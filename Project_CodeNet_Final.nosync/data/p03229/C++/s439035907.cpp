#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());

  int64_t answer = 0;
  if (N % 2) {
    int l0 = 0;
    int r0 = N - 1;
    vector<int64_t> B(N);
    B[N / 2] = A[l0++];
    for (int i = 1; i <= N / 2; ++i) {
      B[N / 2 + i] = (i % 2) ? A[r0--] : A[l0++];
      B[N / 2 - i] = (i % 2) ? A[r0--] : A[l0++];
    }
    int64_t tmp_ansB = 0;
    rep(i, N - 1) { tmp_ansB += abs(B[i + 1] - B[i]); }
    answer = max(answer, tmp_ansB);

    int l1 = 0;
    int r1 = N - 1;
    vector<int64_t> C(N);
    C[N / 2] = A[r1--];
    for (int i = 1; i <= N / 2; ++i) {
      C[N / 2 + i] = (i % 2) ? A[l1++] : A[r1--];
      C[N / 2 - i] = (i % 2) ? A[l1++] : A[r1--];
    }
    int64_t tmp_ansC = 0;
    rep(i, N - 1) { tmp_ansC += abs(C[i + 1] - C[i]); }
    answer = max(answer, tmp_ansC);
  } else {
    int l0 = 0;
    int r0 = N - 1;
    vector<int64_t> D(N);
    for (int i = 0; i < N / 2; i++) {
      D[N / 2 - 1 - i] = (i % 2) ? A[l0++] : A[r0--];
      D[N / 2 + i] = (i % 2) ? A[r0--] : A[l0++];
    }
    int64_t tmp_ansD = 0;
    rep(i, N - 1) { tmp_ansD += abs(D[i + 1] - D[i]); }
    answer = max(answer, tmp_ansD);
  }
  cout << answer << endl;
  return 0;
}