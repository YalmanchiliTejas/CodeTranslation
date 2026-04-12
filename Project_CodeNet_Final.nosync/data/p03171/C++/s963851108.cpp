#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  vector<vector<int64_t>> dp(n+2,vector<int64_t>(n+2,0));
  for(int d=0;d<n;d++){
    for(int i=1;i+d<=n;i++){
      if((n-d)%2==1)
        dp[i][i+d]=max(dp[i+1][i+d]+a.at(i-1),dp[i][i+d-1]+a.at(i+d-1));
      else
        dp[i][i+d]=min(dp[i+1][i+d]-a.at(i-1),dp[i][i+d-1]-a.at(i+d-1));
    }
  }
  cout<<dp[1][n]<<endl;
}