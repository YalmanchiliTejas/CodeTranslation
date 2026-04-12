#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int k, d = s.size();
  cin >> k;
  vector<int> n(d);
  for (int i = 0; i < d; i++) n.at(i) = s.at(i) - '0';
  vector<vector<int>> dp_exact(d + 1, vector<int>(k + 1)),
    dp_under(d + 1, vector<int>(k + 1));
  dp_exact.at(0).at(0) = 1;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j <= k; j++) {
      if (n.at(i) && j < k) {
        dp_exact.at(i + 1).at(j + 1) += dp_exact.at(i).at(j);
        dp_under.at(i + 1).at(j + 1) += dp_exact.at(i).at(j) * (n.at(i) - 1);
      }
      if (n.at(i) == 0) dp_exact.at(i + 1).at(j) += dp_exact.at(i).at(j);
      if (n.at(i)) dp_under.at(i + 1).at(j) += dp_exact.at(i).at(j);
      if (j < k) dp_under.at(i + 1).at(j + 1) += dp_under.at(i).at(j) * 9;
      dp_under.at(i + 1).at(j) += dp_under.at(i).at(j);
    }
  }
  cout << dp_exact.at(d).at(k) + dp_under.at(d).at(k) << endl;
}
