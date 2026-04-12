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
  vector<ll> d;

  rep(i, n) {
    auto itr = lower_bound(d.rbegin(), d.rend(), a[i]);
    if (itr == d.rbegin())
      d.emplace_back(a[i]);
    else
      *--itr = a[i];
  }
  cout << d.size() << endl;
  return 0;
}