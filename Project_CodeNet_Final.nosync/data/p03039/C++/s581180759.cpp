#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
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

long long f(long long N,long long M){
	long long k=0,j=0;
  	for(int i=0; i<M; i++){
      k+=j+((N-1)*N*(2*N-1)/6+(N-1)*N/2)/2;
      j+=N*N*(i+1)+(N-1)*N*(2*N-1)/6+(N-1)*N/2;
      k%=MOD;j%=MOD;
    }
  	return k;
}

int main(){
  COMinit();
  long long N,M,K;cin >> N >> M >> K;
  cout << (COM(N*M-2,K-2)*f(N,M))%MOD << endl;
}