#include <iomanip>
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
  int64_t mod = 1e9 + 7;
  int64_t answer = 0;
  int64_t sum = A[0];
  for (int i = 1; i < N; ++i) {
    answer += (A[i] * sum) % mod;
    answer %= mod;
    sum = (sum + A[i]) % mod;
  }
  cout << answer << endl;
  return 0;
}
