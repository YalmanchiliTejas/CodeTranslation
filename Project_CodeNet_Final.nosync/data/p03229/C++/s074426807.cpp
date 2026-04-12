#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto&& w : a) cin >> w;
  sort(begin(a), end(a), greater<int>());
  int m = (n - 1) / 2;
  int s1 = accumulate(begin(a), begin(a) + m + 1, 0ll);
  int s2 = accumulate(begin(a) + m + 1, end(a), 0ll);
  int ans, ans1, ans2;
  if (n % 2 == 1) {
    ans1 = (2 * s1 - a[m] - a[m - 1]) - (2 * s2);
    ans2 = (2 * (s1 - a[m])) - (2 * (s2 + a[m]) - a[m] - a[m + 1]);
    ans = max(ans1, ans2);
  } else {
    ans = (2 * s1 - a[m]) - (2 * s2 - a[m + 1]);
  }
  cout << ans << endl;
}