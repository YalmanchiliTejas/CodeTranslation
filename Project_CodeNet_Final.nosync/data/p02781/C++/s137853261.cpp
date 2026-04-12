#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
  string s; cin >> s;
  int d = s.size();
  int n[d];
  for (int i = 0; i < d; i++) n[i] = s[i] - '0';
  int k; cin >> k;

  int c = 1;
  int dp[d][k+1] = {};
  dp[0][0] = 1;
  dp[0][1] = n[0] - 1;
  for (int i = 1; i < d; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i-1][j-1] * 9 + dp[i-1][j];
    }
    if (n[i] > 0) {
      if (c <= k) dp[i][c] += 1;
      c++;
      if (c <= k) dp[i][c] += n[i] - 1;
    }
  }
  if (c == k) dp[d-1][k]++;

  cout << dp[d-1][k] << endl;
}