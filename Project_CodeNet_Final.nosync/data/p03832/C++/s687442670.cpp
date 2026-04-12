#include <cstdio>
#include <cstring>

typedef long long i64;

enum {
  MAXN = 1000 + 5
};

const int MOD = 1e9+7;

int N, A, B, C, D;

int dp[MAXN];
int dp0[MAXN];
int fac[MAXN];
int ifac[MAXN];

int fpm(int x, int exp) {
  int res(1);
  for (; exp; exp>>=1, x=(i64)x*x%MOD)
    if (exp&1)
      res = (i64) res*x % MOD;
  return res;
}

void exec() {
  dp[0] = 1;
  int i, j, k, tmp, FROM;
  for (fac[0]=ifac[0]=1,i=1; i<MAXN; ++i) {
    fac[i] = (i64) fac[i-1] * i % MOD;
    ifac[i] = (i64) ifac[i-1] * fpm(i, MOD-2) % MOD;
  }
  scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);
  for (i=A; i<=B; ++i) {
    memcpy(dp0, dp, sizeof dp);
    FROM = 1;
    for (j=1; j<C; ++j)
      FROM = (i64) FROM*ifac[i] % MOD;
    for (k=0; k<N; ++k) {
      if (!dp[k]) continue;
      tmp = FROM;
      for (j=C; j<=D && (i64)i*j <= N-k; ++j) {
	tmp = (i64) tmp*ifac[i] % MOD;
	(dp0[k+i*j] += (i64) dp[k] * fac[N-k] % MOD * ifac[N-k-j*i] % MOD * tmp % MOD * ifac[j] % MOD) %= MOD;
      }
    }
    memcpy(dp, dp0, sizeof dp0);
  }
  printf("%d\n", dp[N]);
}

int main() {
  if (fopen("E.in", "r") != NULL) {
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
  }
  exec();
  return 0;
}
