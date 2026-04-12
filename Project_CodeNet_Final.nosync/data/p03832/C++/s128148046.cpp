#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORD(i,b,a) for (int i = (int)(b) - 1; i >= a; --i)
#define REP(i,N) FOR(i,0,N)
#define st first
#define nd second
#define pb push_back

typedef pair<int, int> PII;
typedef long long LL;

int pow_mod(long long a, int b, int mod) {
  int result = 1;
  while (b) {
    if (b&1) result = (result * a) % mod;
    b >>= 1;
    a = (a*a)%mod;
  }
  return result;
}
int inverse_mod(int a, int prime) { return pow_mod(a, prime-2, prime); }

const int MOD = 1000000007;

int DP[2000][2000];
int fact[2000], invfact[2000];
int SN[2000][2000];
int main() {
  fact[0] = invfact[0] = 1;
  FOR(i,1,2000) {
    fact[i] = (fact[i-1]*(LL)i) % MOD;
    invfact[i] = inverse_mod(fact[i], MOD);
  }
  REP(i,2000) {
    SN[i][0] = SN[i][i] = 1;
    FOR(j,1,i) SN[i][j] = (SN[i-1][j-1] + SN[i-1][j]) % MOD;
  }

  int N, A, B, C, D;
  scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);
  DP[A-1][0] = 1;
  FOR(i,A,B+1) {
    REP(p,N+1) {
      DP[i][p] = (DP[i][p] + DP[i-1][p]) % MOD;
      FOR(j,C,D+1) {
        int n = p + i * j;
        if (n > N) break;
        // printf("%d %d %d!\n", i, j, p);
        LL tmp = (DP[i-1][p] * (LL)SN[N-p][i*j]) % MOD;
        // printf("%lld\n", tmp);
        tmp = (tmp * fact[i*j]) % MOD;
        tmp = (tmp * invfact[j]) % MOD;
        tmp = (tmp * pow_mod(invfact[i], j, MOD)) % MOD;
        DP[i][n] = (DP[i][n] + tmp) % MOD;
      }
    }
  }

  printf("%d\n", DP[B][N]);
}
