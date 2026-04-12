#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, MOD = 1e9+7;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  long ans = 0;
  for (long i = 0, sum = 0; i < N; i++) {
    (ans += sum * A.at(i) % MOD) %= MOD;
    (sum += A.at(i)) %= MOD;
  }
  cout << ans << "\n";
}