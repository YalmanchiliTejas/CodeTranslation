#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

i64 N,A,B,C,D;


i64 MOD = 1e9 + 7;

// Eucli
i64 inv_mod(i64 a, i64 m = MOD) {
  i64 b, x, u, q, abs_m, tmp;

  abs_m = (m < 0) ? -m : m;
  b = m;
  x = 1;
  u = 0;
  while (b > 0) {
    q = a / b;
    tmp = u;
    u = x - q * u;
    x = tmp;
    tmp = b;
    b = a - q * b;
    a = tmp;
  }

  return (x < 0) ? abs_m + x : x;
}

i64 fact[100010];
i64 inv_fact[100010];

i64 nCr(int n, int r) {
  return (fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD) % MOD;
}

//重複組み合わせ
i64 nHr(int n, int r) { return (nCr(n + r - 1, r)) % MOD; }

i64 dp[1010][1010];

i64 ipow(i64 a,i64 k){
  i64 ans = 1;
  while(k > 0){
    if(k & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    k >>= 1;
  }
  return ans;
}

int main(){
  fact[0] = 1;
  rep(i,1,100010 - 1){
    fact[i] = fact[i - 1] * i % MOD;
  }
  inv_fact[100010 - 1] = inv_mod(fact[100010 - 1]);
  for(int i = 100010 - 1;i >= 1;i--){
    inv_fact[i - 1] = inv_fact[i] * i % MOD;
  }
  cin >> N >> A >> B >> C >> D;
  dp[A - 1][N] = 1;

  rep(i,A,B){
    rep(j,0,N){
      dp[i][j] = dp[i - 1][j];
      i64 r = ipow(inv_fact[i],C); 
      for(int k = C;k <= D && i * k <= j;k++){
        (dp[i][j - i * k] += dp[i - 1][j] * fact[j] % MOD * inv_fact[j - i * k] % MOD * r % MOD * inv_fact[k]) %= MOD;
        r = r * inv_fact[i] % MOD;
      }
    }
  }
  cout << dp[B][0] << endl;
}

