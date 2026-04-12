#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 202020;

long long fac[MAX], finv[MAX], inv[MAX];

inline void add(long long &x, long long y) {
  x += y;
  if(x >= mod) x -= mod;
}

inline void sub(long long &x, long long y) {
  x -= y;
  if(x < 0) x += mod;
}

inline long long mul(long long x, long long y) {
  return x % mod * y % mod;
}

inline long long inverse(long long x) {
  x = (x % mod + mod) % mod;
  long long y = mod, u = 1, v = 0;
  while(y) {
    long long t = x / y;
    x -= t * y; swap(x, y);
    u -= t * v; swap(u, v);
  }
  return (u % mod + mod) % mod;
}

inline long long power(long long x, long long y) {
  long long res = 1;
  while(y) {
    if(y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}

inline void pre_mod_nCk() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i = 2; i < MAX; i++) {
    fac[i] = mul(fac[i - 1], i);
    inv[i] = mod - mul(inv[mod % i], mod / i);
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

inline long long nCk(int n, int k) {
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return mul(fac[n], mul(finv[k], finv[n - k]));
}
long long n, m, k;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m >> k;
  cerr << n << " " <<  m << " " << k << endl;
  pre_mod_nCk();
  long long tate = 0;
  for (long long x = 1; x < n; x++) {
    add(tate, mul(x, n - x));
  }
  (tate *= (m * m % mod)) %= mod;
  cerr << tate << endl;
  long long yoko = 0;
  for (long long x = 1; x < m; x++) {
    add(yoko, mul(x, m - x));
  }
  (yoko *= (n * n % mod)) %= mod;
  //cerr << tate << " " << yoko << endl;
  long long ans = (tate + yoko) % mod;
  //cerr << ans << endl;
  cout << mul(ans, nCk((int) (n * m - 2), (int) (k -2))) << endl;
  return 0;
}