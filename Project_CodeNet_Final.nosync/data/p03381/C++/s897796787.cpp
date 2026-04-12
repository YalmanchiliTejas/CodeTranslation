#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N; cin >> N;
  vector<P> X(N); for (int i = 0; i < N; ++i) {
    int val; cin >> val;
    X[i] = {val, i};
  }

  vector<P> A(X), B(N);
  sort(begin(A), end(A));
  for (int i = 0; i < N; ++i) B[i] = {A[i].second, i};
  int c = B[N / 2].second;
  sort(begin(B), end(B));
  for (int i = 0; i < N; ++i) {
    cout << ( (B[i].second < c) ? A[c].first : A[c - 1].first) << endl;
  }
  return 0;
}
