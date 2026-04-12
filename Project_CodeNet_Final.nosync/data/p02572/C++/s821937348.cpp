#include <bits/stdc++.h>
#include <vector>

#define rep(x, n) for(int i = x; i < (n); ++i)

using namespace std;
using ll = long long;

int main(void)
{
  ll n;
  cin >> n;
  vector<ll> a(n), b(n + 1, 0);
  ll mod = 1000000007;
  for (int i = 0; i < n; ++i) {
    cin >> a.at(i);
    b.at(i + 1) = b.at(i) + a.at(i);
  }

  ll res = 0;
  for (int j = 0; j < n; ++j) {
    ll sum = (b.at(n) - b.at(j + 1)) % mod;
    res += a.at(j) * sum;
    res %= mod;
  }
  cout << res << endl;
}