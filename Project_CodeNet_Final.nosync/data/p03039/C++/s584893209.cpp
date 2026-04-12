#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

struct Modcomb{
  int mod; //素数
  std::vector<long long int>fac;  //階乗
  std::vector<long long int>finv; //階乗の逆元
  std::vector<long long int>inv;  //逆元

  //nCr=n!/r!(n-r)!
  Modcomb(int max,int mod){
    this->mod=mod;
    fac.resize(max+1,0);
    finv.resize(max+1,0);
    inv.resize(max+1,0);
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<=max;i++){
      fac[i]=(fac[i-1]*i%mod)%mod;
      inv[i]=mod-inv[mod%i]*(mod/i)%mod;
      finv[i]=finv[i-1]*inv[i]%mod;
    }
  }

  long long int slove(int n,int r){
    if(n<r)return 0;
    if(n<0||r<0)return 0;
    return fac[n]*(finv[r]*finv[n-r]%mod)%mod;
  }
};

ll modpow(ll x,ll n){
  if(n==0)return 1;
  if(n%2)return ((x%MOD)*(modpow(x,n-1)%MOD))%MOD;
  else {
    ll half=modpow(x,n/2)%MOD;
    return (half*half)%MOD;
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M,K;
  cin>>N>>M>>K;

  Modcomb comb(N*M,MOD);

  ll ans=0;
  vector<ll>sumN(N+1),sumM(M+1);
  sumN[0]=0,sumM[0]=0;
  for(int i=1;i<=N;i++)sumN[i]=(sumN[i-1]+i)%MOD;
  for(int i=1;i<=M;i++)sumM[i]=(sumM[i-1]+i)%MOD;
  for(ll i=1;i<=M;i++){
    ans=((ans%MOD+((N*N)%MOD*(sumM[M]-sumM[i-1])%MOD)%MOD)%MOD)%MOD;
    ans=(ans%MOD-((N*N)%MOD*((M+1-i)*i)%MOD)%MOD)%MOD;
    if(ans<0)ans+=MOD;
  }
  ans%=MOD;
  for(ll i=1;i<=N;i++){
    ans=((ans%MOD+((M*M)%MOD*(sumN[N]-sumN[i-1])%MOD)%MOD)%MOD)%MOD;
    ans=(ans%MOD-((M*M)%MOD*((N+1-i)*i)%MOD)%MOD)%MOD;
    if(ans<0)ans+=MOD;
  }
  ans%=MOD;
  ans=(ans*comb.slove(N*M-2,K-2))%MOD;
  cout<<ans<<endl;

  return 0;
}
