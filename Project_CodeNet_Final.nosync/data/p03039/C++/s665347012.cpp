#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000000
using Graph=vector<vector<int>>;

long long modpow(long long a,long long n,long long mod){
  long long res=1;
  while(n>0){
    if(n&1){       //nのbitと...00001を比較  nが2で割り切れるならtrue
      res=(res*a)%mod;
    }
    a=(a*a)%mod;
    n>>=1;
  }
  return res;
}

long long modinv(long long a,long long mod){
  return modpow(a,mod-2,mod);
}


int main(){
  ll N,M,K;
  cin>>N>>M>>K;

  ll com=1;
  for(ll i=0;i<K-2;i++){
    com*=(N*M-2-i);
    com%=MOD;
    com*=modinv(i+1,MOD);
    com%=MOD;
  }

  ll sum=0;
  for(ll i=0;i<N;i++){
    for(ll j=0;j<M;j++){
      sum+=i+j;
    }
  }

  ll ans=0;


  for(ll i=0;i<N;i++){
    for(ll j=0;j<M;j++){
      if(j==0){
        ans+=(sum%MOD)*com%MOD;
        ans%=MOD;
        continue;
      }
      sum+=N*(2*j-M);
      ans+=(sum%MOD)*com%MOD;
      ans%=MOD;
    }
    sum+=M*(2*(i+1)-N);
  }
  ans*=modinv(2,MOD);
  ans%=MOD;

  cout<<ans<<endl;
}
