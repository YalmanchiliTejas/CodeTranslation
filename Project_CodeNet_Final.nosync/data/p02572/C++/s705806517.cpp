#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = (s[i] + a[i]) % mod;

  ll ans = 0;
  rep(i, n - 1) {
    ans = (ans + (ll)a[i] * (s[n] - s[i + 1] + mod) % mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
