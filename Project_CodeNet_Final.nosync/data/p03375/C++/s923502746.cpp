//#pragma GCC diagnostic error "-std=c++11"
//#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, mod, C[3030][3030], f[3030][3030];

ll K(ll x,ll y,ll mo=mod){
  ll t=1;
  for (;y;y>>=1, x=x*x%mo)
    if (y&1) t=t*x%mo;
  return t;
}

int main(){
  cin>>n>>mod;
  for (int i=0;i<=n;++i){
    C[i][0]=1;
    for (int j=1;j<=i;++j)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
  }
  f[0][0]=1;
  for (int i=1;i<=n;++i){
    f[i][0]=1;
    for (int j=1;j<=i;++j)
      f[i][j]=(f[i-1][j-1]+(ll)f[i-1][j]*(j+1))%mod;
  }
  ll ans=0;
  for (int i=0;i<=n;++i){
    ll res=0, b1=1, eb1=K(2,n-i), b2=K(2,K(2,n-i,mod-1));
    for (int j=0;j<=i;++j){
      res+= f[i][j]* b1%mod *b2%mod;
      b1=b1*eb1%mod;
    }
    res=res%mod *C[n][i]%mod;
    ans+= i&1? -res: res;
  }
  ans=(ans%mod+mod)%mod;
  cout<<ans<<endl;
}
