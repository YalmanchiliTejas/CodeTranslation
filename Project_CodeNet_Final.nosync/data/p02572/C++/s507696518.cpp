#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n), s(n + 1, 0);
  rep(i, n) cin >> a[i];
  rep(i, n) s[i + 1] = s[i] + a[i];
  rep(i, n - 1) {
    ll t1 = (s[n] - s[i + 1]);
    t1 %= MOD;
    ans += a[i] * t1;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}