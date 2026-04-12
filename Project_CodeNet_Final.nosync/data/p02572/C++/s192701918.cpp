#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  int64_t M = 1000000007LL;
  int64_t sum = 0;
  int64_t ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
    sum %= M;
  }
  for (int i = 0; i < N-1; i++) {
    sum -= A.at(i);
    if (sum < 0) sum += M;
    ans += A.at(i) * sum;
    ans %= M;
  }
  cout << ans % M << endl;
}