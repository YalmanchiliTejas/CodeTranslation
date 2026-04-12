// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
  int N;
  cin >> N;
  vector<int64> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int64 sub = 0;
  int64 add = 0;
  int64 ans = 0;
  if (N % 2 == 0) {
    for (int i = 0; i < (N - 1) / 2; i++) {
      sub += A[i] * 2;
    }
    sub += A[(N - 1) / 2];
    for (int i = N - 1; i > N - 1 - (N - 1) / 2; i--) {
      add += A[i] * 2;
    }
    add += A[N - 1 - (N - 1) / 2];
    ans = add - sub;
  } else {
    for (int i = 0; i < (N - 1) / 2; i++) {
      sub += A[i] * 2;
    }
    for (int i = N - 1; i > N - 1 - (N - 1) / 2; i--) {
      add += A[i] * 2;
    }
    int64 sub1 = sub + A[(N - 1) / 2] - A[(N - 1) / 2 - 1];
    int64 add1 = add + A[N - 1 - (N - 1) / 2] - A[N - (N - 1) / 2];
    // cout << add << ' ' << sub << ' ' << add1 << ' ' << sub1 << ' ' << endl;
    ans = max(add1 - sub, add - sub1);
  }
  cout << ans << endl;
  return 0;
}
