#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF INT_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

ll modpow(ll x,ll n){
  if(n==0)return 1;
  if(n%2)return (modpow(x,n-1)*x)%MOD;
  else {
    ll half=n/2;
    ll halfpow=modpow(x,n/2)%MOD;
    return (halfpow*halfpow)%MOD;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int N,M,K;
  cin>>N>>M>>K;
  vector<ll>fac(N*M+1);
  fac[0]=1;
  for(int i=1;i<=N*M;i++)fac[i]=(fac[i-1]*i)%MOD;

  ll inv=modpow((fac[N*M-2-(K-2)]*fac[K-2])%MOD,MOD-2)%MOD;
  ll comb=(fac[N*M-2]*inv)%MOD;

  ll x=0;
  for(int i=1;i<N;i++)x+=((M*M)%MOD*((N-i)*(i*comb)%MOD)%MOD)%MOD;
  ll y=0;
  for(int i=1;i<M;i++)y+=((N*N)%MOD*((M-i)*(i*comb)%MOD)%MOD)%MOD;

  cout<<(x+y)%MOD<<endl;
  return 0;
}
