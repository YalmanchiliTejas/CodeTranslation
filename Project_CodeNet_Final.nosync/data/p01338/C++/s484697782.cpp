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

const int point[4] = { 0, 60, 70, 80 };
int field[5][5];
int memo[5][5][1 << 10];

inline int get_point(int x, int y, int rotate) {
  if (field[y][x] == 0) { return 0; }
  return point[(field[y][x] - 1 + rotate) % 4];
}

const int mask = (1 << 10) - 1;
int calc(int x, int y, int puse) {
  if (y == 5) { return 0; }
  if (memo[y][x][puse] != -1) { return memo[y][x][puse]; }
  if (x == 4) {
    int lup = 3 & (puse >> 8);
    int lbottom = 3 & (puse >> 0);
    int nuse = puse & ((1 << 8) - 1);
    return memo[y][x][puse] = calc(0, y + 1, nuse) + get_point(x, y, lup + lbottom);
  }
  int ret = 0;
  REP(rotate, 4) {
    if (y == 4 && rotate > 0) { break; }
    int nuse = ((puse << 2) & mask) | rotate;
    int lup = 3 & (puse >> 8);
    int rup = 3 & (puse >> 6);
    int lbottom = 3 & (puse >> 0);
    if (x == 0) { lbottom = 0; }
    ret = max(ret, calc(x + 1, y, nuse) + get_point(x, y, lup + rup + lbottom + rotate));
  }
  return memo[y][x][puse] = ret;
}

char str[1000];
int main() {
  int test;
  scanf("%d", &test);
  assert(test <= 100);
  while (test--) {
    MEMSET(memo, -1);
    REP(y, 5) REP(x, 5) {
      scanf("%d", &field[y][x]);
      assert(0 <= field[y][x] && field[y][x] <= 4);
    }
    printf("%d\n", calc(0, 0, 0));
  }
  assert(scanf("%s", str) == EOF);
}