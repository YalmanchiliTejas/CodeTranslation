#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  sort(A.begin(), A.end());
  long long res = 0;
  res += abs(A[0] - A[N - 1]) + abs(A[0] - A[N - 2]);
  for (int i = 1; i < N / 2; i++) {
    res += abs(A[i] - A[N - i]);
    if ((N - 1) / 2 < N - i - 2) {
      res += abs(A[i] - A[N - i - 2]);
    }
  }
  if (N % 2 && 3 < N) {
    res += max(A[N / 2 + 1] - A[N / 2], A[N / 2] - A[N / 2 - 1]);
  }

  if(N == 3){
    res = max(res, A[N-1] - A[0] + A[N - 1] - A[1]);
  }

  cout << res << endl;

  return 0;
}