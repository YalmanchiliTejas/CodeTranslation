#include <bits/stdc++.h>
using namespace std;

int main() {
  const int64_t inf = 1e18;
  int n;
  cin >> n;
  vector<int64_t> a(n + 2);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  vector<vector<int64_t>> dp(n + 3, vector<int64_t>(n % 2 + 2, -inf));
  for (int i = 0; i < n % 2 + 2; i++) dp.at(i + 1).at(i) = a.at(i);
  for (int i = 1; i <= n + 2; i++) {
    for (int j = 0; j < n % 2 + 2; j++) {
      for (int k = 0; k <= j; k++) {
        if (i - 2 + k - j < 0) continue;
        dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 2 + k - j).at(k) + a.at(i - 1));
      }
    }
  }
  cout << dp.at(n + 2).at(n % 2 + 1) << endl;
}
