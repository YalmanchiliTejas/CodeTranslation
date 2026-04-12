/*input
10000000000 10 99959
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  const int MX = 100005;
  vector<ll> a(MX);
  a[0] = x;
  map<ll, int> mp;
  mp[a[0]] = 0;
  int s, t;
  rep(i, MX) {
    ll na = (a[i]*a[i])%m;
    // cout << a[0] << " " << na << endl;
    if (mp.count(na)) {
      s = mp[na];
      t = i+1;
      break;
    }
    a[i+1] = na;
    mp[na] = i+1;
  }
  ll ans = 0;
  if (n < t) {
    rep(i, n) ans += a[i];
  }
  else {
    rep(i, s) ans += a[i];
    n -= s;
    ll sum = 0;
    for (int i = s; i < t; ++i) sum += a[i];
    ans += n/(t-s)*sum;
    for (int i = s; i < s+n%(t-s); ++i) ans += a[i];
  }
  cout << ans << endl;
}