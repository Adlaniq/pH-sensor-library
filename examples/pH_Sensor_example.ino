#include <pH_Sensor.h>

pH_Sensor phSensor(18.4); // Set the calibration value

void setup() {
  phSensor.begin();
  Serial.begin(115200);
}

void loop() {
  float pHValue = phSensor.getpH();
  Serial.print("pH Value: ");
  Serial.println(pHValue);
  delay(1000);
}
