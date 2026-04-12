#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  vector<int> y = X;
  map<int, int> where;
  sort(y.begin(), y.end());
  for (int i = 0; i < N; ++i) {
    where[y[i]] = i;
  }
  for (int i = 0; i < N; ++i) {
    if (where[X[i]] < N / 2) {
      cout << y[N / 2] << endl;
    } else {
      cout << y[N / 2 - 1] << endl;
    }
  }
  return 0;
}
