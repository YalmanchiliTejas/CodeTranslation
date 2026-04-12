#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int64_t i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N, X, M;
  cin >> N >> X >> M;

  unordered_map<int64_t, pair<int64_t, int64_t>> hist;
  int64_t answer = 0;
  int64_t A = X;
  rep(i, N) {
    if (hist.count(A)) {
      auto prev = hist[A];
      int64_t loop_size = i - prev.first;
      int64_t loop_sum = answer - prev.second;
      int64_t loop_cnt = (N - i) / loop_size;
      answer += loop_sum * loop_cnt;

      int64_t last = N - i - loop_cnt * loop_size;
      rep(j, last) {
        answer += A;
        A = (A * A) % M;
      }
      break;
    } else {
      hist[A] = {i, answer};
      answer += A;
      A = (A * A) % M;
    }
  }
  cout << answer << endl;
  return 0;
}
