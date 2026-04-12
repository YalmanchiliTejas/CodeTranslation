#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 mod = 1e9 + 7;

inline int64 modPow(int64 x, int64 n)
{
  if(n == 0) return (1);
  int64 ret = modPow(x, n / 2);
  (ret *= ret) %= mod;
  if(n & 1) (ret *= x) %= mod;
  return (ret);
}

inline int64 modInv(int64 a)
{
  return (modPow(a, mod - 2));
}

int64 fact[2001];

int64 nCr(int64 n, int64 r)
{
  int64 N = 1;
  for(int i = 0; i < r; i++, n--) (N *= n % mod) %= mod;
  return (N * modInv(fact[r]) % mod);
}

int main()
{
  int64 N, D, X;
  int64 dp[2001];

  fact[0] = 1;
  for(int i = 1; i < 2001; i++) (fact[i] = fact[i - 1] * i) %= mod;

  while(cin >> N >> D >> X, N) {

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    int64 ret = 0, now = D;
    for(int64 i = 1; i <= min(D, N); i++) {

      // dp[i][j] := ???[k=j-X+1..j-1] dp[i - 1][k]
      for(int64 j = 1; j <= N; j++) (dp[j] += dp[j - 1]) %= mod;
      for(int64 j = N; j > 0; j--) {
        int64 sub = (j - X < 0 ? 0 : dp[j - X]);
        dp[j] = (dp[j - 1] - sub + mod) % mod;
      }
      dp[0] = 0;
      (ret += nCr(D, i) * dp[N] % mod) %= mod;
    }
    cout << ret << endl;
  }
}