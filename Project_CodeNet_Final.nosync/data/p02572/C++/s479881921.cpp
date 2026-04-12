#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N, MOD = 1000000007;
  cin >> N;
  vector<long long int> A(N);
  for (long long int i = 0; i < N; i++) cin >> A.at(i);
  long long int S1 = 0, S2 = 0;
  for (long long int i = 0; i < N; i++) {
    S1 = (S1 + A.at(i)) % MOD;
    S2 = (S2 + ((A.at(i) * A.at(i)) % MOD)) % MOD;
  }
  S1 = (S1 * S1) % MOD;
  long long int ans = (S1 - S2) % MOD;
  if (ans < 0) ans += MOD;
  long long int inv2 = MOD - (MOD / 2) % MOD;
  ans = (inv2 * ans) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
}