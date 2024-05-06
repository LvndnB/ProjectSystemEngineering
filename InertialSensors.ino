#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4IMU imu;


void setup() {
  Wire.begin(); // Nodig voor het gebruik van de library functions
  imu.init();
  
}

void loop() {
  imu.read();

  Serial.print("Vector accelerometer: ");
  Serial.print(imu.a.x);
  Serial.print(", ");
  Serial.print(imu.a.y);
  Serial.print(", ");
  Serial.println(imu.a.z);

  Serial.print("Vector gyro: ");
  Serial.print(imu.m.x);
  Serial.print(", ");
  Serial.print(imu.m.y);
  Serial.print(", ");
  Serial.println(imu.m.z);

  Serial.print("Vector magnetometer: ");
  Serial.print(imu.g.x);
  Serial.print(", ");
  Serial.print(imu.g.y);
  Serial.print(", ");
  Serial.println(imu.g.z);

  delay(1000);

}
