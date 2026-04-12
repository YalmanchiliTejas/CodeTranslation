#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string N;
  cin>>N;
  int k;
  cin>>k;
  int n = N.size();
  ll dp[n+1][k+1][2] = {}; // ith digit, j non-zero digits, less/greater than N
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) { // for each digit of N starting from MSD
    for (int j = 0; j <= k; j++) { // each count of zero digits
      dp[i+1][j][1] += dp[i][j][1];
      if (N[i] == '0') dp[i+1][j][0] += dp[i][j][0];
      if (N[i] != '0') dp[i+1][j][1] += dp[i][j][0];
      for (int h = 1; h <= 9; h++) {
        if (j + 1 <= k && N[i] == ('0'+h)) dp[i+1][j+1][0] += dp[i][j][0];
        if (j+1<=k){
          dp[i+1][j+1][1] += dp[i][j][1];
          if ('0' + h < N[i]) dp[i+1][j+1][1] += dp[i][j][0];
        }
      }
    }
  }
  ll ans = dp[n][k][0] + dp[n][k][1];
  cout << ans << endl;
}
