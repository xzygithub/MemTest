package com.example.memtest;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("memtest");
    }

    EditText mMallocSize;
    EditText mMallocTimes;
    Button MallocFree;
    Button FinallyFree;

    public native void testMalloc(int times, int size);

    public native void testFree();

    public native void testFreeFinally();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mMallocSize = findViewById(R.id.editText);
        mMallocTimes = findViewById(R.id.editText2);
        MallocFree = findViewById(R.id.button);
        FinallyFree = findViewById(R.id.button2);
        MallocFree.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (MallocFree.getText().toString().startsWith("M")) {
                    MallocFree.setText("Free");
                    testMalloc(Integer.parseInt(mMallocTimes.getText().toString()),
                            Integer.parseInt(mMallocSize.getText().toString()));
                }else{
                    MallocFree.setText("Malloc");
                    testFree();
                }
            }
        });
        FinallyFree.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                testFreeFinally();
            }
        });
    }
}