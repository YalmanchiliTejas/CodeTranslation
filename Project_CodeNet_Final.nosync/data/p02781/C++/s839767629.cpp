#include <bits/stdc++.h>
using namespace std;

string s;
long long n, k;
vector<vector<vector<long long>>> dp;

long long solve();

int main() {
  cin >> s >> k;

  cout << solve() << endl;
  return 0;
}

long long solve() {
  n = s.size();
  dp.assign(n + 1, vector<vector<long long>>(
                       2, vector<long long>(k + 1, 0)));
  dp[0][0][0] = 1;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 10; ++j)
      for(int l = 0; l <= k; ++l) {
        long long now = l + (j != 0);
        if(now > k) continue;
        if(j == s[i] - '0') {
          dp[i + 1][1][now] += dp[i][1][l];
          dp[i + 1][0][now] += dp[i][0][l];
        }
        else if(j < s[i] - '0') {
          dp[i + 1][1][now] += dp[i][0][l] + dp[i][1][l];
        }
        else if(j > s[i] - '0') {
          dp[i + 1][1][now] += dp[i][1][l];
        }
        else
          assert(0);
      }
  }
  long long res = 0;
  for(int i = 0; i < 2; ++i) res += dp[n][i][k];
  return res;
}