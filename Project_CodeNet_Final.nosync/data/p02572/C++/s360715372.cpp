#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll sum[n - 1];
  sum[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    sum[i] += a[n - i - 1];
    sum[i] %= MOD;
    if (i != n - 2) {
      sum[i + 1] = sum[i];
    }
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ll tmp = a[i] * sum[n - 2 - i];
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}