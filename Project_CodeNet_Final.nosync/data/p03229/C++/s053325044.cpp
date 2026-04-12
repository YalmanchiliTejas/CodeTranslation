/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int64_t result = 0;
  if (N % 2 == 0) {
    int64_t i = 0;
    for (int64_t j = 0; j < (N - 2) / 2; ++j) {
      result -= A[i++] * 2;
    }
    result -= A[i++];
    result += A[i++];
    for (int64_t j = 0; j < (N - 2) / 2; ++j) {
      result += A[i++] * 2;
    }
  } else {
    int64_t result_1 = 0;
    {
      int64_t i = 0;
      for (int64_t j = 0; j < (N - 3) / 2; ++j) {
        result_1 -= A[i++] * 2;
      }
      result_1 -= A[i++];
      result_1 -= A[i++];
      for (int64_t j = 0; j < (N - 1) / 2; ++j) {
        result_1 += A[i++] * 2;
      }
    }

    int64_t result_2 = 0;
    {
      int64_t i = 0;
      for (int64_t j = 0; j < (N - 1) / 2; ++j) {
        result_2 -= A[i++] * 2;
      }
      result_2 += A[i++];
      result_2 += A[i++];
      for (int64_t j = 0; j < (N - 3) / 2; ++j) {
        result_2 += A[i++] * 2;
      }
    }
    result = max(result_1, result_2);
  }

  cout << result << endl;
  return 0;
}
