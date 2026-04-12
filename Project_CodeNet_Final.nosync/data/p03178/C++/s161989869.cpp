// https://atcoder.jp/contests/dp/tasks/dp_s

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(i, n) printf("%d%c", a[i], i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(i, n) REP(j, m) printf("%d%c", a[i][j], j + 1 == m ? '\n' : ' '); puts("")

// const int K_MAX = 10e10000;
const int S_MAX = 10000;
const int D_MAX = 100;
const int MOD = 1e9+7;

char S[S_MAX + 1];
int D;

int L;
int dp0[2][D_MAX];
int dp1[2][D_MAX];

void solve() {
  L = strlen(S);
  auto cur = dp0;
  auto nxt = dp1;
  cur[0][0] = 1;
  cur[1][0] = 1;
  REP(i, L) {
    fill(nxt[0], nxt[2], 0);
    int d = S[L - 1 - i] - '0';
    REP(j, D) {
      REP(k, 10) {
        nxt[0][(j + k) % D] = (nxt[0][(j + k) % D] + cur[0][j]) % MOD;
      }
      REP(k, d) {
        nxt[1][(j + k) % D] = (nxt[1][(j + k) % D] + cur[0][j]) % MOD;
      }
      nxt[1][(j + d) % D] = (nxt[1][(j + d) % D] + cur[1][j]) % MOD;
    }
    swap(cur, nxt);
  }
  printf("%d\n", (cur[1][0] + MOD - 1) % MOD);
}

void input() {
  scanf("%s", S);
  scanf("%d", &D);
}

int main() {
  input();
  solve();
  return 0;
}
