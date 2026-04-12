#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

const long long MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  long long sum = 0;
  for (int i = 0; i < N; i++) { sum += A[i]; sum %= MOD; }

  long long ans = 0;
  for (int i = 0; i < N - 1; i++) {
    sum -= A[i];
    if (sum < 0) sum += MOD;
    sum %= MOD;
    ans += (A[i] * sum) % MOD;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
