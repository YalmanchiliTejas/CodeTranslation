#include <bits/stdc++.h>
using namespace std;

int main() {
  const int64_t mod = 998244353;
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(s + 1));
  for (int i = 0; i < n; i++) {
    dp.at(i).at(0)++;
    for (int j = 0; j <= s; j++) {
      (dp.at(i + 1).at(j) += dp.at(i).at(j)) %= mod;
      if (j + a.at(i) <= s) (dp.at(i + 1).at(j + a.at(i)) += dp.at(i).at(j)) %= mod;
    }
  }
  int64_t ans = 0;
  for (int i = 0; i <= n; i++) {
    (ans += dp.at(i).at(s)) %= mod;
  }
  cout << ans << endl;
}
