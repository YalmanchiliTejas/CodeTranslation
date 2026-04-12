#include <bits/stdc++.h>
using namespace std;

typedef long long int LLI;
const LLI MOD = 1e9 + 7;

int N;
int A;
int B;
int C;
int D;
LLI fact[1145];
LLI invfact[1145];
LLI dp[1145][1145];
LLI memo[1145][1145];

LLI inv(LLI n) {
  return n == 1 ? n : inv(MOD % n) * (MOD - MOD / n) % MOD;
}

LLI mypow(LLI base, LLI exp) {
  if (exp == 0) return 1;
  LLI res = mypow(base*base%MOD, exp/2);
  if (exp%2) res = res*base % MOD;
  return res;
}

LLI f(int i, int j) {
  if (j < 0) return 0;
  return dp[i][j];
}

LLI comb(int n, int k) {
  if (n < 0) return 0;
  if (n < k) return 0;
  if (memo[n][k]) return memo[n][k];
  if (k == 0 || k == n) return 1;
  return memo[n][k] = (comb(n-1, k-1) + comb(n-1, k)) % MOD;
}

int main() {
  scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);

  fact[0] = 1;
  invfact[0] = 1;
  for (int i=1; i<=N; i++) {
    fact[i] = fact[i-1] * i % MOD;
    invfact[i] = inv(fact[i]);
  }

  dp[A-1][0] = 1;
  for (int i=A; i<=B; i++) {
    for (int j=0; j<=N; j++) dp[i][j] = dp[i-1][j];
    for (int j=i; j<=N; j++) {
      for (int k=C; k*i<=j && k <= D; k++) {
        LLI t = dp[i-1][j-i*k] * fact[i*k] % MOD;
        t = t * (comb(N + i*k - j, i*k) * invfact[k] % MOD) % MOD;
        t = t * mypow(invfact[i], k) % MOD;
        dp[i][j] = (dp[i][j] + t) % MOD;
      }
    }
  }

  /*for (int i=A; i<=B; i++) {
    for (int j=0; j<=N; j++) {
      printf("%lld ", dp[i][j]);
    }
    puts("");
  }*/

  printf("%lld\n", dp[B][N]);
}
