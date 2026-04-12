#include <bits/stdc++.h>
using namespace std;

int mod = (int)1e9 + 7;

int safe_mod(long long x, int m) {
  x %= m;
  if (x < 0) {
    x += m;
  }
  return (int)x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum = safe_mod(sum + a[i], mod);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    sum = safe_mod(sum - a[i], mod);
    int prod = safe_mod((long long)a[i] * sum, mod);
    ans = (ans + prod) % mod;
  }
  cout << ans << '\n';
  return 0;
}