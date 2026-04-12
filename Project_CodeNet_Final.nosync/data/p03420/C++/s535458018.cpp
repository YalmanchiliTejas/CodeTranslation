#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 1LL * n * n << endl;
    return 0;
  }
  long long ans = 0;
  for (int a = m; a <= n; ++a) {
    ans += n - a;
  }
  for (int b = m + 1; b <= n; ++b) {
    int t = n / b;
    ans += 1LL * (t - 1) * (b - m);
    if (b * t + m <= n) {
      ans += n - (b * t + m) + 1;
    }
  }
  cout << ans << endl;
}
