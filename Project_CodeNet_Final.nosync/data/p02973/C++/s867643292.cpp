#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 100005;
char en = '\n';
ll inf = 1e16;
ll mod = 1000000007;
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

  ll n;
  cin >> n;
  ll arr[n + 5];

  for (ll i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = -arr[i];
  }

  multiset<int> s;
  multiset<int>::iterator it;

  for (ll i = 1; i <= n; i++) {
    s.insert(arr[i]);

    it = s.upper_bound(arr[i]);

    if (it != s.end())
      s.erase(it);
  }

  cout << s.size() << endl;

  return 0;
}