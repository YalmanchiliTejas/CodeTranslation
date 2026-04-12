#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

ll modpow(ll k, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % mod;
    k = k * k % mod;
    n /= 2;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  ll sum = 0, r = 0;
  rep(i, n) sum = (sum + a[i]) % mod;
  rep(i, n) r = (r + (ll)a[i] * a[i] % mod) % mod;

  ll ans = sum * sum % mod;
  ans = (ans - r + mod) % mod;
  ans = ans * modpow(2, mod - 2) % mod;
  cout << ans << endl;
  return 0;
}
