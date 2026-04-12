#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
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

int dp[123][2][5];

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int m = 0; m <= 9; ++m) {
        if (m < s[i] - '0') {
          dp[i + 1][1][j + (m != 0)] += dp[i][0][j];
          dp[i + 1][1][j + (m != 0)] += dp[i][1][j];
        } else if (m == s[i] - '0') {
          dp[i + 1][0][j + (m != 0)] += dp[i][0][j];
          dp[i + 1][1][j + (m != 0)] += dp[i][1][j];
        } else {
          dp[i + 1][1][j + (m != 0)] += dp[i][1][j];
        }
      }
    }
  }
  cout << dp[n][0][k] + dp[n][1][k] << endl;
  return 0;
}