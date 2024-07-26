//SH_CP
int clk = PB0;
//DS
int data = PB1;
//ST_CP
int latch = PB2;

void setup() {
  pinMode(latch, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(data, OUTPUT);
}

void loop() {
  for (unsigned int i = 0; i < 65536; i++) {
    digitalWrite(latch, LOW);
    shiftOut(data, clk, MSBFIRST, (i >> 8));
    shiftOut(data, clk, MSBFIRST, i);
    digitalWrite(latch, HIGH);
    delay(10);
  }
}