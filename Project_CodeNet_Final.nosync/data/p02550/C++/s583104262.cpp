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

  int64_t N, X, M;
  cin >> N >> X >> M;
  vector<int64_t> order(M, -1);
  int64_t a = X;
  int64_t index = 0;
  int64_t P = 0, Q = 0;
  vector<int64_t> sequences;
  while (true) {
    if (order[a] >= 0) {
      P = order[a];
      Q = index - P;
      break;
    } else {
      order[a] = index;
      sequences.emplace_back(a);
      a = (a * a) % M;
      index++;
    }
  }
  int64_t cycle_sum = 0;
  for (int64_t i = P; i < P + Q; ++i) {
    cycle_sum += sequences[i];
  }

  int64_t result = 0;
  for (int64_t i = 0; i < min(P, N); ++i) {
    result += sequences[i];
  }

  result += ((N - P) / Q) * cycle_sum;
  int64_t residu = ((N - P) % Q) + P;
  for (int64_t i = P; i < residu; ++i) {
    result += sequences[i];
  }
  cout << result << endl;
  return 0;
}
