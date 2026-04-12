#include <bits/stdc++.h>
using namespace std;

long long dp[3010][3010];
int main() {
  int n, s;
  cin>>n>>s;
  int a[n];
  for (int i=0; i<n+1; i++) cin>>a[i];
  for (int i=0; i<1; i++) {
    for (int j=0; j<s+1; j++) {
      dp[i][j] = 0;
    }
  }
  long long mod = 998244353;
  for (int i=0; i<n; i++) {
    ++dp[i][0];
    for (int j=0; j<s+1; j++) {
      dp[i+1][j] += dp[i][j];
      if (j - a[i] >= 0) {
        dp[i+1][j] += dp[i][j-a[i]];
        dp[i+1][j] %= mod;
      }
    }
  }
  long long ans = 0;
  for (int i=1; i<n+1; i++) {
    ans += dp[i][s];
    ans %= mod;
  }
  cout<<ans<<endl;
}