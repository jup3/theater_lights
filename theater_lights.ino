/*
Theater Lights by motion sensor

Turn on theater lights for n seconds after input from motion sensor

WIP
1. write blink function
2. test blink function

*/

//Timer
unsigned long curTime;
unsigned long startTime;
unsigned long endTime;

// Motion Sensor
int const motionInPin = 2;
int motionInPinValue = 0;
int const allLights = 10;

// Marquee
int const marqueeOne = 13;
int const marqueeTwo = 12;
int const marqueeThree = 8;

void setup() {
  pinMode(motionInPin, INPUT);
  pinMode(allLights, OUTPUT);
  pinMode(marqueeOne, OUTPUT);
  pinMode(marqueeTwo, OUTPUT);
  pinMode(marqueeThree, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(allLights, LOW);
  digitalWrite(marqueeOne, LOW);
  digitalWrite(marqueeTwo, LOW);
  digitalWrite(marqueeThree, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {

  // Detect Motion
  motionInPinValue = digitalRead(motionInPin);
  if (motionInPinValue > 0) {
    int counter = 0;
    while (counter < 30) {
      counter++;
      runLights();
    }
  }
  digitalWrite(allLights, LOW);
}

void blink(int ipin) {
  Serial.println(ipin);
  digitalWrite(ipin, HIGH);
  delay(150);
  digitalWrite(ipin, LOW);
}

void runLights() {
    digitalWrite(allLights, HIGH);
    blink(marqueeOne);
    blink(marqueeTwo); 
    blink(marqueeThree);

}