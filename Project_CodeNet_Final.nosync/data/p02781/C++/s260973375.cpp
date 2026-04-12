// https://atcoder.jp/contests/abc154/tasks/abc154_e

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int S_MAX = 100;
const int K_MAX = 3;

char S[S_MAX + 1];
int N, K;

int dp[S_MAX + 1][2][K_MAX + 1];

void solve() {
  N = strlen(S);
  dp[0][0][0] = 1;
  REP(i, N) {
    int d = S[i] - '0';
    REP(smaller, 2) REP(j, K + 1) REP(x, smaller ? 10 : d + 1) {
      if (j == K && x > 0) continue;
      dp[i + 1][smaller || x < d][j + (x > 0)] += dp[i][smaller][j];
    }
  }

  // REP(smaller, 2) {
  //   REP(_i, N + 1) REP(_j, K + 1) printf("%d%c", dp[_i][smaller][_j], _j == K ? '\n' : ' ');
  //   puts("");
  // }

  printf("%d\n", dp[N][0][K] + dp[N][1][K]);
}

void input() {
  scanf("%s", S);
  scanf("%d", &K);
}

int main() {
  input();
  solve();
  return 0;
}
