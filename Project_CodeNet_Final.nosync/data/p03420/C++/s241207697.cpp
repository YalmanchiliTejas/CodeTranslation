#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll ans = 0;
  ll n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n * n << endl;
    return 0;
  }
  for (ll i = 2; i <= n; i++) {
    if (i - 1 < k) continue;
    ans += (n / i) * (i - k);
    if (n % i != 0) {
      ans += max(0LL, n % i - (k - 1));
    }
  }
  cout << ans << endl;
  return 0;
}
