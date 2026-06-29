#include <Keypad.h>
#define BUZZER_PIN 2
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {0, 1, 3, 4}; 
byte colPins[COLS] = {5, 6, 7}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <WiFi.h>
#include <time.h>
// storage for pin assignments
#define TFT_CS 8
#define TFT_RST 9
#define TFT_DC 10
#define TFT_SCLK 20
#define TFT_MOSI 21
// wifi constants
const char* ssid = "KAFHome";
const char* password = "9717470303";
//alarm variables
int alarmHour = 7; 
int alarmMinute = 30;
bool alarmTriggered = false;
// time server
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -18000; 
const int daylightOffset_sec = 3600;
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
void setup() {
  Serial.begin(115200);
  tft.init(284, 76);
 tft.setAddrWindow(82, 18, 284, 76);
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);
// connecting to the wifi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() 
{
  //rmb to check for key press!
  char key = keypad.getKey();
if (key)
{
  Serial.println(key);
  if (key == '#') 
  {
    alarmTriggered = false; 
    noTone(BUZZER_PIN);
  }
}
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) 
  {
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(10, 20);
    tft.setTextSize(3);
    tft.setTextColor(ST77XX_WHITE);
    // to correct formatting in hh:mm format (ex: 09:30) -> will not add PM or AM to reduce complications
    char timeString[10];
    strftime(timeString, sizeof(timeString), "%H:%M", &timeinfo);
    tft.print(timeString);
  }
  delay(1000);
}