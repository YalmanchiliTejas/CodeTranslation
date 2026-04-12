/**
 *    author:  tourist
 *    created: 11.05.2020 14:12:32       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = (int) s.size();
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int limit = (int) (s[i] - '0');
    if (i < n - 1) {
      --limit;
    }
    for (int d = 0; d <= limit; d++) {
      int cur = cnt + (d > 0);
      if (k - cur == 0) {
        ans += 1;
      }
      if (k - cur == 1) {
        ans += (n - i - 1) * 9;
      }
      if (k - cur == 2) {
        ans += (n - i - 1) * (n - i - 2) / 2 * 9 * 9;
      }
      if (k - cur == 3) {
        ans += (n - i - 1) * (n - i - 2) * (n - i - 3) / 6 * 9 * 9 * 9;
      }
    }
    if (s[i] != '0') {
      cnt += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
