#ifndef SensoreUltraMatto_h
#define SensoreUltraMatto_h

#include "Arduino.h"
class SensoreUltraMatto {
  public:
    SensoreUltraMatto(int out, int trig);
    SensoreUltraMatto(int out, int trig[], int n);
    float dist();
    float dist(int n);
  private:
    int out;
    int trig[];
    int n;
    void init(int out, int trig[], int n);
};
#endif
