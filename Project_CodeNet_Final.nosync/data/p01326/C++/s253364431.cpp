#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

const ll MOD = 1000000;
int n;
char bytes[1100][20];
ll memo[1100][4][2];

ll calc(int depth, int rest, int exist) {
  if (memo[depth][rest][exist] != -1) { return memo[depth][rest][exist]; }
  ll ret = 0;
  if (depth == n) {
    if (rest == 0) { ret = 1; }
    return memo[depth][rest][exist] = ret;
  }
  for (int i = 0; i < (1 <<  8); i++) {
    int nrest = rest - 1;
    int nexist = 1;
    REP(j, 8) {
      if (bytes[depth][7 - j] != 'x' && bytes[depth][7 - j] - '0' != ((i >> j) & 1)) { goto next; }
    }
    if (rest == 0) {
      if (!(i & (1 << 7))) { nrest = 0; }
      else if (!(i & (1 << 6))) { goto next; }
      else if (!(i & (1 << 5))) { nrest = 1; }
      else if (!(i & (1 << 4))) { nrest = 2; }
      else if (!(i & (1 << 3))) { nrest = 3; }
      else { goto next; }
      if (nrest == 1) {
        if (!(i & (2 + 4 + 8 + 16))) { goto next; }
      } else if (nrest == 2) {
        if (!(i & (1 + 2 + 4 + 8))) { nexist = 0; }
      } else if (nrest == 3) {
        if (!(i & (1 + 2 + 4))) { nexist = 0; }
      }
    } else {
      if (!(i & (1 << 7))) { goto next; }
      if (i & (1 << 6)) { goto next; }
      if (!exist) {
        if (rest == 2) {
          if (!(i & 32)) { goto next; }
        } else if (rest == 3) {
          if (!(i & (16 + 32))) { goto next; }
        } else {
          assert(false);
        }
      }
    }
    ret = (ret + calc(depth + 1, nrest, nexist)) % MOD;
next:;
  }
  return memo[depth][rest][exist] = ret;
}

int main() {
  while (scanf("%d", &n), n) {
  REP(i, n) {
    scanf("%s", bytes[i]);
  }
  MEMSET(memo, -1);
  printf("%lld\n", calc(0, 0, 1));
  }
}