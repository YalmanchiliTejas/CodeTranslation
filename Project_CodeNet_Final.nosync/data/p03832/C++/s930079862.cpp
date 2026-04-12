#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int MAX = 1010;
ll f[MAX], finv[MAX];

ll mod_pow(ll x, ll e) {
  ll v = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) {
      v = v * x % MOD;
    }
    x = x * x % MOD;
  }
  return v;
}

ll Comb(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return (f[n] * finv[k] % MOD) * finv[n - k] % MOD;
}

void init() {
  f[0] = 1;
  for (int i = 1; i < MAX; i++) {
    f[i] = f[i-1] * i % MOD;
  }
  finv[MAX-1] = mod_pow(f[MAX-1], MOD - 2);
  for (int i = MAX - 2; i >= 0; i--) {
    finv[i] = finv[i+1] * (i + 1) % MOD;
  }
}

int main() {
  init();
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
  dp[A-1][N] = 1;
  for (int k = A; k <= B; k++) {
    for (int n = 0; n <= N; n++) {
      (dp[k][n] += dp[k-1][n]) %= MOD;
      ll t = 1;
      for (int m = 2; m < C; m++) {
        if (n < k * m) {
          break;
        }
        t = t * Comb(k * m, k) % MOD;
      }
      for (int m = C; m <= D; m++) {
        if (n < k * m) {
          break;
        }
        t = t * Comb(k * m, k) % MOD;
        ll coef = (Comb(n, k * m) * t % MOD) * finv[m] % MOD;  
        (dp[k][n-k*m] += dp[k-1][n] * coef % MOD) %= MOD;
      }
    }
  }
  cout << dp[B][0] << endl;
  return 0;
}
