
#define btn_num 3
//12 d6
int btn [btn_num] = {5, 4, 14}; //d1 d2 d5 
bool btn_old_sg [btn_num] = {1, 1, 1};


void btnSetup()
{
  // Bouton poussoir 1
  for (int i = 0; i < btn_num ; i++) {
    pinMode(btn[i], INPUT_PULLUP);
  }

}


bool getBtn(int i) {
  bool sg = digitalRead(btn[i]);
  bool r = btn_old_sg[i] != sg && sg == HIGH;
  btn_old_sg[i] = sg;
  return r;
}
