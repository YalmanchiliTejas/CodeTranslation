#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define N 200010
ll fac[N],inv[N],ivf[N];
ll c(ll n,ll k){
    return fac[n]*ivf[n-k]%mod*ivf[k]%mod;
}
int main(){
  fac[0]=ivf[0]=inv[1]=1;
  for(int i=1;i<N;i++){
      if(i>1)inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
      fac[i]=fac[i-1]*i%mod;
      ivf[i]=ivf[i-1]*inv[i]%mod;
  }
  ll n,m,k;cin>>n>>m>>k;
  ll ans=0;
  for(int d=1;d<m;d++){
      mad(ans,(m-d)*n*n*d);
  }
  for(int d=1;d<n;d++){
      mad(ans,(n-d)*m*m*d);
  }
  ans=ans*c(n*m-2,k-2)%mod;
  cout<<ans<<endl;
  return 0;
}
