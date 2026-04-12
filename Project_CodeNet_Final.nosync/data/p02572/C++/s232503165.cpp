#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, MOD = 1e9+7;
  cin >> N;
  vector<long> A(N);
  for (long i = 0; i < N; i++) cin >> A.at(i);
  vector<long> R(N + 1);
  for (long i = 1; i < N + 1; i++) R.at(i) = R.at(i - 1) + A.at(i - 1);
  long ans = 0;
  for (long i = 0; i + 1 < N; i++) {
    long X = A.at(i);
    long Y = R.at(N) - R.at(i + 1);
    Y %= MOD;
    X *= Y;
    X %= MOD;
    ans += X;
    ans %= MOD;
  }
  cout << ans << "\n";
}