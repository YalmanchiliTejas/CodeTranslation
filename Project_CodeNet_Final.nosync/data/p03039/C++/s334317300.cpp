#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll MOD = 1e9 + 7;

ll fac[MAX], finv[MAX], inv[MAX];

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

ll COM(ll n, ll k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll powMod(ll x, ll k) {
  if (k == 0) return 1;
  if (k % 2 == 0)
    return powMod(x * x % MOD, k / 2);
  else
    return x * powMod(x, k - 1) % MOD;
}

int main() {
  ll N, M, K;
  cin >> N >> M >> K;
  COMinit();
  ll ret = 0;
  for (ll d = 1; d <= N - 1; d++) {
    ret = (ret + d * (N - d) * M * M % MOD * COM(N * M - 2, K - 2)) % MOD;
  }
  for (ll d = 1; d <= M - 1; d++) {
    ret = (ret + d * (M - d) * N * N % MOD * COM(N * M - 2, K - 2)) % MOD;
  }
  cout << ret << endl;
}