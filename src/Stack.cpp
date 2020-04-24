#include <Arduino.h>
#include "Stack.h"
#include "funcs.h"

#define SIZE 4
#define PINOFFSET 8

Stack::Stack() {
    arr = new int8_t[SIZE];
    cap = SIZE;
    top = -1;

    for(int i=8;i<12;i++) {
        pinMode(i,OUTPUT);
        digitalWrite(i,0);
    }


    Serial.println("Successfully created stack of capacity " + cap);
}

Stack::~Stack() {
    delete[] arr;
}

uint8_t Stack::isEmpty() {
    if(top < 0) {
        return 1;
    }
    return 0;
}

uint8_t Stack::isFull() {
    if(top >= (cap-1)) {
        return 1;
    }
    return 0;
}

void Stack::push(int8_t num) {
    if(isFull()) {
        Serial.println("Stack Overflow!");
        return;
    }
    delay(10);
    arr[++top] = num;
    digitalWrite(top+PINOFFSET,1);
    return;
}

int8_t Stack::pop() {
    if(isEmpty()) {
        Serial.println("Stack Underflow!");
        return 0;
    }
    delay(10);
    digitalWrite(top+PINOFFSET, 0);
    return arr[top--];
}

int8_t Stack::getTop() {
    if(isEmpty()) {
        Serial.println("Empty Array!");
        return 0;
    }
    return arr[top];
}

uint8_t Stack::getCapacity() {
    return cap;
}

uint8_t Stack::getSize() {
    return (top+1);
}