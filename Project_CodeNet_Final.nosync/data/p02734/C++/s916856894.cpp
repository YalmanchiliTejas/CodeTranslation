#include <bits/stdc++.h>
using namespace std;

int n,s,ans,a,dp[10000],MOD=998244353;
void pl(int &a,int b){a=(a+b)%MOD;}

int main(){
  cin>>n>>s;
  dp[0]=1;
  for(int i=0,j=s;i<n;i++){
    cin>>a;
    for(int j=s;j>=0;j--)pl(dp[j+a],dp[j]);
    pl(dp[a],i);
    pl(ans,dp[s]);
  }
  cout<<ans;
}
