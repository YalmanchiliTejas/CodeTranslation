#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 9;
const int mod = 998244353;
int fac[maxn];
int inv[maxn];
int power[maxn];

int modpow(int base, int exponent) {
  int var = base;
  int ans = 1;
  while(exponent > 0) {
    if(exponent & 1) {
      ans = (1LL * ans * var) % mod;
    }
    var = (1LL * var * var) % mod;
    exponent >>= 1;
  }
  return ans;
}
int nCr(int n, int r) {
  int num = fac[n];
  int den = (1LL * inv[r] * inv[n - r]) % mod;
  return (1LL * num * den) % mod;
}
int main() {
  int n;
  cin >> n;
  fac[0] = power[0] = 1;
  for(int i = 1; i <= n; i++) {
    fac[i] = (1LL * fac[i - 1] * i) % mod;
    power[i] = (power[i - 1] * 2LL) % mod;
  }
  inv[n] = modpow(fac[n], mod - 2);
  for(int i = n - 1; i >= 0; i--) {
    inv[i] = (1LL * inv[i + 1] * (i + 1)) % mod;
  }
  int ans = modpow(3, n);
  for(int i = (n / 2) + 1; i <= n; i++) {
    ans -= (1LL * power[n - i + 1] * nCr(n, i)) % mod; 
    ans %= mod;
  }
  cout << (ans + mod) % mod << endl;
  return 0;
}
