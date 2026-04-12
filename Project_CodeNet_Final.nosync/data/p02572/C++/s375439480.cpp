#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;
 // constexpr int MOD = 998244353;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  auto cs = [&](auto V) {
    int n = V.size() + 1;
    vector<long> R(n);
    for (int i = 1; i < n; i++) {
      R.at(i) = R.at(i - 1) + V.at(i - 1);
    }
    return R;
  };

  auto R = cs(A);
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
