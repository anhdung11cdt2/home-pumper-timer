int state = LOW;
// LOW is ON, HIGHT is OFF
// + connect to 5V Vout , - connect to pump pin (7) 
unsigned long preDay = 0;
unsigned long preMinute = 0;

const long oneDay = 86400000; // 1 day = 86400,000 s
const long tenMinutes = 600000; // 10p = 600,000s

const int led = LED_BUILTIN;
const int pump = 7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(7, OUTPUT);
//  Serial.begin(9600);
}

void loop() {
  // TURN ON PUMP IN EVERY 24H
  unsigned long curTime = millis();
  if (curTime - preDay >= oneDay) {
    preDay = curTime;
    preMinute = curTime;
    state = LOW;
//    Serial.print(curTime - preDay);
//    Serial.println("   ON");
  }
  // TURN OFF IF PUMP IS ON AND AFTER 10'
  if ((state == LOW) && (curTime - preMinute >= tenMinutes)) {
    state = HIGH;
//    Serial.print(curTime - preMinute);
//    Serial.println("  OFF");
    preMinute = 0;
  }
  digitalWrite(led, !state);
  digitalWrite(pump, state);
}
