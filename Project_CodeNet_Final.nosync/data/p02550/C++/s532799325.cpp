#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, X, M;
  cin >> N >> X >> M;
  
  long ans = 0;
  vector<pair<long, long>> pre(M);

  for (long i = 0; i < N; i++) {
    auto [p_i, p_ans] = pre.at(X);
    if (!p_i) {
      pre.at(X) = {i, ans};
    } else {
      long len = i - p_i;
      long cnt = (N - i - 1) / len;
      i += len * cnt;
      ans += (ans - p_ans) * cnt;
    }
    ans += X;
    X = X * X % M;
  }
  cout << ans << "\n";
}