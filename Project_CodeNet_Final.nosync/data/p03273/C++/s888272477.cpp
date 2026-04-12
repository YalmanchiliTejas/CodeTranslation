// https://atcoder.jp/contests/abc107/tasks/abc107_b

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int H_MAX = 100;
const int W_MAX = 100;

int H, W;
char a[H_MAX][W_MAX + 1];

bool rx[H_MAX];
bool cx[W_MAX];

void solve() {
  REP(i, H) REP(j, W) rx[i] = rx[i] || (a[i][j] == '#');
  REP(j, W) REP(i, H) cx[j] = cx[j] || (a[i][j] == '#');
  REP(i, H) if (rx[i]) {
    REP(j, W) if (cx[j]) {
      printf("%c", a[i][j]);
    }
    puts("");
  }
}

void input() {
  scanf("%d%d", &H, &W);
  REP(i, H) scanf("%s", a[i]);
}

int main() {
  input();
  solve();
  return 0;
}
