#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int NP = 4;
const int NR = 13;

/* typedef */

struct Card {
  int rnk;
  char st;

  Card() {}

  int stlvl(char tr, char ldst) const {
    if (st == tr) return 2;
    if (st == ldst) return 1;
    return 0;
  }

  bool higher(char tr, char ldst, const Card& cd) const {
    int lvl0 = stlvl(tr, ldst);
    int lvl1 = cd.stlvl(tr, ldst);
    return (lvl0 > lvl1 || (lvl0 == lvl1 && rnk > cd.rnk));
  }

  void print() { printf("%c%d", st, rnk); }
};

/* global variables */

Card cards[NP][NR];

/* subroutines */

int rank2num(char rank) {
  if (rank == 'A') return NR - 1;
  if (rank == 'K') return NR - 2;
  if (rank == 'Q') return NR - 3;
  if (rank == 'J') return NR - 4;
  if (rank == 'T') return NR - 5;
  return (rank - '2');
}

/* main */

int main() {
  for (;;) {
    char tr;
    cin >> tr;
    if (tr == '#') break;

    for (int i = 0; i < NP; i++)
      for (int j = 0; j < NR; j++) {
	string crd;
	cin >> crd;
	cards[i][j].rnk = rank2num(crd[0]);
	cards[i][j].st = crd[1];
      }

    int nswin = 0, ewwin = 0, ld = 0;
    
    for (int j = 0; j < NR; j++) {
      int wi = ld;
      Card wcd = cards[ld][j];
      char ldst = wcd.st;

      if (false) {
	printf("%d", ld);
	for (int i = 0; i < NP; i++) putchar(':'), cards[i][j].print();
	putchar('\n');
      }
      
      for (int i = 0; i < NP; i++)
	if (cards[i][j].higher(tr, ldst, wcd))
	  wi = i, wcd = cards[i][j];

      if (wi == 0 || wi == 2) nswin++;
      else ewwin++;

      ld = wi;
    }
    //printf("ns=%d, ew=%d\n", nswin, ewwin);

    if (nswin > ewwin)
      printf("NS %d\n", nswin - 6);
    else
      printf("EW %d\n", ewwin - 6);
  }

  return 0;
}