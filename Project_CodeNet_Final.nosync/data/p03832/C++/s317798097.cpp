#include <cstdio>

const int MOD = 1000000007;

int N, A, B, C, D;
int dp[1010][1010]; // last number, remain number
int fac[1010], inv[1010], facinv[1010];

int pow_mod(int x, int y){
  int res = 1, pw = x;
  for(; y > 0; y /= 2){
    if(y % 2 == 1) res = 1LL * res * pw % MOD;
    pw = 1LL * pw * pw % MOD;
  }
  return res;
}

int inv_mod(int x){ return pow_mod(x, MOD - 2); }

int dfs(int now, int rem){
  if(rem == 0) return 1;
  if(rem < 0) return 0;
  if(dp[now][rem] != -1) return dp[now][rem];

  if(now == A){
    if(rem % now == 0){
      int v = rem / now;
      if(v < C || v > D){ dp[now][rem] = 0; return 0; }
      int res = 1LL * fac[rem] * inv_mod(pow_mod(fac[now], v)) % MOD * facinv[v] % MOD;
      dp[now][rem] = res; return res;
    }
    else{ dp[now][rem] = 0; return 0; }
  }

  int res = 0;

  // 0
  res += dfs(now - 1, rem);

  for(int i = C; i <= D; i++){
    if(now * i > rem) break;
    res += 1LL * dfs(now - 1, rem - now * i) * fac[rem] % MOD * inv_mod(fac[rem - now * i]) % MOD * inv_mod(pow_mod(fac[now], i)) % MOD * facinv[i] % MOD;
    res %= MOD;
  }

  dp[now][rem] = res; return res;
}

int main(){
  scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);
  inv[1] = 1;
  for(int i = 2; i <= N; i++) inv[i] = MOD - 1LL * (MOD / i) * inv[MOD % i] % MOD;

  fac[0] = facinv[0] = 1;
  for(int i = 1; i <= N; i++){
    fac[i] = 1LL * fac[i - 1] * i % MOD;
    facinv[i] = 1LL * facinv[i - 1] * inv[i] % MOD;
  }

  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= N; j++) dp[i][j] = -1;
  }

  printf("%d\n", dfs(B, N));
  return 0;
}