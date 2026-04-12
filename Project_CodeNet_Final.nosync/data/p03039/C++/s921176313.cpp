#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()
#define ADD(a, b) a = (a + b) % MOD

// x^n
ll mod_pow(ll x, ll n) {
  if (n == 0) return 1;
  ll res = mod_pow(x * x % MOD, n / 2);
  if (n & 1) res = res * x % MOD;
  return res;
}

// x^{-1}
ll inv(ll x) { return mod_pow(x, MOD - 2); }

ll fact[200001];
ll fact_inv[200001];

void init_fact() {
  fact[0] = fact_inv[0] = 1;
  REP(i, 200000) {
    fact[i + 1] = fact[i] * (i + 1) % MOD;
    fact_inv[i + 1] = fact_inv[i] * inv(i + 1) % MOD;
  }
}

ll nCr(ll n, ll r) {
  if (n < r || n < 0 || r < 0) return 0;
  return fact[n] * fact_inv[r] % MOD * fact_inv[n - r] % MOD;
}

ll nPr(ll n, ll r) { return nCr(n, r) * fact[r] % MOD; }

int main() {
  init_fact();
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  for (ll d = 1; d < n; ++d) {
    ADD(ans, d * (n - d) % MOD * m % MOD * m % MOD);
  }
  for (ll d = 1; d < m; ++d) {
    ADD(ans, d * (m - d) % MOD * n % MOD * n % MOD);
  }
  ans *= nCr(n * m - 2, k - 2);
  ans %= MOD;
  cout << ans << endl;
  return 0;
}