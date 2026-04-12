#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t N, X, M;
  cin >> N >> X >> M;
  int64_t res = 0;
  set<int64_t> st;
  auto f = [](int64_t x, int64_t m) { return x % m; };
  while (N > 0 && st.find(X) == st.end()) {
    res += f(X, M);
    st.insert(X);
    X *= X;
    X %= M;
    N--;
  }
  if (N == 0) {
    cout << res << '\n';
    return 0;
  }
  int64_t loop = 0;
  set<int64_t> tt;
  while (tt.find(X) == tt.end()) {
    loop += f(X, M);
    tt.insert(X);
    X *= X;
    X %= M;
  }
  res += loop * (N / (int)tt.size());
  N %= (int)tt.size();
  while (N > 0) {
    res += f(X, M);
    X *= X;
    X %= M;
    N--;
  }
  // int idx = 0;
  // int64_t tsum = 0;
  // for (int i = 0; i < (int)XS.size(); i++) {
  //   if (XS[i] == X) {
  //     idx = i;
  //     break;
  //   }
  // }
  // for (int i = idx; i < (int)XS.size(); i++) {
  //   tsum += XS[i];
  // }
  // res *= (N / ((int)XS.size() - idx));
  // N %= (int)XS.size() - idx;
  // while (N > 0) {
  //   res += f(X, M);
  //   X *= X;
  //   X %= M;
  //   N--;
  // }
  cout << res << '\n';
  return 0;
}
