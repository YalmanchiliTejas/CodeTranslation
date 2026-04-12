#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll mod=1000000007;
ll a[1005][1005];
ll modpow(ll x,ll y){
if(y==0)
  return 1;
  else if(y%2==0){
  ll z=modpow(x,y/2);
    return (z*z)%mod;
  }else{
  ll z=modpow(x,y/2);
    return (x*((z*z)%mod))%mod;
  }
}
ll dp[1005][1005];
ll comb[1005];
ll N,A,B,C,D;
int main(){
  for(int i=0;i<1005;i++)
    for(int j=0;j<1005;j++)
      a[i][j]=-1;
  cin>>N>>A>>B>>C>>D;
  comb[0]=1;
  for(ll i=1;i<=1004;i++)
    comb[i]=(i*comb[i-1])%mod;
  for(ll i=A;i<=B;i++)
    for(ll j=C;j<=D;j++){
    if(N<i*j)break;
      a[i][j]=modpow((modpow(comb[i],j)*comb[j])%mod,mod-2);
    }
  dp[A-1][0]=1;
  for(int i=A;i<=B;i++){
    for(int j=0;j<=N;j++)
      dp[i][j]=dp[i-1][j];
    for(int j=0;j<=N;j++){
    for(ll k=C;k<=D;k++){
    ll y=a[i][k];if(y<0)break;
      if(0<=j-i*k)
        dp[i][j]=(dp[i][j]+((dp[i-1][j-i*k]*y)%mod))%mod;
    }
    }
  }
    ll ans=(dp[B][N]*comb[N])%mod;
  cout<<ans<<endl;
  return 0;
}