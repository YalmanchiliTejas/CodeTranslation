#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  if (!k) return cout << 1ll * n * n << endl, 0;
  ll res = 0;
  for (int x = k; x <= n; x++) {
    ll cnt = n / x;
    res += cnt * (x - k) + max(n % x - k + 1, 0);
    // cout << x << " " << res << endl;
  }
  cout << res << endl;
  return 0;
}