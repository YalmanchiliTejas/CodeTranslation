#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int maxA = 0;
  for (int i = 0; i < N; i++) maxA = max(A[i], maxA);
  int ans;
  for (ans = 1; ans < maxA; ans++) {
    int work = 0;
    for (int i = 0; i < N; i++) {
      work += A[i];
      work -= ans;

      if (work < 0) {
        ans--;
        break;
      }
    }

    if (work < 0) break;
  }

  cout << ans << endl;
}
