#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) cin >> a;
  reverse(A.begin(), A.end());
  const int inf = 1e9 + 5;
  vector<int> lis(N, inf);
  for (int i = 0; i < N; i++) {
    *upper_bound(lis.begin(), lis.end(), A[i]) = A[i];
  }
  int ans = lower_bound(lis.begin(), lis.end(), inf) - lis.begin();
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
