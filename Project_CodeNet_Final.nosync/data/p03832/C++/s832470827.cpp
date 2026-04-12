#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
const int mod = 1e9 + 7;
 
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
 
int64 fact[202020], rfact[202020];
int N, A, B, C, D;
int64 dp[1001][1001];
 
int main()
{
  fact[0] = rfact[0] = 1;
  for(int i = 1; i < 102020; i++) {
    fact[i] = fact[i - 1] * i % mod;
    rfact[i] = modInv(fact[i]);
  }
 
  cin >> N >> A >> B >> C >> D;
 
  dp[A - 1][0] = fact[N];
  for(int j = A; j <= B; j++) { // j 人の組
    int64 bat = 1;
    for(int k = 0; k < C - 1; k++) (bat *= rfact[j]) %= mod;
    for(int k = C; k <= D; k++) { // k 個
      (bat *= rfact[j]) %= mod;
      for(int i = N - 1; i >= 0; i--) {
        int sum = i + j * k;
        if(sum > N) continue;
        (dp[j][sum] += 1LL * dp[j - 1][i] * bat % mod * rfact[k] % mod) %= mod;
      }
    }
    for(int k = N; k >= 0; k--) (dp[j][k] += dp[j - 1][k]) %= mod;
  }
  cout << dp[B][N] << endl;
}