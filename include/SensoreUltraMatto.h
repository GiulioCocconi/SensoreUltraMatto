#ifndef SensoreUltraMatto_h
#define SensoreUltraMatto_h

#include "Arduino.h"
class SensoreUltraMatto {
  public:
    SensoreUltraMatto(int trigger, int echo);
    SensoreUltraMatto(int trigger, int echo[], int n);
    double dist();
    double dist(int n);
    String getData();
  private:
    int trigger;
    int *echo;
    int n;
    void init(int trigger, int echo[], int n);
};
#endif
