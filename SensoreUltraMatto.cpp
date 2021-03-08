#include "SensoreUltraMatto.h"

void SensoreUltraMatto::init(int trigger, int echo[], int n) {
  this->trigger = trigger;
  this->echo = echo;
  this->n = n;
  pinMode(trigger, OUTPUT);
  for (int i = 0; i<n; i++) {
    pinMode(echo[i], INPUT);
  }
}

SensoreUltraMatto::SensoreUltraMatto(int trigger, int echo) {
  this->init(int trigger, new int[1]{echo}, 1);
}

SensoreUltraMatto::SensoreUltraMatto(int trigger, int echo[], int n) {
  this->init(trigger, echo, n);
}

double SensoreUltraMatto::dist(n) {
  digitalWrite(this->trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(this->trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trigger, LOW);
  unsigned long durata = pulseIn(this->echo[n], HIGH);
  double distanza = durata/58.0;//www.acmesystems.it/HC-SR04
  if (distanza == 0 || distanza > 400) {
    return -1.0;
  }
  return distanza;
}

String SensoreUltraMatto::getData() {
  String result = "";
  for (int i = 0; i<this->n; i++) {
    String distanza = String(this->dist(i), 1);
    result += distanza;
    result += "\t";
  }
  return result + "\n";
}

float SensoreUltraMatto::dist() {
  return this->dist(0);
}
