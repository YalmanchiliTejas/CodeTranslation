#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MOD = 1e9 + 7;

int mod_inv(int a, int m) {
  int b = m, u = 1, v = 0;
  while (b) {
    int t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int sum = 0;
  int d_sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
    d_sum += A[i] * A[i] % MOD;
    sum %= MOD;
    d_sum %= MOD;
  }

  int ans = ((sum * sum) % MOD - d_sum + MOD) % MOD;
  ans = ans * mod_inv(2, MOD) % MOD;

  cout << ans << endl;
  return 0;
}