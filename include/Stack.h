#ifndef STACK_H
#define STACK_H

#include <Arduino.h>
#include "funcs.h"

class Stack {
    int8_t *arr;
    int8_t top;
    uint8_t cap;

    public:
        Stack();
        ~Stack();
        uint8_t isEmpty();
        uint8_t isFull();
        void push(int8_t num);
        int8_t pop();
        int8_t getTop();
        uint8_t getCapacity();
        uint8_t getSize();
};

#endif