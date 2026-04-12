#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  rep(i, N) { cin >> A[i]; }

  int64_t answer = 0;
  while (true) {
    bool ok = true;
    rep(i, N) {
      if (A[i] >= N) {
        ok = false;
        int64_t times = A[i] / N;
        answer += times;
        A[i] -= (N * times);
        rep(j, N) {
          if (i != j) A[j] += times;
        }
      }
    }
    if (ok) break;
  }
  cout << answer << endl;
  return 0;
}