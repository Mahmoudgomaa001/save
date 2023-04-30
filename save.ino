

void setup() {
  Serial.begin(9600);
  btnSetup();
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  handler();
}
