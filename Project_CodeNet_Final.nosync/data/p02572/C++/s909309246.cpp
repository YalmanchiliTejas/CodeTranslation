#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  vector<long long> S(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long sum = (S[n] - S[i+1]) % MOD;
    ans += A[i] * sum;
    ans %= MOD;
    //cout << "---- i == " << i << " ----\n";
    //cout << "A[i] == " << A[i] << "\n";
    //cout << "S[n] - S[i+1] == " << S[n] - S[i+1] << "\n";
    //cout << "to be added:" << A[i] * (S[n] - S[i]) << "\n";
    //cout << "ans:" << ans << "\n";
  }

  cout << ans << "\n";
}