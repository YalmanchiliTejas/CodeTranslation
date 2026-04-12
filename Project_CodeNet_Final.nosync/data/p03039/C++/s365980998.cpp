#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int nmax=200005;
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;cin >> n >> m >> k;
    COMinit();
    ll ans=0;
    for(ll i=0;i<n;i++){
        (ans+=i*(n-i)%mod*m%mod*m%mod)%=mod;
    }
    for(ll i=0;i<m;i++){
        (ans+=i*(m-i)%mod*n%mod*n%mod)%=mod;
    }
    (ans*=com(n*m-2,k-2))%=mod;
    cout << ans << endl;
}