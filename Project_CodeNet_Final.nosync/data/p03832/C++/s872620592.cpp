#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif

typedef long long LL;

#define MOD 1000000007
LL fPow(LL t, int p) {
  LL ret = 1;
  while (p) {
    if (p&1)ret = ret * t % MOD;
    t = t * t % MOD;
    p >>= 1;
  }
  return ret;
}

#define N 1010
int fact[N], f[N][N], dp[N][N], C[N][N];
void calc() {
  fact[0] = 1;
  for (int i = 1; i <= 1000; i++)
    fact[i] = fact[i-1] * (LL) i % MOD;
  C[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
      if (i%j!=0)
        continue;
      f[i][j] = fact[i] * fPow(fPow(fact[i/j], j), MOD-2) %MOD* fPow(fact[j], MOD-2) % MOD;
    }
  }
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  calc();
  int n, a, b, c, d;
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  dp[a-1][0] = 1;
  for (int i = a; i <= b; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = dp[i-1][j];
      for (int k = c; k <= min(d, j / i); k++) {
        dp[i][j] = (dp[i][j] + dp[i-1][j-k*i]*(LL)C[j][k*i]%MOD * (LL)f[k*i][k]) % MOD;
      }
    }
  }
  printf("%d\n", dp[b][n]);
  return 0;
}
