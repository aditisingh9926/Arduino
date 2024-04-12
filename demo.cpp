#include <Wire.h>
#include <DS3231.h>

#define BUZZER_PIN 9  // Pin where the buzzer is connected

DS3231 rtc;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize RTC module
  rtc.begin();

  // Set the time if it's not already set in the RTC module
  rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(12, 0, 0);  // Set the time to 12:00:00 (24hr format)
  rtc.setDate(1, 1, 2024);   // Set the date to January 1st, 2024

  // Set the alarm time (hour, minute, second, day)
  rtc.setAlarm1(0, 0, 0, 1); // Set alarm to trigger every Monday at 12:00:00
  
  // Enable the alarm
  rtc.enableAlarm1();

  // Attach the buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Check if the alarm is triggered
  if (rtc.isAlarm1()) {
    Serial.println("Alarm triggered!");
    // Activate the buzzer for 10 seconds
    activateBuzzer();
    delay(10000); // Wait for 10 seconds
    // Reset the alarm flag
    rtc.clearAlarm1();
  }
}

void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH); // Turn the buzzer on
}