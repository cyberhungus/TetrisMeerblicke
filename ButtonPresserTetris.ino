#include "Keyboard.h"

// Define the pin numbers that buttons are connected toooooooooooooooooouuuuuuuuiiiiiiiiiiiiiiiiiiiiiiii
const int buttonPins[] = {4,7,8,5,A3,A2,A1,A0,16,14,15}; // Example pins
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

// Corresponding keystrokes for each button
// For example, 'a', 'b', and 'c' will be sent when buttons 1, 2, and 3 are pressed, respectively.qqweeaaaasdzzzzzzzzzzzzyyyy
const char keystrokes[numButtons] = {'w','a','s','d','t','f','g','h','u','i','o'};

// Array to keep track of the last state of each button
bool lastButtonStates[numButtons];

void setup() {
  // Initialize the Keyboard library
  Keyboard.begin();

  // Set each button pin as an input with pullup
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    // Initialize lastButtonStates as HIGH (not pressed)
    lastButtonStates[i] = HIGH;
  }
}

void loop() {
  // Check each button
  for (int i = 0; i < numButtons; i++) {
    int currentButtonState = digitalRead(buttonPins[i]);
    
    // If the button state has changed from HIGH to LOW (button pressed),
    // and the last state was HIGH (button was not pressed before)
    if (currentButtonState == LOW && lastButtonStates[i] == HIGH) {
      // Send the corresponding keystroke
      Keyboard.press(keystrokes[i]);
      Keyboard.releaseAll(); // Release all keys
    }

    // Update the lastButtonState to the current state
    lastButtonStates[i] = currentButtonState;
  }

  // Short delay to debounce
  delay(50);
}
