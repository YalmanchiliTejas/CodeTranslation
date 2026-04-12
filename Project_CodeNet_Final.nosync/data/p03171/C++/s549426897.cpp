#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
  int n;
  cin>>n;
  int a[n];
  int mx=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    mx+=a[i];
  }
  int dp[n][n];
  memset(dp,0,sizeof dp);
  for(int i=0;i<n;i++){
    dp[i][i]=a[i];
  }
  for(int s=2;s<=n;s++){
    for(int i=0;i<=(n-s);i++){
      int j=i+s-1;
      dp[i][j]=max(a[i]+min(dp[i+1][j-1],dp[i+2][j]),a[j]+min(dp[i][j-2],dp[i+1][j-1]));
    }
  }
  cout<<2*dp[0][n-1]-mx;


}
