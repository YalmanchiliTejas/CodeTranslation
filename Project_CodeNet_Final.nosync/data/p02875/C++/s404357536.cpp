#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll mod=998244353;

vector<ll> fac(100000000);
 
ll modinv(ll a){
    ll b=mod,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b; swap(a,b);
        u-=t*v; swap(u,v);
        }
        u%=mod;
        if(u<0) u+=mod;
    return u;
}
 
void modfac(int n){
    fac[0]=1;
    for(ll i=1;i<n;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
 
ll modperm(ll n,ll k){
    if(n<0||k<0||n<k) return 0;
    else return (fac[n]*modinv(fac[n-k]))%mod;
}
 
ll modcomb(ll n,ll k){
    if(n<0||k<0||n<k) return 0;
    else return ((fac[n]*modinv(fac[k]))%mod*modinv(fac[n-k]))%mod;
}
 
ll modpow(ll a,ll b){
  ll ans=1;
  a%=mod;
  while(b){
    if(b&1) ans=ans*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return ans;
}

int main(){
  ll n;
  cin >> n;
  modfac(10000010);
  ll ans=modpow(3,n);
  ll cnt=modpow(2,n-n/2-1);
  ll inv2=modinv(2);
  for(ll i=n/2+1;i<=n;i++){
    ans-=cnt*modcomb(n,i)*2%mod;
    ans+=mod; ans%=mod;
    cnt*=inv2; cnt%=mod;
  }
  cout << ans << endl;
}