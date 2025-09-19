

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID         "YOUR_WIFI_SSID"
#define WIFI_PASS         "YOUR_WIFI_PASSWORD"
#define APP_KEY           "YOUR_APP_KEY"
#define APP_SECRET        "YOUR_APP_SECRET"

#define FAN_ID            "YOUR_FAN_DEVICE_ID"
#define LED_ID            "YOUR_LED_DEVICE_ID"
#define MOTOR_ID          "YOUR_MOTOR_DEVICE_ID"

#define FAN_PIN           D1
#define LED_PIN           D2
#define MOTOR_PIN         D3

#define FAN_BUTTON        D5
#define LED_BUTTON        D6
#define MOTOR_BUTTON      D7

bool fanState = false;
bool ledState = false;
bool motorState = false;

// Create device references
SinricProSwitch& myFan   = SinricPro[FAN_ID];
SinricProSwitch& myLed   = SinricPro[LED_ID];
SinricProSwitch& myMotor = SinricPro[MOTOR_ID];

// Function to set GPIO state
void setDeviceState(int pin, bool state) {
  digitalWrite(pin, state ? HIGH : LOW);
}

// Fan callback
bool onFanPowerState(const String &deviceId, bool &state) {
  Serial.printf("Fan turned %s via SinricPro\n", state ? "ON" : "OFF");
  fanState = state;
  setDeviceState(FAN_PIN, fanState);
  return true;
}

// LED callback
bool onLedPowerState(const String &deviceId, bool &state) {
  Serial.printf("LED turned %s via SinricPro\n", state ? "ON" : "OFF");
  ledState = state;
  setDeviceState(LED_PIN, ledState);
  return true;
}

// Motor callback
bool onMotorPowerState(const String &deviceId, bool &state) {
  Serial.printf("Motor turned %s via SinricPro\n", state ? "ON" : "OFF");
  motorState = state;
  setDeviceState(MOTOR_PIN, motorState);
  return true;
}

void setup() {
  Serial.begin(115200);

  pinMode(FAN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  pinMode(FAN_BUTTON, INPUT_PULLUP);
  pinMode(LED_BUTTON, INPUT_PULLUP);
  pinMode(MOTOR_BUTTON, INPUT_PULLUP);

  // WiFi connection
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.printf("Connecting to %s", WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected!");

  // Setup SinricPro devices
  myFan.onPowerState(onFanPowerState);
  myLed.onPowerState(onLedPowerState);
  myMotor.onPowerState(onMotorPowerState);

  SinricPro.begin(APP_KEY, APP_SECRET);
}

void loop() {
  SinricPro.handle();

  // Manual Fan Button
  if (digitalRead(FAN_BUTTON) == LOW) {
    delay(200);
    fanState = !fanState;
    setDeviceState(FAN_PIN, fanState);
    myFan.sendPowerStateEvent(fanState);
    Serial.printf("Fan manually %s\n", fanState ? "ON" : "OFF");
  }

  // Manual LED Button
  if (digitalRead(LED_BUTTON) == LOW) {
    delay(200);
    ledState = !ledState;
    setDeviceState(LED_PIN, ledState);
    myLed.sendPowerStateEvent(ledState);
    Serial.printf("LED manually %s\n", ledState ? "ON" : "OFF");
  }

  // Manual Motor Button
  if (digitalRead(MOTOR_BUTTON) == LOW) {
    delay(200);
    motorState = !motorState;
    setDeviceState(MOTOR_PIN, motorState);
    myMotor.sendPowerStateEvent(motorState);
    Serial.printf("Motor manually %s\n", motorState ? "ON" : "OFF");
  }
}

