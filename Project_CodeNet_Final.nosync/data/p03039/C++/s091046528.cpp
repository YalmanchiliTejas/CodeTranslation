#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
vector<ll> kaijo;
ll pow(ll x,ll y){
  if(y==0) return 1;
  ll res=pow(x,y/2);
  res*=res;
  res%=mod;
  if(y%2==1) res*=x;
  return res%mod;
}
void kaijo_set(ll n){
  kaijo.push_back(1);
  for(ll i=1;i<=n;i++) kaijo.push_back(kaijo[i-1]*i%mod);
}
ll nCr(ll n,ll r){
  if(n==0||r==0) return 1;
  ll res=kaijo[n];
  res*=pow(kaijo[r],mod-2);
  res%=mod;
  res*=pow(kaijo[n-r],mod-2);
  return res%mod;
}
int main(){
  ll n,m,k;
  cin>>n>>m>>k;
  kaijo_set(n*m);
  ll ans=0;
  for(ll d=1;d<n;d++){
    ll kans=(n-d)*m;
    kans%=mod;
    kans*=m;
    kans%=mod;
    kans*=nCr(n*m-2,k-2);
    kans%=mod;
    kans*=d;
    kans%=mod;
    ans+=kans;
    ans%=mod;
  }
  swap(n,m);
  for(ll d=1;d<n;d++){
    ll kans=(n-d)*m;
    kans%=mod;
    kans*=m;
    kans%=mod;
    kans*=nCr(n*m-2,k-2);
    kans%=mod;
    kans*=d;
    kans%=mod;
    ans+=kans;
    ans%=mod;
  }
  cout<<ans<<endl;
}
