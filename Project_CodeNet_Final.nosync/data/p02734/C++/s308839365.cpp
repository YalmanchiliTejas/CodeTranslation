#include<iostream>
#include<algorithm>
#include<cstdint>

int64_t const MOD = 998244353;

int const MAXN = 3000;

int64_t dp1[MAXN+1][MAXN+1];
int64_t dp2[MAXN+1][MAXN+1];
int N, S;

int main() {
  std::cin >> N >> S;
  for(int i = 1; i <= N; ++i) {
    // don't choose i'th num
    std::copy_n(dp1[i-1], S+1, dp1[i]);
    for(int s = 1; s <= S; ++s) dp2[i][s] = (dp2[i-1][s]+dp1[i-1][s])%MOD;
    int a; std::cin >> a;
    // x_1 = i
    (dp1[i][a] += i) %= MOD;
    (dp2[i][a] += i) %= MOD;
    // x_2+ = i
    for(int s = a+1; s <= S; ++s) {
      (dp1[i][s] += dp1[i-1][s-a]) %= MOD;
      (dp2[i][s] += dp1[i-1][s-a]) %= MOD;
    }
  }
  std::cout << dp2[N][S] << std::endl;
  return 0;
}
