#include<bits/stdc++.h>
using namespace std;
const long MAX = 12000000;
const long MOD = 998244353;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (long i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long COM(long n, long k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long powmod(long x,long p){
  if(p==0)return 1;
  if(p%2)return powmod(x,p-1)*x%MOD;
  long long a=powmod(x,p/2);return a*a%MOD;
}
int main() {
  COMinit();
  long N;cin>>N;
  long X=0;
  for(long k=N/2+1;k<=N;k++){
    X=(X+COM(N,k)*powmod(2,N-k))%MOD;
  }
  long ans=(powmod(3,N)-2*X+2*MOD)%MOD;
  cout<<ans<<endl;
}



/*
消去によって偶奇は変化しない
偶A or 奇B -> X
偶B or 奇A -> Y
と変換すると
XXとYYが消せないものになる
どのような消し方をしてもXXが余ってしまうのは, X>N/2の時

Xがk個になる場合の数は
nCk * 2^(N-k)


*/