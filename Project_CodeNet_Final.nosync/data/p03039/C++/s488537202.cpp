#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX = 200002;
const int MOD = 1000000007;
int fac[MAX], finv[MAX], inv[MAX];
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

// 二項係数計算
int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main(){
    COMinit();
   int n,m,k;
   cin>>n>>m>>k;
   
 int p=0;
  for(int i=1;i<n;i++){
      p=(p+(n-i)*i*m*m)%MOD;
  }
   for(int i=1;i<m;i++){
      p=(p+(m-i)*i*n*n)%MOD;
  }
p=(p*COM(n*m-2,k-2))%MOD;
cout<<p;
    
    return 0;
}