#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long lint;

int main() {
  int N;
  cin >> N;
  vector<lint> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  lint ans = 0;
  while (1) {
    bool finish = true;
    for (int i = 0; i < N; i++) {
      if (A[i] >= N) {
        finish = false;
        lint cnt = A[i] / N;
        ans += cnt;
        A[i] -= cnt * N;
        for (int j = 0; j < N; j++) {
          if (i != j) {
            A[j] += cnt;
          }
        }
      }
    }
    if (finish) break;
  }
  cout << ans << endl;
  return 0;
}