#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll dp[120][2][500];

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  dp[0][1][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int a = 0; a <= 9; ++a) {
        if (a == 0) {
          dp[i + 1][(s[i] == '0')][j] += dp[i][1][j];
          dp[i + 1][0][j] += dp[i][0][j];
        } else if (a < s[i] - '0') {
          dp[i + 1][0][j + 1] += dp[i][1][j];
          dp[i + 1][0][j + 1] += dp[i][0][j];
        } else if (a == s[i] - '0') {
          dp[i + 1][1][j + 1] += dp[i][1][j];
          dp[i + 1][0][j + 1] += dp[i][0][j];
        } else {
          dp[i + 1][0][j + 1] += dp[i][0][j];
        }
      }
    }
  }
  cout << dp[n][0][k] + dp[n][1][k] << endl;
  return 0;
}