#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<ll> sums(n + 1, 0);
  for (int i = 1; i <= n; ++i) sums[i] = sums[i - 1] + a[i - 1];

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll tmp = a[i] * ((sums[n] - sums[i + 1]) % MOD);
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}

