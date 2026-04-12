#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;
typedef long long ll;

const int Mod = 1e9+7;

//逆元
//fermatの定理を利用
// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// a^{-1} mod を計算する
ll modinv(ll a, ll mod) {
  return modpow(a, mod-2, mod);
}

ll cal_comb(ll a, ll b, ll mod) {
  if (b > a-b) return cal_comb(a, a-b, mod);
  ll bunsi = 1;
  ll bunbo = 1;
  for (int i = 0; i < b; ++i) {
    bunsi *= (a - i);
    bunsi %= mod;
    bunbo *= (i + 1);
    bunbo %= mod;
  }
  return bunsi * modinv(bunbo, mod) % mod;
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  rep(i, m) {
    ans += i * (m-i) * n * n;
    ans %= Mod;
  }
  rep(i, n) {
    ans += i * (n-i) * m * m;
    ans %= Mod;
  }
  ans *= cal_comb(n*m-2, k-2, Mod);
  ans %= Mod;
  cout << ans << endl;
  return 0;
}