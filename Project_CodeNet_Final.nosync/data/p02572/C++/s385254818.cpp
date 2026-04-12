#include <iostream>

using namespace std;

int main() {
  const int MAX = 2e5;
  const long long MOD = 1e9 + 7;
  const long long MODINV = 500000004;

  int N; cin >> N;
  long long A[MAX];
  for (int i = 0; i < N; i++) cin >> A[i];

  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum = (sum + A[i]) % MOD;
  }

  long long sqr = (sum * sum) % MOD;

  long long mid = 0; 
  for (int i = 0; i < N; i++) {
    mid = mid + ((A[i] * A[i]) % MOD) % MOD;
  }

  long long top = (sqr - mid) % MOD;
  if (top < 0) top += MOD;

  long long ans = (top * MODINV) % MOD;

  cout << ans << endl;
}