#include <SoftwareSerial.h>

#define LED_PIN 13  // Replace with the actual pin connected to your LED
SoftwareSerial bluetooth(10, 11); // RX, TX pins for HC-05 module

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();

    if (command == '1') {
      digitalWrite(LED_PIN, HIGH); // Turn on the LED
      bluetooth.write("LED ON\n");
    } else if (command == '0') {
      digitalWrite(LED_PIN, LOW);  // Turn off the LED
      bluetooth.write("LED OFF\n");
    }
  }
}
