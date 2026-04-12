#include <bits/stdc++.h>

const int MAX_N = 200005;
const int64_t MOD = 1000000007;
int N;
int64_t vals[MAX_N];

int main() {
  scanf("%d", &N);
  int64_t sum = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%lld", vals + i);
    vals[i] %= MOD;
    sum += vals[i];
  }
  sum %= MOD;
  int64_t ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    sum = (sum + MOD - vals[i]) % MOD;
    ans = ((ans % MOD) + (vals[i] * sum) % MOD) % MOD;
  }
  printf("%lld\n", ans % MOD);
}
