#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10, mod = 998244353;
long long fac[N];

long long bpow(long long b, long long e) {
  long long res = 1;
  while (e) {
    if (e & 1) {
      res *= b;
      res %= mod;
    }
    b *= b;
    b %= mod;
    e >>= 1;
  }
  return res;
}

long long inv(long long x) { return bpow(x, mod - 2); }

long long C(int n, int k) {
  // n! / k! / (n - k)!
  return fac[n] * inv(fac[k]) % mod * inv(fac[n - k]) % mod;
}

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  for (int i = n / 2 + 1; i <= n; i++) {
    // nCi * 2 ^ (n - i)
    ans += bpow(2, n - i) * C(n, i) % mod;
    ans %= mod;
  }
  ans <<= 1;
  ans %= mod;
  // cout << ans << endl;
  ans = ((bpow(3, n) - ans) % mod + mod) % mod;
  cout << ans << endl;
  return 0;
}
