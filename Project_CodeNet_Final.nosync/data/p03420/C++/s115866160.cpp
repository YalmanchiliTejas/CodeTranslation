/**
 *    author:  tourist
 *    created: 26.11.2019 03:24:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  for (int b = 1; b <= n; b++) {
    for (int a = 0; a <= n; a += b) {
      int from = max(a + k, 1);
      int to = min(a + b - 1, n);
      if (from <= to) {
        ans += to - from + 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
