#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;

ll modinv(ll a, ll n) {
  // 法nにおけるaの逆元 (ax≡1 mod nのx)を求める関数
  // modinv(a, MOD)でaの逆元(=a^(-1))が求まる
  ll q, s, t, u, v, w;
  s = a; t = n; u = 1; v = 0;
  while (s > 0) {
    q = t/s;
    w = t - q*s;
    t = s;
    s = w;
    w = v - q*u;
    v = u;
    u = w;
  }
  return (v + n) % n;
}

int main() {
  ll n, m, k; cin >> n >> m >> k;
  ll ans = 0;
  rep(i, 1, n) {
    ans += (i*(n-i)*m*m) % MOD;
    ans %= MOD;
  }
  rep(i, 1, m) {
    ans += (i*(m-i)*n*n) % MOD;
    ans %= MOD;
  }
  ll nm = n*m-2, kk = k-2;
  if (nm-kk < kk) kk = nm-kk;
  ll mi = 1;
  for (ll j=0; j<kk; j++) {
    mi *= nm--;
    mi %= MOD;
  }
  for (ll j=1; j<=kk; j++) {
    mi *= modinv(j, MOD);
    mi %= MOD;
  }
  cout << (ans * mi) % MOD << endl;
  return 0;
}
