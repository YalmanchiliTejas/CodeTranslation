#include <iostream>
#include <vector>

const long long MOD = 1000000007;

long long pow(long a, long n) {
  long long ret = 1;
  for (; n > 0; n >>= 1, a = a * a % MOD) {
    if (n % 2 == 1) ret = ret * a % MOD;
  }
  return ret;
}

long long inv(long long a) {
  return pow(a, MOD - 2);
}

long long comb(int n, int k) {
  long long ret = 1;
  for (int i = n; i >= n - k + 1; --i) ret = ret * i % MOD;
  for (int i = 1; i <= k; ++i) ret = ret * inv(i) % MOD;
  return ret;
}

int main() {
  long long N, M, K;
  std::cin >> N >> M >> K;
  long long xsum = 0, ysum = 0;
  {
    long long upper = 0;
    long long lower = N * (N - 1) / 2;
    for (int i = 0; i < N; ++i) {
      ysum =(ysum + upper + lower) % MOD;
      upper += i + 1;
      lower += MOD - (N - 1 - i);
      upper %= MOD;
      lower %= MOD;
    }
    {
      long long upper = 0;
      long long lower = M * (M - 1) / 2;
      for (int i = 0; i < M; ++i) {
	xsum =(xsum + upper + lower) % MOD;
	upper += i + 1;
	lower += MOD - (M - 1 - i);
	upper %= MOD;
	lower %= MOD;
      }
    }
  }
  long long ans = 0;
  long long totx = M * M % MOD * inv(2) % MOD;
  long long toty = N * N % MOD * inv(2) % MOD;
  ans = (ysum * totx % MOD + xsum * toty % MOD) % MOD * comb(N * M - 2, K - 2) % MOD;
  std::cout << ans << std::endl;
  return 0;
}
