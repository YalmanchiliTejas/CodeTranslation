#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  int ans = 0ll;
  cin >> a[0];

  for (int i=1; i<n; i++) {
    cin >> a[i];
    ans += (a[i] * a[i-1])%MOD;
    a[i] += a[i-1];
    ans %= MOD;
    a[i] %= MOD;
  }
  cout << ans << endl;
  return 0;
}
