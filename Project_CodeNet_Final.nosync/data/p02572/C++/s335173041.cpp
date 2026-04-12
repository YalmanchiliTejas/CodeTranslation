#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long long int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
  long long int ans = 0LL;
  long long int MOD = int(pow(10,9)+7);
  long long int asum = accumulate(A.begin(), A.end(), 0LL);
  for (int i = 0; i < N-1; i++) {
      asum -= A[i];
      ans += A[i]*(asum%MOD) % MOD;
      ans = ans % MOD;
  }
  cout << ans << endl;
}