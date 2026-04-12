#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
ll bin_pow(ll a,ll n){
    ll ans=1;
    while(n>0){
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans%mod;
}

ll inv_mod(ll a){
  return bin_pow(a,mod-2);
}

int main()
{
  ll n;
  cin>>n;
  vector<ll> a(n);
  ll sum=0;
  for(auto&& e: a) 
  {
    cin>>e;
    sum+=e;
  }
  ll ans=0;
  for(auto&& e: a) 
  {
    ans+=(((sum-e)%mod)*e)%mod;
    ans%=mod;
    sum-=e;
  }
  cout<<ans<<endl;

}