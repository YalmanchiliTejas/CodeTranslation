#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 200005;
char en = '\n';
ll inf = 1e16;
ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  set<ll> mySet;
  for (char c : s) {
    mySet.insert(c);
  }

  cout << ((mySet.size() == 1) ? "No" : "Yes") << en;

  return 0;
}
