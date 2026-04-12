#include <iostream>
#include <algorithm>

int N, K;

int main() {
  using namespace std;
  cin >> N >> K;

  long long ans = 0;

  if (K == 0) {
    cout << N * (long long)N << endl;
    return 0;
  }

  for (int i = K + 1; i <= N; ++i) {
    // ? % i >= K
    // K, K + i, ... <= N
    ans += N / i * (i - K) + std::max(0, (N % i - (K - 1)));
  }

  cout << ans << endl;
  return 0;
}
