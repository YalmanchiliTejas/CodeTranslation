// https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(i, n) printf("%d%c", a[i], i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(i, n) REP(j, m) printf("%d%c", a[i][j], j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 3000;
const int A_I_MAX = 1e9;

int N;
int a[N_MAX];

ll dp[N_MAX][N_MAX];

void solve() {
  FOR(k, 1, N) {
    bool sen = ((N - k) % 2 == 0);
    FOR(i, 0, N - k) {
      if (k == 1) {
        if (sen) {
          dp[i][i] = a[i];
        } else {
          dp[i][i] = -a[i];
        }
      } else {
        int j = i + k - 1;
        if (sen) {
          dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
        } else {
          dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
        }
      }
    }
  }
  // DUMP2D(dp, N, N);
  printf("%lld\n", dp[0][N - 1]);
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
}

int main() {
  input();
  solve();
  return 0;
}
