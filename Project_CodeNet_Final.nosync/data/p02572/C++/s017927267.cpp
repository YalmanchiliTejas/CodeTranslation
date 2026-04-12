#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), x(n + 11, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= MOD;
    x[i + 1] = (x[i] + a[i]) % MOD;
  }
  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ll p = x[n] - x[i + 1];
    ans += (p < 0 ? p + MOD : p) * a[i];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}