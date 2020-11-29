#include <Stepper.h>
int PhotoR = A0;
int nombredepas = 48*64;
bool porte_en_haut = true;
bool porte_en_bas = false;

Stepper monMoteur(nombredepas,9,11,10,6);

int PhotoRLue;

void setup() {
  Serial.begin(9600);
  monMoteur.setSpeed(9);
  pinMode(PhotoR, INPUT);
}

void loop() {
  PhotoRLue = analogRead(PhotoR);
  Serial.print("PhotoRLue = ");
  Serial.print(PhotoRLue);
    //on saute une ligne entre deux affichages
  Serial.println();
  
  if (PhotoRLue < 520 && porte_en_haut) {
    monMoteur.step(1000);
    delay(1000);
    porte_en_haut = false;
    porte_en_bas = true;
  }

  if (PhotoRLue > 520 && porte_en_bas) { 
    monMoteur.step(-1000);
    delay(1000);
    porte_en_haut = true;
    porte_en_bas = false; 
  }
}
