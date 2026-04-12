#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

int mapto[200];
int card[4][20];
int point[2];

int main() {
  mapto['S'] = 0;
  mapto['H'] = 1;
  mapto['D'] = 2;
  mapto['C'] = 3;
  mapto['2'] = 0;
  mapto['3'] = 1;
  mapto['4'] = 2;
  mapto['5'] = 3;
  mapto['6'] = 4;
  mapto['7'] = 5;
  mapto['8'] = 6;
  mapto['9'] = 7;
  mapto['T'] = 8;
  mapto['J'] = 9;
  mapto['Q'] = 10;
  mapto['K'] = 11;
  mapto['A'] = 12;
  char c;
  while (scanf(" %c ", &c), c != '#') {
    int trump = mapto[(int)c];
    point[0] = point[1] = 0;
    REP(i, 4) {
      REP(j, 13) {
        char d, s;
        scanf(" %c %c ", &d, &s);
        int num = mapto[(int)d];
        int suit = mapto[(int)s];
        card[i][j] = num + suit * 13;
      }
    }
    int parent = 0;
    REP(i, 13) {
      int psuit = card[parent][i] / 13;
      int winner = 0;
      int maxvalue = -1;
      REP(j, 4) {
        int num = card[j][i] % 13;
        int suit = card[j][i] / 13;
        int value = num;
        if (suit == psuit) { value += 100; }
        if (suit == trump) { value += 1000; }
        if (value > maxvalue) {
          maxvalue = value;
          winner = j;
        }
      }
      point[winner % 2]++;
      parent = winner;
    }
    if (point[0] > point[1]) {
      printf("NS %d\n", point[0] - 6);
    } else {
      printf("EW %d\n", point[1] - 6);
    }
  }
}