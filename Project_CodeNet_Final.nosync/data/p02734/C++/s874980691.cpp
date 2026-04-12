#include <cstdio>

/*
g(L, R) := \prod_{i=L}^{R} (1 + q^{A_i})
f(L, R) = [q^S] g(L, R)
\sum_{1<=L<=R<=N} f(L, R)
p[i] := \sum_{1<=L<=i} g(L, i)
p[i] = (p[i-1] + 1) * (1 + q^{A_i})
*/

constexpr unsigned mod = 998244353;

int n, s;
unsigned long long dp[3001];

int main(){
  scanf("%d%d", &n, &s);

  int ans = 0;
  for(int i = 0; i < n; i++){
    int a;
    scanf("%d", &a);
    dp[s]++;
    for(int j = 0; j <= s-a; j++){
      dp[j] += dp[j + a];
    }
    if(i % 31 == 30){
      for(int j = 0; j <= s; j++)
        dp[j] %= mod;
    }
    ans = (ans + dp[0]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
