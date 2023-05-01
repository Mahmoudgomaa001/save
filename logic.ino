unsigned long  timer = 0;
unsigned long  timer2 = 0;
#define timer_time_out  5000
#define timer_time_out2  30000


bool flag1 = false;
bool flag2 = false;
bool flag3 = false;


#define emcbtn   0
#define forkbtn  1
#define lockbtn  2
#define relay    12 //d6
////
void handler() {

  if (getBtn(emcbtn)) {
    // digitalWrite(relay, HIGH);
    if (!flag1)
    {
      Serial.println("first !");
      flag1 = true;
    }

    if (getBtn(forkbtn)) {
      if (!flag2)
      {
        Serial.println("sec !");
        flag2 = true;
        timer = millis();
        Serial.println("start timer !");
        timer2 = millis();
      }


    }
    else {
      timer = 0;
      timer2 = 0;
      Serial.println("reset timer !");
      flag2 = false;
      flag3 = false;
    }

    if (timer &&  millis() < timer + timer_time_out) {
      if (getBtn(lockbtn)) {
        if (!flag3)
        {
          Serial.println("third");
          flag3 = true;
          Serial.println("not any more !!! ");
          digitalWrite(relay, HIGH);
        }


      }
    }
    else if (timer &&  millis() > timer + timer_time_out) {
      if (getBtn(lockbtn)) {
        if (!flag3)
        {
          Serial.println("third");
          flag3 = true;
          Serial.println("al7a msa !!! ");
          digitalWrite(relay, LOW);
        }


      }
    }

    if (timer2 &&  millis() > timer2 + timer_time_out2) {
      digitalWrite(relay, HIGH);
    }

  }
  else {
    digitalWrite(relay, HIGH);
    flag1 = false;
  }

}
