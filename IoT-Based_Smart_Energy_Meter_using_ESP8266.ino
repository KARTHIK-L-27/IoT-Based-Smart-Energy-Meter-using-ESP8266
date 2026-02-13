#include <ESP8266WiFi.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

int currentSensor = A0;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Connected");
}

void loop() {
  int sensorValue = analogRead(currentSensor);
  
  float voltage = sensorValue * (3.3 / 1023.0);
  float current = (voltage - 2.5) / 0.066;  // ACS712 approx
  
  float power = 230 * current;  // Assuming 230V AC

  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A | Power: ");
  Serial.print(power);
  Serial.println(" W");

  delay(2000);
}

