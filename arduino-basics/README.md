# Let's code

To see if everything is working you can click the ![Green Play](greenpb.png) button and watch it do **ｎｏｔｈｉｎｇ**!.
Then you can stop the simulation before your computer does a "spectacular firework show".

## Code Explained

```cpp
void setup() {
  ...
}

void loop() {
  ...
}

```

You might have noticed that there are two void functions, they are void because they only take inputs, think of it as a... void. The two functions are named `setup` and `loop`, the difference between them is that the `setup` function **only runs once**, while the `loop` function runs all the time, **looping**...

---

```cpp
Serial.begin(115200);
```

This line of code initializes the serial comunication so that you can interact using text with it. The number 115200 is basically the speed of comunication and it's in *"bits per second"*/*bps*, so 115k bits are being sent per second, but only when a message is sent.

---

```cpp
Serial.println("Hello, Arduino!");
```

This line of code sends the text `Hello, Arduino!` along with a newline and carriage return (`\n`, `\r`) characters to the serial port. These characters go way back to the starting  days of computing, where the newline character would send the printer head to the next line and the carriage return would return the head to the start of said line.

---

```cpp
delay(10);
```

This line of code makes the Arduino **die** for 10 miliseconds. I said die because while on delay, the Arduino **does not do anything**. This is important if you want to make some kind of multitasking, because with the arduino firmware, you only have one thread to execute code. (unless you know how to change that)

## The first steps

In this first project we will:

- Learn how to use the digital ports
- Learn how to use the analog ports
- Learn how to use libraries

### Digital ports

For this step we will need:

- 1x `Half Breadboard`
- 1x `LED`
- 1x `Pushbutton`

Make the circuit below:

![Circuit](digitalasm.png)