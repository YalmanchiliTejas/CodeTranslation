#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<long long> A(N);
  std::vector<long long> S(N + 1, 0);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  for (int i = 1; i <= N; i++) {
    S[i] = S[i - 1] + A[i - 1];
  }

  long long ans = 0;
  int mod = 1000000007;

  for (int i = 0; i < N; i++) {
    ans += A[i] * ((S[N] - S[i + 1]) % mod);
    ans %= mod;
  }

  std::cout << ans << "\n";

  return 0;
}