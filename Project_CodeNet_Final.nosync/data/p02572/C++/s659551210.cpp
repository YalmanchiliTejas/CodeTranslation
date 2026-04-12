#include <bits/stdc++.h>
#define REP(i,  n) for (int i  =  0; i < (int)(n); ++i)
#define FOR(i, j, n) for (int i  =  j; i < (int)(n); ++i)
#define REPR(i,  n) for (int i  =  n - 1; i >= 0; --i)
using namespace std;
#define int long long int
constexpr int MOD = 1e9 + 7;
//------------ATCODER TEMPLATE-------------

signed main() {
  int N; cin >> N;
  vector<int> A(N), S(N + 1);
  REP(i, N) cin >> A[i];

  S[N] = 0;
  for (int i = N - 1; i >= 0; --i) {
    S[i] = S[i + 1] + A[i];
    S[i] %= MOD;
  }

  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += A[i] * S[i + 1];
    sum %= MOD;
  }
  cout << sum << endl;
  return 0;
}
