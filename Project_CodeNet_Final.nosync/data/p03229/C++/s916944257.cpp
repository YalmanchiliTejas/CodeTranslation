#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, i;
  cin >> n;
  vector<ll> a(n + 1, 0);
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll ans = 0, tmp = 0;
  int mid = n / 2;
  if (n % 2 == 0 && n > 2) {
    for (i = 1; i <= mid; ++i) {
      ans -= 2 * a[i];
    }
    for (i = mid + 1; i <= n; ++i) {
      ans += 2 * a[i];
    }
    ans = ans - a[mid + 1] + a[mid];
  } else if (n % 2 != 0 && n > 2) {
    for (i = 1; i <= mid; ++i) {
      ans -= 2 * a[i];
    }
    for (i = mid + 2; i <= n; ++i) {
      ans += 2 * a[i];
    }
    ans = ans - a[mid + 1] + a[mid];
    for (i = 1; i <= mid; ++i) {
      tmp -= 2 * a[i];
    }
    for (i = mid + 1; i <= n; ++i) {
      tmp += 2 * a[i];
    }
    tmp = tmp - a[mid + 1] - a[mid + 2];
    ans = max(ans, tmp);
  } else {
    ans = a[2] - a[1];
  }
  cout << ans << "\n";
  return 0;
}