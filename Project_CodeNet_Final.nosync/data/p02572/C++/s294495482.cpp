#include <bits/stdc++.h>
using namespace std;

const int MOD = pow(10, 9) + 7;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  vector<long long> S(N + 1, 0);

  for (int i = 0; i < A.size(); i++) {
    cin >> A[i];
    S[i + 1] = S[i] + A[i];
  }

  long answer = 0;

  for (int i = 0; i < A.size() - 1; i++) {
    long long sum = (S[N] - S[i + 1]) % MOD;
    answer += A[i] * sum;
    answer %= MOD;
  }

  cout << answer << endl;
}
