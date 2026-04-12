#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<pair<ll, ll>, ll> mp;
ll f(ll i, ll x) {
  if(x == 0) return 0;
  if(i == 0) return 1;
  if(mp.count({i, x})) return mp[{i, x}];
  ll a = (1LL << (i + 1)) - 3;
  ll res;
  if(x == 1)
    res = 0;
  else if(x < a + 2)
    res = f(i - 1, x - 1);
  else
    res = f(i - 1, a) + f(i - 1, x - a - 2) + 1;
  mp[{i, x}] = res;
  return res;
}
int main() {
  ll n, x;
  cin >> n >> x;
  cout << f(n, x) << endl;
}
