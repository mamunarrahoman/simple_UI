#include <Adafruit_GFX.h>   // Core graphics library
#include <MCUFRIEND_kbv.h>  // Hardware-specific library
MCUFRIEND_kbv tft;
Adafruit_GFX_Button on_btn, off_btn;

// // #include <Fonts/FreeSans9pt7b.h>
// // #include <Fonts/FreeSans12pt7b.h>
// #include <Fonts/FreeSerif12pt7b.h>

// // #include <FreeDefaultFonts.h>

#include <Keypad.h>

const byte ROWS = 4;  // Four rows
const byte COLS = 4;  // Four columns

// Define the keymap
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// Connect row and column pins to these Arduino pins
byte rowPins[ROWS] = { A8, A9, A10, A11 };    // Rows 0 through 3
byte colPins[COLS] = { A12, A13, A14, A15 };  // Columns 0 through 3

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

byte k1 = 0;
byte k2 = 0;
byte k3 = 0;

void setup() {
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(0);
  tft.fillScreen(BLACK);
  tft.setCursor(60, 130);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.println("FREEDOM");
  delay(500);
  tft.setCursor(75, 160);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("break the binary");
  delay(500);
  tft.setCursor(65, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("Designed by -MAMUNAR RAHOMAN");
  delay(2000);
  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  for (long i = 1000000000; i <= 1000000320; i++) {
    tft.print("1001000110");
    tft.println(i, BIN);
  }
  tft.fillScreen(BLACK);

  tft.setCursor(40, 10);
  tft.setTextSize(2);
  tft.println("USER INTERFACE");
  on_btn.initButton(&tft, 90, 70, 150, 30, WHITE, WHITE, BLACK, "NETWORK", 1);
  on_btn.drawButton(false);
  on_btn.initButton(&tft, 210, 70, 30, 30, WHITE, WHITE, BLACK, "A", 1);
  on_btn.drawButton(true);

  on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "SENSORS", 1);
  on_btn.drawButton(false);
  on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "B", 1);
  on_btn.drawButton(true);

  on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "HMI", 1);
  on_btn.drawButton(false);
  on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "C", 1);
  on_btn.drawButton(true);

  on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "SOFTWARE", 1);
  on_btn.drawButton(false);
  on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "D", 1);
  on_btn.drawButton(true);

  on_btn.initButton(&tft, 90, 270, 150, 30, WHITE, WHITE, BLACK, "CONTROLS", 1);
  on_btn.drawButton(false);
  on_btn.initButton(&tft, 210, 270, 30, 30, WHITE, WHITE, BLACK, "0", 1);
  on_btn.drawButton(true);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    if (key == 'A') {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 10);
      tft.setTextSize(2);
      tft.println("NETWORK");

      on_btn.initButton(&tft, 90, 70, 150, 30, WHITE, WHITE, BLACK, "CALL", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 70, 30, 30, WHITE, WHITE, BLACK, "5", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "MESSAGE", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "6", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "REFRESH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "A", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);
    }
    if (key == 'B') {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 10);
      tft.setTextSize(2);
      tft.println("SENSORS");

      on_btn.initButton(&tft, 90, 70, 150, 30, WHITE, WHITE, BLACK, "U.SONIC", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 70, 30, 30, WHITE, WHITE, BLACK, "5", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "IR", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "6", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "REFRESH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "B", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);

      tft.setCursor(10, 280);
      tft.print("U.SONIC- UltraSonic");
    }
    if (key == 'C') {
      k1 = 1;

      tft.fillScreen(BLACK);
      tft.setCursor(100, 10);
      tft.setTextSize(2);
      tft.println("HMI");

      on_btn.initButton(&tft, 90, 70, 150, 30, WHITE, WHITE, BLACK, "FLASH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 70, 30, 30, WHITE, WHITE, BLACK, "5", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "RFID", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "6", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "LED", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "7", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "REFRESH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "C", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 270, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 270, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);
    }
    if (k1 == 1 && key == '5' || key == '9') {
      k3 = 1;
      tft.fillScreen(BLACK);
      tft.setCursor(90, 10);
      tft.println("FLASH LIGHT");

      tft.fillCircle(120, 60, 15, WHITE);
      tft.fillCircle(120, 60, 15, WHITE);

      on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "ON", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "3", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 160, 150, 30, WHITE, WHITE, BLACK, "OFF", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 160, 30, 30, WHITE, WHITE, BLACK, "4", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 200, 150, 30, WHITE, WHITE, BLACK, "REFRESH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 200, 30, 30, WHITE, WHITE, BLACK, "5", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 240, 150, 30, WHITE, WHITE, BLACK, "BACK", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 240, 30, 30, WHITE, WHITE, BLACK, "*", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 280, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 280, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);
    }
    if (k1 == 1 && k3 == 1 && key == '*') {
      tft.fillScreen(BLACK);
      tft.setCursor(100, 10);
      tft.setTextSize(2);
      tft.println("HMI");

      on_btn.initButton(&tft, 90, 70, 150, 30, WHITE, WHITE, BLACK, "FLASH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 70, 30, 30, WHITE, WHITE, BLACK, "5", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "RFID", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "6", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "LED", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "7", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "REFRESH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "C", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 270, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 270, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);
    }
    if (k1 == 1 && key == '7') {
      k2 = 1;
      tft.fillScreen(BLACK);
      tft.setCursor(60, 10);
      tft.println("BLINK LED FOR 10 TIMES");

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "REFRESH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "7", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "BACK", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "*", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 270, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 270, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);

      for (int i = 1; i <= 10; i++) {
        tft.fillCircle(120, 80, 15, RED);
        delay(500);
        tft.fillCircle(120, 80, 15, BLACK);
        delay(500);
      }
    }
    if (k1 == 1 && k2 == 1 && key == '*') {
      tft.fillScreen(BLACK);
      tft.setCursor(100, 10);
      tft.setTextSize(2);
      tft.println("HMI");

      on_btn.initButton(&tft, 90, 70, 150, 30, WHITE, WHITE, BLACK, "FLASH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 70, 30, 30, WHITE, WHITE, BLACK, "5", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "RFID", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "6", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "LED", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "7", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "REFRESH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "C", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 270, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 270, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);
    }
    if (key == 'D') {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 10);
      tft.setTextSize(2);
      tft.println("SOFTWARE");

      on_btn.initButton(&tft, 90, 70, 150, 30, WHITE, WHITE, BLACK, "NC", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 70, 30, 30, WHITE, WHITE, BLACK, "5", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "CLOCK", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "6", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "REFRESH", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "D", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);

      tft.setCursor(10, 280);
      tft.print("NC- Normal Calculator");
    }
    if (key == '0') {
      tft.fillScreen(BLACK);
      tft.setCursor(0, 70);
      // tft.setTextSize(2);
      tft.println("Left Side Column is for Function icon.");
      tft.println();
      tft.println("Right side column is for access the");
      tft.println("corresponding Function.");

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "HOME", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "#", 1);
      on_btn.drawButton(true);
    }
    if (key == '#') {
      tft.fillScreen(BLACK);

      tft.setCursor(40, 10);
      tft.setTextSize(2);
      tft.println("USER INTERFACE");
      on_btn.initButton(&tft, 90, 70, 150, 30, WHITE, WHITE, BLACK, "NETWORK", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 70, 30, 30, WHITE, WHITE, BLACK, "A", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 120, 150, 30, WHITE, WHITE, BLACK, "SENSORS", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 120, 30, 30, WHITE, WHITE, BLACK, "B", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 170, 150, 30, WHITE, WHITE, BLACK, "HMI", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 170, 30, 30, WHITE, WHITE, BLACK, "C", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 220, 150, 30, WHITE, WHITE, BLACK, "DRIVERS", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 220, 30, 30, WHITE, WHITE, BLACK, "D", 1);
      on_btn.drawButton(true);

      on_btn.initButton(&tft, 90, 270, 150, 30, WHITE, WHITE, BLACK, "CONTROLS", 1);
      on_btn.drawButton(false);
      on_btn.initButton(&tft, 210, 270, 30, 30, WHITE, WHITE, BLACK, "0", 1);
      on_btn.drawButton(true);
    }
  }
}
