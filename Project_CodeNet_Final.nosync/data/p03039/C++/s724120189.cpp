#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
  COMinit();

  long N,M,K;cin>>N>>M>>K;
  long ans=0;
  for(long vx=0;vx<M;vx++){
    for(long vy=0;vy<N;vy++){
      long C=(vx+vy)%MOD;
      long S=((M-vx)*(N-vy))%MOD;
      long O=COM(M*N-2,K-2)%MOD;
      if(vx!=0&&vy!=0){
        S*=2;
        //if(vx!=vy)S*=2;
      }
      ans=ans+(((C*S)%MOD)*O)%MOD;
    }
  }
  cout<<ans%MOD;
}