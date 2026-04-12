#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
int N, S;
int A[3005];
long long memo[3005][3005];

long long dp(int now, int val) {
  if(val == S) return N - now + 2;
  if(now > N || val > S) return 0;
  if(memo[now][val] != -1) return memo[now][val];
  return memo[now][val] = (dp(now + 1, val) + dp(now + 1, val + A[now])) % MOD;
}

int main() {
  memset(memo, -1, sizeof(memo));
  scanf("%d %d", &N, &S);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    ans = (dp(i, 0) + ans) % MOD;
  }
  printf("%lld\n", ans % MOD);
}
