unsigned long  timer = 0;
#define timer_time_out  5000

#define emcbtn   0
#define forkbtn  1
#define lockbtn  2
#define relay    12 //d6
////
void handler() {

  if (getBtn(emcbtn)) {
    // digitalWrite(relay, HIGH);
    Serial.println(emcbtn);
    if (getBtn(forkbtn)) {
      timer = millis();
      Serial.println(emcbtn);
    }
    if (timer &&  millis() < timer + timer_time_out) {
      if (getBtn(lockbtn)) {
        Serial.println(lockbtn);
        digitalWrite(relay, HIGH);
      }
    }
  }
  else {
    timer = 0;
  }

}
