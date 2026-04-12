#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
using namespace std;
typedef long long ll;

const int MAX = 510000;
const int MOD = 1000000007;

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

int main() {
  COMinit();
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  FOR(d, 1, n) {
    ans += ((d * (n - d)) % MOD) * (m * m % MOD);
    ans %= MOD;
  }
  FOR(d, 1, m) {
    ans += ((d * (m - d)) % MOD) * (n * n % MOD);
    ans %= MOD;
  }
  ans *= COM(n * m - 2, k - 2);
  ans %= MOD;
  cout << ans << endl;
  return 0;
}