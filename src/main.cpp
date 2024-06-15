#include <Arduino.h>
#include <NanitLib.h>
#include "SmartButton.cpp"

#define BTN P4_1
#define RED P4_2
#define GRN P4_3
#define BLU P4_4

SmartButton buttonOnOff = SmartButton(760, 780, BTN);
SmartButton buttonRed = SmartButton(520, 550, BTN);
SmartButton buttonGreen = SmartButton(270, 280, BTN);
SmartButton buttonBlue = SmartButton(10, 30, BTN);

bool ledOn = false;
int red_val = 0, grn_val = 0, blu_val = 0;

void alterColor (int &val) {
    int newVal = int(val * 1.2);
    if (newVal > 255) {
      newVal = 50;
    }
    val = newVal;
}

void setup() {
  Nanit_Base_Start();
  pinMode(BTN, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(BLU, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Serial.println(analogRead(BTN));
  if (buttonOnOff.isPressed()) {
    Serial.println("ON/OFF pressed");
    ledOn = !ledOn;
    red_val = grn_val = blu_val = ledOn ? 50 : 0;
    Serial.println(String(red_val) + "+" + String(grn_val) + "+" + String(blu_val));
  }
  if (buttonRed.isPressed()) {
    Serial.println("Red pressed");
    alterColor(red_val);
    Serial.println(String(red_val) + "+" + String(grn_val) + "+" + String(blu_val));
  }
  if (buttonGreen.isPressed()) {
    Serial.println("Green pressed");
    alterColor(grn_val);
    Serial.println(String(red_val) + "+" + String(grn_val) + "+" + String(blu_val));
  }
  if (buttonBlue.isPressed()) {
    Serial.println("Blue pressed");
    alterColor(blu_val);
    Serial.println(String(red_val) + "+" + String(grn_val) + "+" + String(blu_val));
  }
  // Serial.println(String(red_val) + "+" + String(grn_val) + "+" + String(blu_val));

  analogWrite(RED, red_val);
  analogWrite(GRN, grn_val);
  analogWrite(BLU, blu_val);
}