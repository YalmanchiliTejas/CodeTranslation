#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, X, M;
  cin >> N >> X >> M;

  vector next(60, vector(M, 0L));
  auto sum = next;
  for (int i = 0; i < M; i++) {
    next.at(0).at(i) = (long) i * i % M;
    sum.at(0).at(i) = i;
  }

  for (int i = 0; i + 1 < 60; i++) {
    for (int j = 0; j < M; j++) {
      next.at(i + 1).at(j) = next.at(i).at(next.at(i).at(j));
      sum.at(i + 1).at(j) = sum.at(i).at(j) + sum.at(i).at(next.at(i).at(j));
    }
  }

  long ans = 0;
  for (int i = 0; i < 60; i++) {
    if (N >> i & 1) {
      ans += sum.at(i).at(X);
      X = next.at(i).at(X);
    }
  }
  cout << ans << "\n";
}