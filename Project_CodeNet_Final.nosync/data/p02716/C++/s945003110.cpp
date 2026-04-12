#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll dp[200005][3]={0};
ll minf=-1744174417441744;
int main(){
  ll n;
  cin>>n;
  for(int i=0;i<=n+1;i++){
    dp[i][0]=minf;
    dp[i][1]=minf;
    dp[i][2]=minf;
  }
  dp[0][0]=0;
  dp[1][0]=0;
  for(int i=2;i<=n+1;i++){
    ll a;
    cin>>a;
    dp[i][0]=max(dp[i][0],dp[i-2][0]+a);
    dp[i][1]=max(dp[i][1],dp[i-2][1]+a);
    dp[i][2]=max(dp[i][2],dp[i-2][2]+a);
    if(i>=3) dp[i][1]=max(dp[i][1],dp[i-3][0]+a);
    if(i>=3&&n%2==1) dp[i][2]=max(dp[i][2],dp[i-3][1]+a);
    if(i>=4&&n%2==1) dp[i][2]=max(dp[i][2],dp[i-4][0]+a);
  }
  ll ans;
  if(n%2==1){
    ans=max({dp[n+1][0],dp[n+1][1],dp[n+1][2]});
    ans=max({ans,dp[n][0],dp[n][1]});
    ans=max({ans,dp[n-1][0]});
  }
  else{
    ans=max({dp[n+1][0],dp[n+1][1],dp[n][0]});
  }
  cout<<ans<<endl;
}
