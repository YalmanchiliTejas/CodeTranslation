#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n);
  ll keep = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    keep += a.at(i);
  }
  keep %= MOD;
  
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    keep = (keep + MOD - a.at(i)) % MOD;
    ans += (a.at(i) * keep) % MOD;
    ans %= MOD;
  }
  
  cout << ans << '\n';
}