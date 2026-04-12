#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  multiset<ll> s;

  for (ll i = 0; i < n; ++i) {
    ll now = a[i];
    auto itr = s.lower_bound(now);
    if (itr != s.begin()) s.erase(--itr);
    s.insert(now);
  }
  cout << s.size() << endl;
  return 0;
}