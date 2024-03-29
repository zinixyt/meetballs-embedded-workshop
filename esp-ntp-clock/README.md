# Making the Clock

## Importing Libraries

Once you have your project ready, go ahead to the `Library Manager` and add the `LiquidCrystal I2C` Library.

## Adding a screen

After installing the library, over on the `Simulation` side, add a `LCD 16x2 (I2C)` component.
Connect the pins up to the ESP32 in this way. We'll use the I2C protocol. It's basically a way of transfering data using two wires, one for Inbound, and one for Outbound.

| LCD | ESP |
| --- | --- |
| VCC | 3V3 |
| GND | GND |
| SDA |  21 |
| SCL |  22 |

Your circuit should look like this:

![It should look like this](assembly.png)

## Part 1

Copy this code block below to your project. This code contains the basic setup for the clock.

```cpp
//Libraries
#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2); //Define LCD object

#define NTP_SERVER     "pool.ntp.org"//
#define UTC_OFFSET     0             // Set some constants
#define UTC_OFFSET_DST 0             //

void spinner() { //do a fancy animation
  static int8_t counter = 0;
  const char* glyphs = "\xa1\xa5\xdb";
  LCD.setCursor(15, 1);
  LCD.print(glyphs[counter++]);
  if (counter == strlen(glyphs)) {
    counter = 0;
  }
}
```

This code contains the library imports, defines the LCD object, sets some constants and creates a `spinner` function that adds some dots while connecting.
The LCD works like this:

![LCD inner workings](lcd.webp)

So when you set the cursor to [15,1] you are setting it to the 15th column, to the 2nd row.

## Part 2

We are going to use the `getLocalTime()` function built-in to the `WiFi` library to get the time from the NTP server

```cpp
void printLocalTime() {
  struct tm timeinfo; //create the struct variable for the time
  if (!getLocalTime(&timeinfo)) { // if can't get time throw error
    LCD.setCursor(0, 1);
    LCD.println("Connection Err");
    return; //exit function
  }

  LCD.setCursor(8, 0); // set cursor to position
  LCD.println(&timeinfo, "%H:%M:%S"); // write the time with a pre-defined format

  LCD.setCursor(0, 1); // again
  LCD.println(&timeinfo, "%d/%m/%Y   %Z"); // write the date with a pre-defined format
}
```

## Part 3

By the end of this part, we should have this code written:

```cpp
void setup() {
  Serial.begin(115200); //set data speed

  LCD.init(); // initialize the lcd
  LCD.backlight(); // turn on its backlight
  LCD.setCursor(0, 0);
  LCD.print("Connecting to ");
  LCD.setCursor(0, 1);
  LCD.print("WiFi ");

  WiFi.begin("Wokwi-GUEST", "", 6); //connect to the virtual wifi on channel 6 with no password
  while (WiFi.status() != WL_CONNECTED) { // while not connected
    delay(250);
    spinner();      // do the fancy animation
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // print IP address

  LCD.clear(); //clear the lcd
  LCD.setCursor(0, 0);
  LCD.println("Online");
  LCD.setCursor(0, 1);
  LCD.println("Updating time...");

  configTime(UTC_OFFSET, UTC_OFFSET_DST, NTP_SERVER); // set the time settings of the ESP32
}

void loop() {
  printLocalTime(); // do the actual thing
  delay(250); // wait 250ms, so it refreshes 4 times per second: 1s/4=0.25s -> 250ms
}
```
