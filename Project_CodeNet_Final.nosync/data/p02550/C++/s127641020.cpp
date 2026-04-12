#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll lpow(ll x, ll y, ll m){
  ll r = 1;
  x %= m;
  while (y) {
    if (y & 1) r = (r * x) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return r;
}

void fast_io() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
}

int main() {
  fast_io();

  ll n, a, mod;
  cin >> n >> a >> mod;

  ll ans = 0, an = a, fv, gap, nxt;
  ll intv = -1;
  unordered_map<ll, int> u;
  for (int i = 1; i <= n; i++) {
    u.insert({an, i});
    nxt = (an * an) % mod;

    if (u.count(nxt) && i < n) {
      intv = i - u[nxt] + 1;
      gap = u[nxt] - 1;
      fv = nxt;
      ans += an;
      break;
    }
    else {
      ans += an;
      an = nxt;
    }

    if (!an) break;
  }

  if (intv == -1) {
    cout << ans << '\n';
    return 0;
  }
  else {
    ll rep = 0;

    an = fv;
    for (int i = 1; i <= intv; i++) {
      rep += an;
      an = (an * an) % mod;
    }

    ll rept = (n - gap) / intv - 1;
    while (rept--) ans += rep;

    ll nn = (n - gap) % intv;
    for (int i = 1; i <= nn; i++) {
      ans += an;
      an = (an * an) % mod;
    }

    cout << ans << '\n';
  }
}
