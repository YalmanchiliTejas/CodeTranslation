#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1000000000+7;

int main() {
  long long N; cin >> N;
  vector<long long> A(N);
  vector<long long> s(N+1);
  for (long long i = 0; i < N; i++) cin >> A[i];
  s[0] = 0;
  for (long long i = 0; i < N; i++) {
    s[i+1] = (s[i]+A[N-1-i]) % MOD;
  }
  long long result = 0;
  for (long long i = 0; i < N-1; i++) {
    long long tmp = (A[i]*s[N-1-i]) % MOD;
    result = (result + tmp) % MOD;
  }
  cout << result << endl;
  return 0;
}