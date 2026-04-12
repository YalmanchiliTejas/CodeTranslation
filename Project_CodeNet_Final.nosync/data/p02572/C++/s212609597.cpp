#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> a(n);
  vector<int64_t> am(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  am[0] = a[n-1];
  am[0] %= MOD;
  for (int i = 1; i < n; ++i) {
      am[i] = am[i-1] + a[n-i-1];
      am[i] %= MOD;
  }

  int64_t ans = 0;

  for (int i = 0; i < n-1; ++i) {
    ans += (am[n-i-2] * a[i]);
    ans %= MOD;
  }

  cout << ans << '\n';

  return 0;
}
