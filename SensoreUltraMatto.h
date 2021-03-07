#ifndef SensoreUltraMatto_h
#define SensoreUltraMatto_h

#include "Arduino.h"
class SensoreUltraMatto {
  public:
    SensoreUltraMatto(int trigger, int echo);
    SensoreUltraMatto(int trigger, int echo[], int n);
    float dist();
    float dist(int n);
    String getData();
  private:
    int out;
    int trig[];
    int n;
    void init(int trigger, int echo[], int n);
};
#endif
