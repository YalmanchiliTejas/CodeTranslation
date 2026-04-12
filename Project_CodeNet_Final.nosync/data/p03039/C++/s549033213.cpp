#include <bits/stdc++.h> //色々大嘘
//二つ目違うし比較も違う
using namespace std;
//関数
const long INF=1000000000000000;
const long MOD=1000000007;
bool check=false;

long modinv(long a) {
    long  b = MOD, u = 1, v = 0;
    while (b) {
        long  t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

template< typename T >
T binomial(T N, T K) {
  if(K < 0 || N < K) return 0;
  T ret = 1;
  for(T i = 1; i <= K; ++i) {
    ret *= N--;
    ret%=MOD;
    ret *=modinv(i);
    ret%=MOD;
  }
  return ret%MOD;
}

int main(void){
    //cout<<binomial((long)10,(long)3)<<endl;
    long N,M,K;
    cin>>N>>M>>K;
    long ans=0,kasami=binomial(N*M-2,K-2);
    for(long d=1;d<N;d++){
        long pat=(N-d)*M*M;
        pat%=MOD;
        
        pat*=kasami;
        pat%=MOD;
        
        ans+=d*pat;
        ans%=MOD;
    }
    for(long d=1;d<M;d++){
        long pat=(M-d)*N*N;
        pat%=MOD;
        
        pat*=kasami;
        pat%=MOD;
        
        ans+=d*pat;
        ans%=MOD;
    }
    
    cout<<ans<<endl;
}