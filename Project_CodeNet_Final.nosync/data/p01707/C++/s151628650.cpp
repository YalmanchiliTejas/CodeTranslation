#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,x,dp[2001][2001];
const ll mod = 1e9+7;
 
ll mod_pow(ll x,ll n){
  ll res=1;
  while(n){
    if(n%2) res=res*x%mod;
    x=x*x%mod;
    n/=2;
  }
  return res;
}
 
ll nCr(ll n,ll r){
  ll N=1,K=1; 
  for(int i=0;i<r;i++) N=N*((n-i)%mod)%mod,K=K*((r-i)%mod)%mod;
  ll R=mod_pow(K,mod-2);
  return N*R%mod;
}
 
int main(){
  while(1){
    cin>>n>>d>>x;
    if(!n&&!d&&!x) break;
 
    memset(dp,0,sizeof(dp));  
    for(int i=0;i<x;i++) dp[0][i]=1;
 
   
    for(int i=1;i<=min(d,n);i++){
      ll sum=0;
      for(int j=i+1;j<=n;j++){
	if(j-x>=i)sum=(sum-dp[i-1][j-x]+mod)%mod;
	sum=(sum+dp[i-1][j-1])%mod; 
	dp[i][j]=sum;
      }
    }
     
    ll ans=0;
    for(int i=0;i<min(d,n);i++)
      if(dp[i][n]) ans=(ans+dp[i][n]*nCr(d,i+1)%mod)%mod;
    cout <<ans<<endl;
  }
  return 0;
}