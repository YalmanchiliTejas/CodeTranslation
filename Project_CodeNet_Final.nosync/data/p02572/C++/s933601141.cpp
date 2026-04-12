#include <iostream>
#include <vector>
using namespace std;
constexpr long long MOD = 1000000007;
long long N;
vector<long long> A;
int main() { 
  long long ans = 0;
  cin >> N;
  for(int i = 0; i < N; ++i) {
    long long a;
    cin >> a;
    A.push_back(a);
  }
  long long *A_sum = new long long[200001];
  A_sum[N] = 0;
  for (int i = N - 1; i >= 0; --i) {
    A_sum[i] = (A_sum[i + 1] + A[i]) % MOD;
  }
  for (int i = 0; i < N-1; ++i) {
    ans = (ans + (A[i] * A_sum[i+1]) % MOD ) % MOD;
  }
  cout << ans << endl;
}