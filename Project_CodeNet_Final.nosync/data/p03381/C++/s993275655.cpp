#include <bits/stdc++.h>

using namespace std;

template <typename T> T gcd(T x, T y) {
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

template <typename T> T lcm(T x, T y) {
  if (x == 0 || y == 0)
    return 0;
  return x / gcd(x, y) * y;
}

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  vector<int> A = X;
  sort(A.begin(), A.end());
  int mid1 = A[(N - 1) / 2];
  int mid2 = A[N / 2];
  for (int i = 0; i < N; i++) {
    if (mid1 < X[i])
      cout << mid1 << endl;
    else
      cout << mid2 << endl;
  }
}
