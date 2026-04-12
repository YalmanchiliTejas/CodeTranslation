#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll extgcd(ll a,ll b,ll& x,ll& y){
  ll d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
ll mod_inverse(ll a,ll m){
  ll x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}
ll MOD=1000000007LL;

ll dp[1111][1111];
ll fact[1111],facti[1111];
ll po[1111][1111];
int main(){
  ll n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;

  
  fact[0]=facti[0]=1;
  for(ll i=1;i<=n;i++){
    fact[i]=(fact[i-1]*i)%MOD;
    facti[i]=(facti[i-1]*mod_inverse(i,MOD))%MOD;
    assert((fact[i]*facti[i])%MOD==1);
  }
  
  for(ll i=1;i<=n;i++){
    po[i][0]=1LL;
    for(ll j=1;i*j<=n;j++){
      po[i][j]=((po[i][j-1])*facti[i])%MOD;
    }
  }
  
  dp[0][a]=1;
  for(ll i=a;i<=b;i++){
    for(ll j=0;j<=n;j++){
      if(dp[j][i]==0) continue;
      (dp[j][i+1]+=dp[j][i])%=MOD;
      for(ll k=c;k<=d;k++){
	if(j+i*k>n) break; 
	(dp[j+i*k][i+1]+=((dp[j][i]*po[i][k])%MOD)*facti[k])%=MOD;
      }
    }
  }

  /*//
  for(ll j=0;j<=n;j++)
    for(ll i=a;i<=b+1;i++) 
      cout<<dp[j][i]<<" \n"[i==b+1];
  //*/

  ll ans=1LL;
  for(ll i=1;i<=n;i++) (ans*=i)%=MOD;
  cout<<(ans*dp[n][b+1])%MOD<<endl;
  return 0;
}
