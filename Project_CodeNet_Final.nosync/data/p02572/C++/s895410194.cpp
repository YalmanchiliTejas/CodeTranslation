#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  int64_t sum = 0;
  int64_t answer = 0;
  for (int i = N - 1; i >= 0; i--) {
    answer = (answer + sum * A[i] % MOD) % MOD;
    sum = (sum + A[i]) % MOD;
  }
  cout << answer << endl;
  return 0;
}
