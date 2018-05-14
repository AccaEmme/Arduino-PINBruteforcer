# Arduino-PINBruteforcer


Calcolo tempo stimato:
(10)^4=10.000 disposizioni con ripetizioni
10.000/5 (batteria minima) = 2000 batterie
Considerando che ogni batteria di tentativi dura 31secondi(1secondo per la batteria + 28 di attesa)
Possiamo dire che 2000 batterie (2000*31) dureranno 62000 secondi ovvero 1033,333333333 minuti ovvero 17,222222222 ore.
Se non ci fosse il blocco dei 28secondi, il pin da 4 cifre verrebbe individuato in un tempo largamento stimato di meno 2000secondi ovvero 33,333333333 minuti (anche molto prima se consideriamo che il pin può avere cifre molto più basse di 9999).
