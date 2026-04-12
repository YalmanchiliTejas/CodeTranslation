#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll mod=998244353;
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
ll N;
ll fac[10000005];
ll rev[10000005];
ll inf[10000005];
int main(){
  cin>>N;N/=2;
  fac[0]=1;rev[0]=1;
  for(ll i=1;i<=N;i++){
  fac[i]=(i*fac[i-1])%mod;
    rev[i]=modpow(fac[i],mod-2);
  }ll a=1;
  inf[0]=1;
  for(ll i=1;i<=N;i++){
  a=(a*2)%mod;
    inf[i]=(a*((fac[N]*((rev[N-i]*rev[i])%mod))%mod))%mod;
  }ll ans=0;ll sum=0;
  for(ll i=0;i<N;i++){
  sum=(sum+inf[i])%mod;
    ans=(ans+((inf[N-1-i]*sum)%mod))%mod;
  }
  ll all=modpow(9,N);
  ans=(all-2*ans+2*mod)%mod;
  cout<<ans<<endl;
     return 0;
}