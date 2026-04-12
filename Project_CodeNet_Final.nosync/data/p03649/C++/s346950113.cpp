#include <bits/stdc++.h>
using namespace std;

signed main() {

  int N; cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  long long res = 0;
  for (int k = 0; k < 1e6; ++k) {
    for (int i = 0; i < N; ++i) {
      if (A[i] < N) continue;         // 操作の必要なし
      long long cnt = A[i] / N;
      A[i] %= N;
      for (int j = 0; j < N; ++j) {
        if (i == j) continue;
        A[j] += cnt;
      }
      res += cnt;
    }
  }

  cout << res << endl;

}
