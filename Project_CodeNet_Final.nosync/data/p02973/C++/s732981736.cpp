#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N; cin >> N;
  int A[100010], dp[100010];
  for(int i = 0; i < N; ++i) cin >> A[i];
  fill(dp, dp+N, 1);
  for(int i = 0; i < N; ++i) {
    *upper_bound(dp, dp+N, -A[i]) = -A[i];
  }
  std::cout << lower_bound(dp, dp+N, 1) - dp << std::endl;

  return 0;
}
