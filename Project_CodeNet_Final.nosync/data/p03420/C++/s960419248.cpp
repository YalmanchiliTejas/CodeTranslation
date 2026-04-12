#include <cstdint>
#include <iostream>

using namespace std;

int main()
{
  uint64_t N, K;
  cin >> N >> K;

  if (K == 0) {
    cout << (N * N) << endl;
    return 0;
  }

  uint64_t S = 0;
  for (uint64_t b = K + 1; b <= N; ++b) {
    // 1 <= a <= N
    // a = x * b + k, k >= K
    uint64_t d = N / b, r = N % b, t = b - K;
    
    S += d * t;
    if (r + 1 > K) {
      S += r - K + 1;
    }
  }
  cout << S << endl;

  return 0;
}