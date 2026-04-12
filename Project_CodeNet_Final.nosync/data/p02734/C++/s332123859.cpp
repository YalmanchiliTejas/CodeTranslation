#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
// const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
const ll MOD = 998244353;

ll N, S;
ll A[3030];
ll dp[3030][3030][3];

int main() {
  cin >> N >> S;
  rep(i, 0, N) { cin >> A[i]; }

  dp[0][0][0] = 1;
  for (ll i = 0; i <= N - 1; i++) {
    for (ll j = 0; j <= S; j++) {
      dp[i + 1][j][0] += dp[i][j][0];
      dp[i + 1][j][0] %= MOD;
      if (j + A[i] <= S) {
        dp[i + 1][j + A[i]][1] += dp[i][j][0] * (i + 1) % MOD;
        dp[i + 1][j + A[i]][1] %= MOD;
        dp[i + 1][j + A[i]][2] += dp[i][j][0] * (i + 1) % MOD * (N - i) % MOD;
        dp[i + 1][j + A[i]][2] %= MOD;
      }

      dp[i + 1][j][1] += dp[i][j][1];
      dp[i + 1][j][1] %= MOD;
      if (j + A[i] <= S) {
        dp[i + 1][j + A[i]][1] += dp[i][j][1];
        dp[i + 1][j + A[i]][1] %= MOD;
        dp[i + 1][j + A[i]][2] += dp[i][j][1] * (N - i) % MOD;
        dp[i + 1][j + A[i]][2] %= MOD;
      }

      dp[i + 1][j][2] += dp[i][j][2];
      dp[i + 1][j][2] %= MOD;
    }
  }

  cout << dp[N][S][2] << endl;
}