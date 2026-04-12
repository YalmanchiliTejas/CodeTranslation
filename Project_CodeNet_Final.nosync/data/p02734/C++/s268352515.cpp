#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=998244353;

int main(){
  int n,s;
  cin>>n>>s;
  int a[n];
  rep(i,0,n) cin>>a[i];
  ll dp[n+1][s+1];
  dp[0][0]=1;
  rep(i,1,s+1) dp[0][i]=0;
  rep(i,0,n){
    rep(j,0,s+1){
      if(a[i]<=j){
        dp[i+1][j]=(dp[i][j]+dp[i][j-a[i]])%mod;
      }
      else{
        dp[i+1][j]=dp[i][j];
      }
    }
    dp[i+1][0]++;
  }
  ll ans=0;
  rep(i,1,n+1){
    ans+=dp[i][s];
    ans%=mod;
  }
  cout<<ans<<endl;
}