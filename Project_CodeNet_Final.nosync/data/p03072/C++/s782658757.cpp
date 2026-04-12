// https://atcoder.jp/contests/abc124/tasks/abc124_b

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 20;
const int H_I_MAX = 100;

int N;
int H[N_MAX];

void solve() {
  int hx = 0;
  int ans = 0;
  REP(i, N) {
    if (H[i] >= hx) {
      ans++;
      hx = H[i];
    }
  }
  printf("%d\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", H + i);
}

int main() {
  input();
  solve();
  return 0;
}
