
#include <Arduino.h>
#include "funcs.h"
#include "Stack.h"


uint8_t pushButton = 3, popButton = 2;
Stack s;


void hi() {
  s.push(2);
}

void hi2() {
  s.pop();
}


void setup() {
  Serial.begin(9600);
  s = Stack();
  pinMode(pushButton,INPUT);
  pinMode(popButton,INPUT);
}


void loop() {

  // Serial.println("Hello World");
  // for(int i=0;i<4;i++) {
  //   digitalWrite(led[i],toggle(ledStatus+i));
  // }
  int pushStatus = digitalRead(pushButton);
  int popStatus = digitalRead(popButton);
  if(pushStatus) {
    s.push(3);
    delay(250);
  }
  if(popStatus) {
    s.pop();
    delay(250);
  }
}

