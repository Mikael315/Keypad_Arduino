#include <Keypad.h>

const byte numRows = 4;
const byte numCols = 4;

char keymap [numRows][numCols] =
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'},
};

byte rowPins[numRows] = {9,8,7,6};
byte colPins[numCols] = {5,4,3,2};

Keypad myKeypad = Keypad (makeKeymap (keymap), rowPins, colPins, numRows, numCols);

void setup ()
{
	Serial.begin(9600);
}

void loop()
{
char keypressed = myKeypad.getKey();
if (keypressed !=NO_KEY) 
{
Serial.println(keypressed);
}
}

//////////////////////

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define LCD_ADDRESS 0x27
#define LCD_ROWS 2
#define LCD_COLS 16

char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[4] = {9,8,7,6};
byte colPins[4] =  {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_ROWS, LCD_COLS);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  char multiKey[5] = {0};
  int i = 0;
  while (i < 9) {
    char key = keypad.getKey();
    if (key != NO_KEY ) {
      multiKey[i] = key;
      i++;
      lcd.setCursor(i-1, 0);
      lcd.print(key);
    }
    delay(50);
  }
 
}
////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

char keys[4][4] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};

byte rowPins[4] = {9,8,7,6};
byte colPins[4] =  {5,4,3,2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

LiquidCrystal_I2C lcd(0x27, 2, 16);

float num_1 = 0;
float num_2 = 0;
char op;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    if (key == 'C') {
      num_1
     = 0;
      num_2 = 0;
      op = 0;
      lcd.clear();
    } else if (key == '+' || key == '-' || key == '*' || key == '/') {
      op = key;
      lcd.setCursor(0, 1);
      lcd.print(op);
    } else if (key == '=') {
      float result;
      if (op == '+') {
        result = nu1 + num_2;
      } else if (op == '-') {
        result = num_1
       - num_2;
      } else if (op == '*') {
        result = num_1
       * num_2;
      } else if (op == '/') {
        result = num_1;
        
       / num_2;
      }
      lcd.setCursor(0, 1);
      lcd.print("= ");
      lcd.print(result);
      num_1
     = result;
      num_2 = 0;
      op = 0;
    } else {
      float num = key - '0';
      if (op == 0) {
        num_1
       = num_1
       * 10 + num;
        lcd.setCursor(0, 0);
        lcd.print(num_1
      );
      } else {
        num_2 = num_2 * 10 + num;
        lcd.setCursor(0, 1);
        lcd.print(num_2);
      }
    }
  }
}
