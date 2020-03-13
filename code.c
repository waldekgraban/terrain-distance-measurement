#include <LiquidCrystal.h>

LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

int pin1 = 2;
int pin2 = 3;

int PreviousState;
int CurrentState;
int Pos = 0;

const float radiusOfWheel = 3.25;
const int stepsPerRotation = 40;
const float pi = 3.14;

float distance = 0;

void setup() {
    pinMode (pin1 ,INPUT_PULLUP);
    pinMode (pin2 ,INPUT_PULLUP);

    lcd.begin(16, 2);
    lcd.print("MEASURNING");

    PreviousState = digitalRead(pin1);
}

void loop() {
    CurrentState = digitalRead(pin1);
    if (CurrentState != PreviousState){
        if (digitalRead(pin2) != CurrentState) {
            Pos ++;
        }
        else {
            Pos --;
        }
    }

    distance = ((2*pi*radiusOfWheel)/stepsPerRotation) * Pos;

    lcd.setCursor(0, 1);
    lcd.print(distance);

    lcd.setCursor(5, 1);
    lcd.print("cm");

    PreviousState = CurrentState;
}
