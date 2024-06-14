#include <Wire.h>
#include <Zumo32U4.h>
#include <cmath>

Zumo32U4IMU imu;


void setup() {
  Wire.begin(); // Nodig voor het gebruik van de library functions
  imu.init(); // Initialiseren van de imu sensor
  
}

void loop() {
  imu.read(); // Uilezen van de sensor

  Serial.print("Vector accelerometer: "); // Het seriële printen van de rauwe data van de accelerometer
  Serial.print(imu.a.x);
  Serial.print(", ");
  Serial.print(imu.a.y);
  Serial.print(", ");
  Serial.println(imu.a.z);

  Serial.print("Vector gyro: "); // Het seriële printen van de rauwe data van de gyroscope
  Serial.print(imu.g.x);
  Serial.print(", ");
  Serial.print(imu.g.y);
  Serial.print(", ");
  Serial.println(imu.g.z);

  Serial.print("Vector magnetometer: "); // Het seriële printen van de rauwe data van de magnetometer
  Serial.print(imu.m.x);
  Serial.print(", ");
  Serial.print(imu.m.y);
  Serial.print(", ");
  Serial.println(imu.m.z);
  float ax = imu.a.x; // X-as waarde van de accelerometer
  float ay = imu.a.y; // Y-as waarde van de accelerometer
  float az = imu.a.z; // Z-as waarde van de accelerometer
  float pitch = atan2(ax / ay) * (180 / M_PI); // Bron voor de berekening van de pitch: https://atadiat.com/en/e-towards-understanding-imu-basics-of-accelerometer-and-gyroscope-sensors/
  Serial.println(pitch); // Print de data van de pitch voor het testen
  delay(1000);

}
