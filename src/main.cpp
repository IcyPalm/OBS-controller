#include "main.h"

#define NUM_BUTTONS 9
const uint8_t BUTTON_PINS[NUM_BUTTONS] = {2, 3, 4, 5, 6, 7, 8, 9, 18};
Bounce * buttons = new Bounce[NUM_BUTTONS];

void setup() {
  Keyboard.begin();
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].attach( BUTTON_PINS[i] , INPUT_PULLUP  );//setup the bounce instance for the current button
    buttons[i].interval(25);   // interval in ms
  }
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++)  {
    buttons[i].update();
    if ( buttons[i].fell()) {
      if(i<8){
        buttonPressed(i);
      }
      if(i==8){
        Keyboard.press(KEY_F19);
      }
    }
    if(buttons[i].rose() & (i==8)){
      Keyboard.release(KEY_F19);
    }
  }
}

void buttonPressed(int button){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  switch (button)
  {
  case 7:
    Keyboard.press(KEY_F23);
    break;
  case 0:
    Keyboard.press(KEY_F24);
    break;
  case 6:
    Keyboard.press(KEY_F13);
    break;
  case 5:
    Keyboard.press(KEY_F14);
    break;
  case 4:
    Keyboard.press(KEY_F15);
    break;
  case 3:
    Keyboard.press(KEY_F16);
    break;
  case 2:
    Keyboard.press(KEY_F17);
    break;
  case 1:
    Keyboard.press(KEY_F18);
    break;
  default:
    break;
  }
  delay(200);
  Keyboard.release(KEY_LEFT_CTRL);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.release(KEY_LEFT_SHIFT);
  Keyboard.release(KEY_F23);
  Keyboard.release(KEY_F24);
  Keyboard.release(KEY_F13);
  Keyboard.release(KEY_F14);
  Keyboard.release(KEY_F15);
  Keyboard.release(KEY_F16);
  Keyboard.release(KEY_F17);
  Keyboard.release(KEY_F18);
}