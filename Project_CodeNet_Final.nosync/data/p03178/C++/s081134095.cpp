#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

long long d;
long long dp[10005][2][105] = {0};
string k;

long long solve();

int main() {
  cin >> k >> d;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  for(int i = 0; '0' + i < k[0]; ++i) dp[0][1][i % d] += 1;
  dp[0][0][(k[0] - '0') % d] += 1;
  for(int i = 1; i < k.size(); ++i)
    for(int j = 0; j < 10; ++j)
      for(int l = 0; l < d; ++l) {
        if('0' + j < k[i]) {
          dp[i][1][(l + j) % d] +=
              (dp[i - 1][1][l] + dp[i - 1][0][l]) % N;
          dp[i][1][(l + j) % d] %= N;
        }
        else if('0' + j == k[i]) {
          dp[i][1][(l + j) % d] += dp[i - 1][1][l];
          dp[i][1][(l + j) % d] %= N;
          dp[i][0][(l + j) % d] += dp[i - 1][0][l];
          dp[i][0][(l + j) % d] %= N;
        }
        else {
          dp[i][1][(l + j) % d] += dp[i - 1][1][l];
          dp[i][1][(l + j) % d] %= N;
        }
      }
  return (N + dp[k.size() - 1][1][0] +
          dp[k.size() - 1][0][0] - 1) %
         N;
}