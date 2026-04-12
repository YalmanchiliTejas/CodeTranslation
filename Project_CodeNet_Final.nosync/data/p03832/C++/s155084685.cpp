#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

LL dp[1010][1010];
LL f[1010], iv[1010];
const LL mod = 1000000007;
LL inv(LL a, LL n = mod) {
  return a < 2 ? a : ((1 - n * 1LL * inv(n % a, a)) / a % n + n) % n;
}
LL pow_mod(LL a, LL p, const LL m) {
  LL ret = 1;
  for (; p; p >>= 1, a = a*a%m)
    if (p & 1)
      ret = ret*a%m;
  return ret % m;
}
int main() {
  f[0] = iv[0] = 1;
  REPE(i, 1, 1000) {
    f[i] = f[i-1] * i % mod;
    iv[i] = inv(f[i]);
  }
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  REP(i, 1010) dp[0][i] = 1;
  REPE(i, 1, n) {
    for (int j = a; j <= b; ++j) {
      dp[i][j] = dp[i][j-1];
      int ub = min(d, i / j);
      LL bot = pow_mod(iv[j], c, mod);
      for (int k = c; k <= ub; ++k) {
        dp[i][j] += dp[i-j*k][j-1] * (((f[i] * bot % mod) * iv[i - j * k] % mod) * iv[k] % mod);
        dp[i][j] %= mod;
        bot = bot * iv[j] % mod;
      }
    }
  }
  cout << dp[n][b] << endl;
  return 0;
}

