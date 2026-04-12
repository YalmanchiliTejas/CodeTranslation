#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Mod {
  vector<ll> fact;
  vector<ll> finv;
  Mod() {}
  Mod(int n, int p) {
    fact.resize(n + 1); fact[0] = 1;
    for (int i = 1; i < n + 1; ++i) fact[i] = fact[i - 1] * i % p;
    finv.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) finv[i] = mod_pow(fact[i], p - 2, p);
  }
  int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b) {
      d = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    } else {
      x = 1, y = 0;
    }
    return d;
  }
  ll mod_pow(ll x, ll n, ll m) {
    if (n == 0) return 1;
    ll res = mod_pow(x * x % m, n / 2, m);
    if (n & 1) res = res * x % m;
    return res;
  }
};

const ll MOD = 1e9 + 7;
ll dp[1001][1001];
Mod m(1001, MOD);

ll f(int i, int j, int k) {
  ll x = 1;
  x = x * m.fact[j] % MOD;
  x = x * m.finv[j - i * k] % MOD;
  x = x * m.mod_pow(m.finv[i], k, MOD) % MOD;
  return x * m.finv[k] % MOD;
}

int main() {
  int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  dp[0][0] = 1;
  for (int i = 1; i <= B; ++i) {
    for (int j = 0; j <= N; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (i < A) continue;
      for (int k = C; k <= D; ++k) {
        if (j - i * k < 0) break;
        dp[i][j] += f(i, j, k) * dp[i - 1][j - i * k] % MOD;
      }
      dp[i][j] %= MOD;
    }
  }
  cout << dp[B][N] << endl;
  return 0;
}
