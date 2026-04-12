#include <bits/stdc++.h>
using namespace std;
//動画解答例
long long INF=1e18;
long long dp[200005][4];
int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int k=1+n%2;
  for(int i=0;i<n+1;i++){
    for(int j=0;j<k+1;j++){
      dp[i][j]=-INF;
    }
  }
  dp[0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<k+1;j++){
      dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
      long long tmp=dp[i][j];
      if((i+j)%2==0)tmp+=a[i];
      dp[i+1][j]=max(dp[i+1][j],tmp);
    }
  }
  cout<<dp[n][k]<<endl;
  return 0;
}