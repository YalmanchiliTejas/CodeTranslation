#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
  LL N, K;
  cin >> N >> K;
  LL ans = 0;
  for (LL b = K + 1; b <= N; b++) {
    ans += (N / b) * (b - K);
    ans += max(0LL, N - N / b * b - K + 1);
  }
  if (K == 0) ans = N * N;
  cout << ans << endl;
  return 0;
}