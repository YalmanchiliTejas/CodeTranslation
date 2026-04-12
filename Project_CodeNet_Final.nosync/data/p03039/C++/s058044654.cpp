#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=1000000007;

#define rep(i,m,n) for(ll i=m;i<n;i++)

const ll nmax=200005;

ll fac[nmax],finv[nmax],inv[nmax];

void comint(){
 fac[0]=fac[1]=1;
 finv[0]=finv[1]=1;
 inv[1]=1;
 for(long i=2;i<nmax;i++){
  fac[i]=fac[i-1]*i%mod;
  inv[i]=mod-inv[mod%i]*(mod/i)%mod;
  finv[i]=finv[i-1]*inv[i]%mod;
}
}

auto com(auto n, auto k){
 if(n<k||n<0||k<0) return 0;
 return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main(){
  ll n,m,k;
  cin >> n >> m >> k;
  comint();
  ll res=com(n*m-2,k-2);
  ll x=0,y=0;
   rep(d,1,n)(x+=(d*(n-d))%mod)%=mod;
   (x*=m)%=mod;
   (x*=m)%=mod;
   rep(d,1,m)(y+=(d*(m-d))%mod)%=mod;
   (y*=n)%=mod;
   (y*=n)%=mod;
   (res*=(x+y))%=mod;

    
  
  
  cout << res << endl;
}
