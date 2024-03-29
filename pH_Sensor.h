#ifndef pH_Sensor_h
#define pH_Sensor_h

#include "Arduino.h"

class pH_Sensor {
  public:
    pH_Sensor(float calibrationValue);
    void begin();
    float getpH();
  private:
    float _calibrationValue;
};

#endif
