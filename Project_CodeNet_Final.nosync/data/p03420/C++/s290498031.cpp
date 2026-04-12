#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};



int main() {
  // 入力
  int N, K;
  cin >> N >> K;

  ll ans = 0;
  if (K == 0) {
    ans = 1LL * N * N;
  } else {
    // bを固定して考える
    for (int i = 1; i <= N; i++) {
      int p = N / i;
      int q = N % i;
      ans += p * max(0, i - K) + max(0, q - K + 1);
    }
  }

  // 解答
  cout << ans << endl;

  return 0;
}
