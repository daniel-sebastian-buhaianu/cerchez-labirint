# cerchez-labirint
Se considera un labirint reprezentat ca o matrice cu n linii si m coloane, in care zidurile sunt reprezentate prin caracterul #, iar culoarele prin care se poate trece prin caracterul spatiu. In labirint exista un soricel (pozitia sa fiind marcata cu S in labirint) si o bucata de cascaval (pozitia sa fiind marcata in labirint cu C).

Soricelul se poate deplasa in labirint doar pe culoare. La un pas el poate ajunge in una dintre pozitiile vecine cu pozitia sa, in directiile Nord, Est, Sud sau Vest.

1. Scrieti un program care sa determine lungimea unui drum de lungime minima prin care soricelul poate sa ajunga la bucata de cascaval.
2. Modificati programul astfel incat sa reconstituiti un drum de lungime minima prin care soricelul poate sa ajunga la cascaval.

Exemplu:
* C = 1, n = 5, m = 7
* /#/#   /#/#
*    S/# /#
*      /#
* /# /# /# C
*       /#

Pentru cerinta 1, se va afisa: 8
Pentru cerinta 2, se va afisa: (2,4) (3,4) (4,4) (4,5) (4,6) (3,6) (3,7)
