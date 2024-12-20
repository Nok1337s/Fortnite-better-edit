#include <windows.h>
#include <iostream>

// Utility function to check if a key is pressed
bool isKeyPressed(int virtualKey) {
    return (GetAsyncKeyState(virtualKey) & 0x8000) != 0;
}

// Simulate a key press
void sendKeyDown(WORD virtualKey) {
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = virtualKey;
    SendInput(1, &input, sizeof(INPUT));
}

// Simulate a key release
void sendKeyUp(WORD virtualKey) {
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = virtualKey;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    std::cout << "Press 'F' to simulate 'P'. Release 'F' to stop.\n";

    bool isFPressed = false; // Track the state of the 'F' key

    while (true) {
        if (isKeyPressed('F')) {
            if (!isFPressed) {
                // Simulate 'P' key press when 'F' is first pressed
                sendKeyDown('P');
                isFPressed = true;
            }
        } else {
            if (isFPressed) {
                // Simulate 'P' key release when 'F' is released
                sendKeyUp('P');
                isFPressed = false;
            }
        }

        // Small delay to prevent CPU overuse
        Sleep(10); // Pause for 10 milliseconds
    }

    return 0;
}
