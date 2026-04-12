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

  n -= mp[x];
  for (auto t : v) {
    if (t == x) break;
    stot += t;
  }
  ll num = n / (cnt - mp[x]);
  ll mod = n % (cnt - mp[x]);
  ll cycle = tot - stot;
  ans = cycle * num + stot;
  for (int i = mp[x]; i < mp[x] + mod; ++i) ans += v[i];
  cout << ans << endl;
  return 0;
}