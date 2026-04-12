#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1e3 + 3;

ll powmod(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1, (a *= a) %= MOD) {
    if (b & 1) (res *= a) %= MOD;
  }
  return res;
}

ll inversemod(ll a) {
  return powmod(a, MOD - 2);
}

int n, A, B, C, D;
ll fact[N], f[N][N];

ll P(int n, int k) {
  return (fact[n] * inversemod(fact[n - k])) % MOD;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> A >> B >> C >> D;
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % MOD;
  for (int j = 0; j <= n; ++j) f[0][j] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      f[i][j] = f[i][j - 1];
      if (A <= j && j <= B) {
        for (int k = C; k <= D; ++k) {
          if (i - j * k < 0) break;
          (f[i][j] += (((((f[i - j * k][j - 1] * P(n - i + j * k, j * k)) % MOD) * inversemod(fact[k])) % MOD) * inversemod(powmod(fact[j], k))) % MOD) %= MOD;
        }
      }
    }
  }
  cout << f[n][n];
  return 0;
}