#include "pH_Sensor.h"

pH_Sensor::pH_Sensor(float calibrationValue) {
  _calibrationValue = calibrationValue;
}

void pH_Sensor::begin() {
  Serial.begin(115200);
}

float pH_Sensor::getpH() {
  int buffer_arr[10], temp;
  unsigned long int avgval;
  
  for (int i = 0; i < 10; i++) {
    buffer_arr[i] = analogRead(A2); // Read from analog pin A2
    delay(30);
  }
  
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buffer_arr[i] > buffer_arr[j]) {
        temp = buffer_arr[i];
        buffer_arr[i] = buffer_arr[j];
        buffer_arr[j] = temp;
      }
    }
  }
  
  avgval = 0;
  for (int i = 2; i < 8; i++)
    avgval += buffer_arr[i];
  
  float volt = (float)avgval * 5.0 / 1024 / 6;
  float pH_act = -5.70 * volt + _calibrationValue;
  
  return pH_act;
}
