#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  int odd = n%2;
  long a[n];
  rep(i,n)cin >> a[i];
  long dp[n+1][n+1];
  rep(i,n+1)dp[i][i] = 0;
  for(int len=1;len<=n;len++){
    for(int i=0;i+len<=n;i++){
      int j = len+i;
      if(len%2 == odd){
        dp[i][j] = max(dp[i][j-1]+a[j-1],dp[i+1][j]+a[i]);
      }else{
        dp[i][j] = min(dp[i][j-1]-a[j-1],dp[i+1][j]-a[i]);
      }
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}