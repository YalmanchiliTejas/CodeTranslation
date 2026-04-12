#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
  int N, K;
  cin >> N >> K;
  
  int ans = 0;
  for (int i = K; i < N; ++i) {
    int B = i + 1;
    ans += (N / B) * (B - K);
    if (K == 0) ans += N % B;
    if (0 < K && K <= N % B) ans += N % B - K + 1;
  }
  cout << ans << endl;
  return 0;
}