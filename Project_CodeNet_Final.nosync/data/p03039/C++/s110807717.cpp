#include<bits/stdc++.h>
using namespace std;

//mod逆元を使ったnCkの計算(速)
const int64_t MAX = 510000;
const int64_t MOD = 1000000007;

int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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
int64_t COM(int64_t n, int64_t k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  int64_t N, M, K;
  cin >> N >> M >> K;
  int64_t ans = 0;
  
  int64_t n = N*(N*N-1) / 6;
  n %= MOD;
  n *= M*M;
  n %= MOD;
  
  int64_t m = M*(M*M-1) / 6;
  m %= MOD;
  m *= N*N;
  m %= MOD;
  
  ans = n + m;
  ans %= MOD;

  
  COMinit();
  int64_t all = COM(N*M-2,K-2);
  
  ans *= all;
  ans %= MOD;
  
  cout << ans << endl;
  
}