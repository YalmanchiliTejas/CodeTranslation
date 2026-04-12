#include <bits/stdc++.h>
using namespace std;

#define int long long
int dp[223456][5],v[223456];

int f(int S,int J){
  if(S<=0&&J-S==1)return 0;
  if(S<=0||J<0)return -1e18;
  if(~dp[S][J])return dp[S][J];
  return dp[S][J]=max({f(S-2,J),f(S-3,J-1),f(S-4,J-2)})+v[S-1];
}

signed main(){
  int n;cin>>n;
  for(int i=0;i<n;i++)cin>>v[i];
  memset(dp,-1,sizeof(dp));
  if(n&1)cout<<max({f(n,2),f(n-1,1),f(n-2,0)})<<endl;
  else cout<<max(f(n,1),f(n-1,0))<<endl;
}
