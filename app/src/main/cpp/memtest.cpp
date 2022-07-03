#include <jni.h>
#include <cstdlib>
#include "android/log.h"

#define LOG_TAG "MemTest"
void** pMem = nullptr;
jint malloc_times = 0;
extern "C"
JNIEXPORT void JNICALL
Java_com_example_memtest_MainActivity_testMalloc(JNIEnv *env, jobject thiz, jint times, jint size) {
    // TODO: implement testMalloc()
    if(times <= 0 || size <= 0){
        __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,"times = %d,size = %d", times, size);
        return;
    }
    malloc_times = times;
    pMem = (void**)malloc(malloc_times*sizeof(void*));
    for(int i = 0; i < malloc_times; i++){
        pMem[i] = (void*)malloc(size);
    }
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_memtest_MainActivity_testFree(JNIEnv *env, jobject thiz) {
    // TODO: implement testFree()
    if(pMem == nullptr){
        __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,"pMem is null");
    }
    for(int i = 0; i < malloc_times; i++){
        free(pMem[i]);
    }
    free(pMem);
    malloc_times = 0;
    pMem = nullptr;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_memtest_MainActivity_testFreeFinally(JNIEnv *env, jobject thiz) {
    // TODO: implement testFreeFinally()
    mallopt(M_PURGE,0);
}