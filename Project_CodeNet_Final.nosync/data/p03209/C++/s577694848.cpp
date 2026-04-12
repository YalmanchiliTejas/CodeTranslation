#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n + 1, 1), b(n + 1, 1);
  for (ll i = 1; i <= n; i++) {
    a[i] = 1 + a[i - 1] + 1 + a[i - 1] + 1;
    b[i] = b[i - 1] + 1 + b[i - 1];
  }
  ll ans = 0;
  for (ll i = n; i >= 1; i--) {
    if (x == 0) break;
    x--;
    if (x <= a[i - 1]) continue;
    ans += b[i - 1] + 1;
    x -= a[i - 1] + 1;
  }
  if (x) ans++;
  cout << ans << endl;
  return 0;
}
