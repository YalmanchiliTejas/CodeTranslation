#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
const long long MOD = 1e9 + 7;

/* べき乗(mのn乗)を計算する関数. O(logn) */
template <typename T>
T modpow(T m, T n, const T &p) {
  if (n == 0) return 1;
  T ret = modpow(m * m % p, n / 2, p);
  if (n % 2) ret *= m;
  return ret % p;
}
/* フェルマーの小定理を使って二項係数を計算. O(r) */
template <typename T>
T binomial(T n, T r, const T &p) {
  if (r > n - r) return binomial(n, n - r, p);
  T ansMul = 1;
  T ansDiv = 1;
  for (T i = 0; i < r; i++) {
    ansMul *= (n - i);
    ansDiv *= (i + 1);
    ansMul %= p;
    ansDiv %= p;
  }
  // ansDivの逆元
  T ans = (ansMul * modpow(ansDiv, p - 2, p)) % p;
  return ans;
}

int main() {
  llint n, m, k;
  cin >> n >> m >> k;

  llint ans = 0;
  for (llint d = 1; d < n; d++) {
    ans += d * (n - d) * m * m;
    ans %= MOD;
  }
  swap(n, m);
  for (llint d = 1; d < n; d++) {
    ans += d * (n - d) * m * m;
    ans %= MOD;
  }

  ans *= binomial(n * m - 2, k - 2, MOD);
  ans %= MOD;
  cout << ans << endl;

  return 0;
}