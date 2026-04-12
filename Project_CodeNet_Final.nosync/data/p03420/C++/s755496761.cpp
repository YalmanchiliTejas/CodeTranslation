#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int64_t result = 0;
  for (int b = K + 1; b <= N; b++) {
    result += (N / b) * (b - K) + max(N % b - K + 1, 0);
    if (K == 0) result--;  // do not include a=0.
  }
  printf("%ld\n", result);

  return 0;
}
