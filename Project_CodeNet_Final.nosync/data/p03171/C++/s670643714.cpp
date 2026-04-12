#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)cin>>a[i];
  int dp[n][n];
  memset(dp,0,sizeof(dp));
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<n; j++){
      if(i==j){
        dp[i][j] = a[i];
      }
      if(i>j){
      	dp[i][j] = 0;
      }
      if(i<j){
      	dp[i][j] = max(a[i]-dp[i+1][j], a[j] - dp[i][j-1]);
      }
    }
  }
  cout<<dp[0][n-1]<<"\n";
  return 0;
}