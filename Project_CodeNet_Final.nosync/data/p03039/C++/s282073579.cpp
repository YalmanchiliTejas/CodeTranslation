#include <iostream>
#define int long long
using namespace std;

typedef long long ll;

ll mod=1e9+7;

ll fac[300010];
 
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
 
void modfac(){
    fac[0]=1;
    for(ll i=1;i<300010;i++){
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

ll dp[200010];

signed main(){
  ll n,m,k;
  cin >> n >> m >> k;
  //2個の時を求めればOK
  ll t=(n*m)%mod;
  modfac();
  ll p=((k*(k-1))%mod*fac[t-2])%mod;
  p=((p*modinv(fac[k]))%mod*modinv(fac[t-k]))%mod;
  ll len=0;
  for(int i=0;i<n;i++){
    len+=i*(i+1)/2;
    len%=mod;
  }
  dp[1]=len;
  for(int i=2;i<=m;i++){
    dp[i]=(dp[i-1]+len)%mod;
    dp[i]+=((len*2)%mod*(i-1))%mod;
    dp[i]%=mod;
    dp[i]+=((n*n)%mod*((i*(i-1)/2)%mod))%mod;
    dp[i]%=mod;
  }
  cout << (dp[m]*p)%mod << endl;
}