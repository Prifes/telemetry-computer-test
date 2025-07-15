#include "bsp/bsp.h"

int main() {
    board::Initialize();

    while (true) {
        board::ToggleLed();  // Toggle the LED state
        board::Delay(500);  // Delay for 1000 milliseconds (1 second)
    }
}