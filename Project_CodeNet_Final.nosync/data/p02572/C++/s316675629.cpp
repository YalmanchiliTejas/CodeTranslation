#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 922337203685477;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define maxN 200007
using namespace std;
ll addmod(ll a, ll b) {
  if (0 == b)
    return a;
  b = mod - b;
  if (a >= b)
    return a - b;
  else
    return mod - b + a;
}
ll mulmod(ll a, ll b) {
  ll res = 0;
  a = a % mod;
  while (b > 0) {
    if (b % 2 == 1)
      res = (res + a) % mod;
    a = (a * 2) % mod;
    b /= 2;
  }
  return res % mod;
}
int main() {
  fastio;
  ll n = 0, s = 0;
  cin >> n;
  ll ar[n];
  for (ll i = 0; i < n; ++i)
    cin >> ar[i], s += ar[i];
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    s -= ar[i];
    ans = addmod(ans, mulmod(ar[i], s));
  }
  cout << ans;
}