#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  const ll mod = 1e9 + 7;

  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 0;

  vector<ll> acc(n, 0ll);
  for (int i = n - 1; i > 0; i--) {
    acc[i - 1] += acc[i] + a[i];
    acc[i - 1] %= mod;
  }

  for (int i = 0; i < n - 1; i++) {
    ans += (acc[i] * a[i]) % mod;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
