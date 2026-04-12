#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[55], b[55];
int main() {
  ll n, x;
  cin >> n >> x;
  a[0] = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] * 2 + 1;
  }
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] * 2 + 3;
  }
  ll ans = 0;
  while (x > 0) {
    if (x == b[n]) {
      ans += a[n];
      x = 0;
    } else if (x >= b[n] / 2 + 1) {
      ans += a[n - 1] + 1;
      x -= b[n] / 2 + 1;
    } else {
      x--;
    }
    n--;
  }
  cout << ans << endl;
  return 0;
}