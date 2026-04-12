#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  int64_t X;
  cin >> N >> X;
  vector<int64_t> P(N + 1, 1), B(N + 1, 1);
  for (int i = 1; i < N + 1; i++) {
    P[i] = 2 * P[i - 1] + 1;
    B[i] = 2 * B[i - 1] + 3;
  }
  function<int64_t(int, int64_t)> rec = [&](int n, int64_t x) {
    if (n == 0) {
      return x > 0 ? INT64_C(1) : INT64_C(0);
    } else if (x <= B[n - 1] + 1) {
      return rec(n - 1, x - 1);
    } else {
      return P[n - 1] + rec(n - 1, x - (B[n - 1] + 2)) + 1;
    }
  };
  cout << rec(N, X) << '\n';
  return 0;
}
