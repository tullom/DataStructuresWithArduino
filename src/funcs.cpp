#include <Arduino.h>
#include "funcs.h"

uint8_t toggle (uint8_t *num) {
  if (*num) {
    *num = 0;
    return *num;
  } else {
    *num = 1;
    return *num;
  }
}