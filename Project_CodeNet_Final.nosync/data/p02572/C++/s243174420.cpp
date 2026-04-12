#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;
 // constexpr int MOD = 998244353;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<long> R(N + 1);
  for (int i = 1; i < N + 1; i++) {
    R.at(i) = R.at(i - 1) + A.at(i - 1);
  }
  long ans = 0;
  for (int i = 0; i < N; i++) {
    long tmp = R.at(N) - R.at(i + 1);
    tmp %= MOD;
    tmp *= A.at(i);
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << "\n";
}