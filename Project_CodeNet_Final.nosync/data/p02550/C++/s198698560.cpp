#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n, x, m, cnt = 0, tot = 0, ans = 0, stot = 0;
  cin >> n >> x >> m;
  unordered_map<ll, ll> mp;
  vector<ll> v;
  while (mp.count(x) == 0) {
    mp[x] = cnt++;
    v.push_back(x);
    tot += x;
    x = x * x % m;
  }

  if (n <= cnt) {
    rep(i, n) ans += v[i];
    cout << ans << endl;
    return 0;
  }

  for (auto t : v) {
    if (t == x) break;
    stot += t;
  }

  ll c = 0;
  ll s = cnt - mp[x];
  for (int i = mp[x]; i < cnt; ++i) c += v[i];
  ans = tot;
  n -= cnt;
  ans += n / s * c;
  n %= s;
  rep(i, n) ans += v[mp[x] + i];
  cout << ans << endl;
  return 0;
}