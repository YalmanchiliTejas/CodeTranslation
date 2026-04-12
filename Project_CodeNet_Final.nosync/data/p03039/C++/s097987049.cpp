#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

const int MAX=200001; //nCrのnのMAX+1
ll fac[MAX],finv[MAX],inv[MAX];

void cominit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for (int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
ll com(int n,int k){ //1≦k≦n≦10^7
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
//Add cominit(); in main function.

int main(){
  cominit();
  ll n,m,k;
  cin >> n >> m >> k;
  ll afmul=com(n*m-2,k-2);
  ll ans=0;
  for(int d=1;d<n;d++){
    ans+=d*(n-d)%mod*m%mod*m%mod;
    ans%=mod;
  }
  for(int d=1;d<m;d++){
    ans+=d*(m-d)%mod*n%mod*n%mod;
    ans%=mod;
  }
  ans*=afmul;
  ans%=mod;
  cout << ans << endl;
  
}