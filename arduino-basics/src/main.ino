int sliderValue = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, Arduino");
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  sliderValue = analogRead(5); //do not confuse analog pin 5 with digital 5
  //(1024/4)-1 = 255
  if (sliderValue == 0) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    Serial.println("0");
  }else if (sliderValue <= 255){
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    Serial.println("1");
  } else if (sliderValue <= 255+255) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    Serial.println("2");
  } else if (sliderValue <= 255+255+255) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    Serial.println("3");
  } else if (sliderValue >= 255+255+255+255) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    Serial.println("4");
  }
}
