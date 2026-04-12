#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;
const lint MOD = 1e9 + 7;

lint power(lint x, lint n, lint mod = numeric_limits<lint>::max()) {
  assert(n >= 0);
  if (n == 0) return 1;
  return power(x * x % mod, n / 2, mod) * (n % 2 ? x : 1) % mod;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

  VI inv(n + 1); inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
  }

  VI finv(n + 1); finv[0] = 1;
  for (int i = 1; i <= n; i++) {
    finv[i] = (lint) inv[i] * finv[i - 1] % MOD;
  }

  VVI dp(b - a + 1, VI(n + 1)); dp[0][0] = 1;
  for (int i = c; i <= d; i++) {
    if (a * i > n) break;
    dp[0][a * i] = power(finv[a], i, MOD) * finv[i] % MOD;
  }

  for (int i = 1; i <= b - a; i++) {
    dp[i] = dp[i - 1];
    for (int j = 0; j <= n; j++) {
      for (int f = c; f <= d; f++) {
        if ((a + i) * f > j) break;
        dp[i][j] = (dp[i][j] + power(finv[a + i], f, MOD) * finv[f] % MOD * dp[i - 1][j - (a + i) * f]) % MOD;
      }
    }
  }
  
  lint res = dp[b - a][n];
  for (int i = 1; i <= n; i++) {
    res = res * i % MOD;
  }
  cout << res << '\n';
  return 0;
}