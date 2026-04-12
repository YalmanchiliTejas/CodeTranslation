#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, m, n) for (int i = m; i < n; ++i)
const int MOD = 1000000007;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll solve(int N, int M) {
  ll res = 0;
  rep(d, 1, N) {
    res += (ll)d * (N - d) * M * M;
    res %= MOD;
  }
  return res;
}

int main() {
  COMinit();
  int N, M, K;
  cin >> N >> M >> K;
  ll ans = solve(N, M) + solve(M, N);
  ans *= COM(N * M - 2, K - 2);
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
