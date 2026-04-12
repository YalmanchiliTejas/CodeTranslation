#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  vector<long> A(N);
  for (long& a : A) cin >> a;
  sort(A.begin(), A.end());
  vector<long> B(N);
  long i1 = 0, i2 = N-1, a1 = 0, a2 = 0;
  if (N % 2 == 0) {
    //
    B[N/2] = A[i2--];
    for (long i = 1; i < N / 2; i++) {
      if (i % 2) {
        B[N/2-i] = A[i1++];
        B[N/2+i] = A[i1++];
      } else {
        B[N/2-i] = A[i2--];
        B[N/2+i] = A[i2--];
      }
    }
    B[0] = A[i1];
    for (long i = 0; i < N-1; i++) {
      a1 += abs(B[i] - B[i+1]);
    }

    //
    i1 = 0; i2 = N - 1;
    B[N/2] = A[i1++];
    for (long i = 1; i < N / 2; i++) {
      if (i % 2) {
        B[N/2-i] = A[i2--];
        B[N/2+i] = A[i2--];
      } else {
        B[N/2-i] = A[i1++];
        B[N/2+i] = A[i1++];
      }
    }
    B[0] = A[i2];
    for (long i = 0; i < N-1; i++) {
      a2 += abs(B[i] - B[i+1]);
    }

  } else {
    //
    B[N/2] = A[i2--];
    for (long i = 1; i <= N/2; i++) {
      if (i % 2) {
        B[N/2-i] = A[i1++];
        B[N/2+i] = A[i1++];
      } else {
        B[N/2-i] = A[i2--];
        B[N/2+i] = A[i2--];
      }
    }
    for (long i = 0; i < N-1; i++) {
      a1 += abs(B[i] - B[i+1]);
    }

    //
    i1 = 0; i2 = N - 1;
    B[N/2] = A[i1++];
    for (long i = 1; i <= N/2; i++) {
      if (i % 2) {
        B[N/2-i] = A[i2--];
        B[N/2+i] = A[i2--];
      } else {
        B[N/2-i] = A[i1++];
        B[N/2+i] = A[i1++];
      }
    }
    for (long i = 0; i < N-1; i++) {
      a2 += abs(B[i] - B[i+1]);
    }
  }
  cout << max(a1, a2) << endl;
}