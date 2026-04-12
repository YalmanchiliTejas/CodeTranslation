#include <bits/stdc++.h>
using namespace std;
const int INF=1000010000;
typedef long long ll;
int main() {
  int n;cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  vector<vector<ll>> dp(3100,vector<ll>(3100,0));
  for(int len=1; len<=n; len++){
    for(int i=0; i+len<=n; i++){
      int j=i+len;
      if((n-len)%2==0) dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
      else dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}