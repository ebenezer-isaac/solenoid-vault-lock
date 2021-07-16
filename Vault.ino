/* @file HelloKeypad.pde
  || @version 1.0
  || @author Alexander Brevig
  || @contact alexanderbrevig@gmail.com
  ||
  || @description
  || | Demonstrates the simplest use of the matrix Keypad library.
  || #
*/
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {12, 13, 6, 10}; //connect to the row pinouts of the kp,
byte colPins[COLS] = {2, 4, 8, 11}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int letter = -1;
void setup() {
  Serial.begin(9600);
  pinMode(16, OUTPUT);

}
void loop() {
  while (letter == -1) {
    letter = Serial.read();
  }
  if (letter != 10) {
    Serial.println(letter, DEC);
    if (letter == 49) {
      analogWrite(16, 255);
    } else {
      analogWrite(16, 0);
    }
  }
  letter = -1;
}
