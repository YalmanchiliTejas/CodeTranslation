#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  int64_t total = A[N - 1] - A[0];
  int L = 0, R = N - 1;
  while (L < R) {
    int L2 = L + 1;
    int R2 = R - 1;
    if (L2 == R2) {
      if (A[R] - A[L2] > A[R2] - A[L]) {
        total += A[R] - A[L2];
        L = L2;
      } else {
        total += A[R2] - A[L];
        R = R2;
      }
    } else {
      total += A[R] - A[L2];
      total += A[R2] - A[L];
      L = L2;
      R = R2;
    }
  }
  printf("%ld\n", total);

  return 0;
}
