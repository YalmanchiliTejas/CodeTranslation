#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(n + 1));
  for (int s = n - 1; s >= 0; s--) {
    for (int i = 0; i <= s; i++) {
      dp.at(i).at(s - i) = max(a.at(i) - dp.at(i + 1).at(s - i),
                               a.at(n - 1 - (s - i)) - dp.at(i).at(s - i + 1));
    }
  }
  cout << dp.at(0).at(0) << endl;
}
