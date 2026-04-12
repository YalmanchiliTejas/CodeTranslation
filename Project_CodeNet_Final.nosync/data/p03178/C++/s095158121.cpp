#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

string s;
int d;

void add(int& x, int v) {
  x = (x + v) % MOD;
}

void solve() {
  // dp[i][j][k]: 到第i位为止，和为k mod d的数有几个。j代表是否前面都和s中第i位相同
  vector<vector<vector<int> > > dp(s.size() + 1, vector<vector<int> >(2, vector<int>(d, 0)));
  dp[0][1][0] = 1;
  for (int i=1; i<=s.size(); ++i) {
    for (int g=0; g<=9; ++g) {
      for (int p=0; p<d; ++p) {
        int digit = s[i-1] - '0';
        int q = (g + p) % d;
        if (g < digit) {
          add(dp[i][0][q], dp[i-1][0][p]);
          add(dp[i][0][q], dp[i-1][1][p]);
        } else if (g == digit) {
          add(dp[i][0][q], dp[i-1][0][p]);
          add(dp[i][1][q], dp[i-1][1][p]);
        } else {
          add(dp[i][0][q], dp[i-1][0][p]);
        }
      }
    }
  }
  cout << ((dp[s.size()][0][0] + dp[s.size()][1][0] - 1) % MOD + MOD) % MOD << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  cin >> d;
  solve();
  return 0;
}