# alarmclock
Custom Alarm Clock Project
Case Design:
Done at various times throughout June 27 for a total of almost 7 hours, explained fully in Blare Alarm Clock PDF Document.
Currently, for the firmware, I will keep it simple and focus on first having a functioning smart alarm clock. Later, I will move on-to adding more functionalities such as syncing a Spotify API as a standby display.
Arduino Firmware:
Hour 1:
- Designed a 4x3 button matrix layout
- Mapped the components including the LCD panel, Buzzer, and Keyboard to the ESP GPIO Pins
- Drafted a wiring map in Tinkercad to avoid issues when soldering
Final: Checked and made sure all the pins for the matrix, display panel, and audio output (buzzer) are accounted for
Hour 2:
- Configured the Arduino IDE for the ESP Board
- Installed the libraries requested in the tutorial, including AdafruitGFX and ST7789
Hour 4:
- Implemented Wifi connectivity and time fetching so the board can tell what time it is using the local connectivity.
- The device clock will be synced with a global NTP server
- Logic to display time on screen
Final: Functional clock that will update via wi-fi
Hour 6:
- Implemented a checkAlarm() function which compares to see if the time equals the target alarm time, and whether it needs to buzz
- Keypad.h library integrated to enable button inputs
- Buzzer control logic which is triggered by the # key, allowing the user to turn on/off buzzer volume
