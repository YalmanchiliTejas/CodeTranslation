#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const ll mods = 1e9 + 7;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> s(n + 1, 0);
  rep(i, n) cin >> a[i];
  rep(i, n) s[i + 1] = s[i] + a[i];
  ll ans = 0;
  rep(i, n) {
    ll num = (s[n] - s[i + 1]) % mods;
    ans += a[i] * num;
    ans %= mods;
  }
  cout << ans << '\n';
  return 0;
}