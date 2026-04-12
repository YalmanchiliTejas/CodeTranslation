#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N, X;
  cin >> N >> X;
  vector<int64_t> BP(N + 1, 0);
  vector<int64_t> P(N + 1, 0);
  BP[0] = P[0] = 1;
  for (int i = 1; i <= N; ++i) {
    BP[i] = 2 * BP[i - 1] + 3;
    P[i] = 2 * P[i - 1] + 1;
  }

  int64_t answer = 0;
  while (true) {
    if (N == 0) {
      answer += (X <= 0) ? 0 : 1;
      break;
    }
    int64_t half = BP[N - 1] + 1;
    if (X <= half) {
      --X;
      --N;
    } else {
      answer += P[N - 1] + 1;
      X -= (BP[N - 1] + 2);
      --N;
    }
  }

  cout << answer << endl;
  return 0;
}
