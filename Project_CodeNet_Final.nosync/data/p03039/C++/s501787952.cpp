#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int nmax=2000010;
ll fac[nmax],finv[nmax],inv[nmax];
 
void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<nmax;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
ll com(int n,int k){
  if(n<k||n<0||k<0){
    return 0;
  }
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
 
int main(){
  COMinit();
  ll n,m,k;cin >> n >> m >> k;
  ll ans=0;
  for(ll i=0;i<n;i++){
    ans+=i*(n-i)%mod*m%mod*m%mod;
    ans%=mod;
  }
  for(ll i=0;i<m;i++){
    ans+=i*(m-i)%mod*n%mod*n%mod;
    ans%=mod;
  }
  ans*=com(n*m-2,k-2);
  ans%=mod;
  cout << ans << endl;
}