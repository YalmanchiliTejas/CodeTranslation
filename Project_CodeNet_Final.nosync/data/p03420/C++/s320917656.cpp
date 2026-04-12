#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int64_t N, K;
  cin >> N >> K;

  if(K == 0) {
    int64_t answer = N * (N - K);
    cout << answer << endl;
    return 0;
  }

  int64_t answer = 0;
  for (int64_t b = K + 1; b <= N; ++b) {
    // N = pb + q;
    // p = N / b;
    int64_t a_num = (b - K) * (N / b);
    // q = N - pb -> N -> K ~ q
    a_num += max(0L, N - (N / b) * b - K + 1);
    answer += a_num;
  }
  cout << answer << endl;
  return 0;
}