#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


#define PAUSE 1

const boolean affichage[10][7] = {
  1, 1, 1, 1, 1, 1, 0, //0
  0, 1, 1, 0, 0, 0, 0, //1
  1, 1, 0, 1, 1, 0, 1, //2
  1, 1, 1, 1, 0, 0, 1, //3
  0, 1, 1, 0, 0, 1, 1, //4
  1, 0, 1, 1, 0, 1, 1, //5
  1, 0, 1, 1, 1, 1, 1, //6
  1, 1, 1, 0, 0, 0, 0, //7
  1, 1, 1, 1, 1, 1, 1, //8
  1, 1, 1, 1, 0, 1, 1 //9
};


int heure[4] = {0}; // tableau pour stocker chacun des chiffres qui forment l'heure
int HEURE, MIN;

const int transistorPin[4] = {0, 3, 2, 4};
const int ledPin[7] = {11, 10, 9, 8, 7, 6, 5};

tmElements_t tm;


void setup() {

  if (RTC.read(tm)) {

    HEURE = tm.Hour;
    MIN = tm.Minute;

    // assignation de quatre chiffres en fonction de l'heure
    if ( HEURE >= 0 && HEURE < 10 ) {
      heure[0] = 0;
    }
    else {
      heure[0] = HEURE / 10;
    }
    heure[1] = HEURE % 10;
    
    if ( MIN >= 0 && MIN < 10) {
      heure[2] = 0;
    }
    else {
      heure[2] = MIN / 10;
    }
    heure[3] = MIN % 10;
  }

  int i;

  for ( i = 0 ; i < 7 ; i++ ) { // initialisation de toutes les broches utilisées en sortie
    pinMode ( ledPin[i], OUTPUT );
    digitalWrite( ledPin[i], LOW);
  }

  for ( i = 0 ; i < 4 ; i++ ) { // initialisation de toutes les broches utilisées en sortie
    pinMode ( transistorPin[i], OUTPUT );
    digitalWrite( transistorPin[i], LOW);
  }



}


void loop() {

  static int i, j;

  for ( i = 0 ; i < 4 ; i++ ) {

    for ( j = 0 ; j < 7 ; j++ ) {
      digitalWrite ( ledPin[j], affichage[heure[i]][j] ); // met chaque pin à la bonne valeur pour afficher le chiffre

    }

    digitalWrite ( transistorPin[i], HIGH);
    delay (PAUSE);
    digitalWrite ( transistorPin[i], LOW);

  }

  RTC.read(tm);

  HEURE = tm.Hour;
  MIN = tm.Minute;

  if ( HEURE >= 0 && HEURE < 10 ) {
    heure[0] = 0;
  }
  else {
    heure[0] = HEURE / 10;
  }
  heure[1] = HEURE % 10;
  if ( MIN >= 0 && MIN < 10) {
    heure[2] = 0;
  }
  else {
    heure[2] = MIN / 10;
  }
  heure[3] = MIN % 10;

}
