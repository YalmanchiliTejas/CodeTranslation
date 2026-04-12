#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int w = n - 1;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  function<int64(int)> solve_d = ([&](int d) {
    int64 ans = 0;
    int l = 0;
    int r = w;
    int64 current = 0;
    while (true) {
      l += d;
      r -= d;
      if (l > w || r < 0) break;
      if (r <= d) break;
      if (w % d == 0 && r <= l) break;
      current += xs[l];
      current += xs[r];
      ans = max(ans, current);
    }
    return ans;
  });

  int64 ans = 0;
  for (int d = 1; d <= w; d++) {
    ans = max(ans, solve_d(d));
  }
  cout << ans << endl;
}
