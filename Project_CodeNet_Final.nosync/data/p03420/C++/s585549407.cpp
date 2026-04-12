#include <iostream>

typedef long long ll;

ll N, K;

int main() {
  std::cin >> N >> K;
  if (K == 0)
    std::cout << N*N << "\n";
  else {
    ll ans = 0;
    for (ll b = K+1; b <= N; ++b) {
      //std::cout << b << " " << N/b << " " << b - K << " " << N%b - K + 1<< "\n";
      //std::cout << (N/b)*(b - K) + std::max(N%b - K + 1, 0LL) << "\n";
      ans += (N/b)*(b - K) + std::max(N%b - K + 1, 0LL);
    }
    std::cout << ans << "\n";
  }

  return 0;
}
