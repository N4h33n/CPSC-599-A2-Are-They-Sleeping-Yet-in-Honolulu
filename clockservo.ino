#include <Servo.h>
#define LED_PIN 12

Servo sunservo;
Servo moonservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sunservo.attach(5);
  moonservo.attach(3);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val;

  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n');
    // two positions, first for sun servo second for moon servo
    int delimPos = inputString.indexOf(',');
    if (delimPos != -1) {
      String sunstr = inputString.substring(0, delimPos);
      String moonstr = inputString.substring(delimPos + 1);

    float sunPos = sunstr.toFloat();
    float moonPos = moonstr.toFloat();
      if (sunPos >= 0 && sunPos <= 180 && moonPos >= 0 && moonPos <= 180) {
      Serial.println(sunPos);
      Serial.println(moonPos);
      sunservo.write(sunPos); 
      moonservo.write(moonPos); 
    }

      // set LED to be on if it is day time. else, off
    if (sunPos < 180) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
    }
  }
  delay(10);
}
