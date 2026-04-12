#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  size_t N;
  cin >> N;
  long long M = (1000000000 + 7);
  vector<long long> A(N), B(N);
  for (size_t i = 0; i < N; i++) cin >> A[i];
  B[N - 1] = A[N - 1];
  for (size_t i = 1; i < N; i++) {
    B[N - i - 1] = (A[N - i - 1] + B[N - i]) % M;
  }

  long long sum = 0;
  for (size_t i = 0; i + 1 < N; i++) {
    sum += (A[i] * B[i + 1]) % M;
    sum = sum % M;
  }

  cout << sum << endl;
  return 0;
}