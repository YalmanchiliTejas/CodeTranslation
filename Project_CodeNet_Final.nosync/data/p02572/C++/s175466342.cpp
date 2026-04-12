#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) ((x).begin()), ((x).end())

#define READ(x) (cin >> (x))
#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))
#define WRITE_YESNO(x) (WRITE_N((x) ? "Yes" : "No"))

#define PRECISE_COUT std::cout << std::setprecision(15) << std::fixed

bool xor_logic(bool x, bool y) { return (x && y) || (!x && !y); }

#define DIVIDER 1000000007

ll solve(vector<ll> &A) {
  ll sum_mod = 0;
  for (auto &&x : A) {
    sum_mod = (sum_mod + x) % DIVIDER;
  }

  ll retv = 0;
  for (auto &&x : A) {
    sum_mod = (sum_mod + DIVIDER - x) % DIVIDER;
    retv = (retv + x * sum_mod) % DIVIDER;
  }

  return retv;
}

int main() {
  // get values from input
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  std::vector<ll> A(N, 0);
  for (size_t i = 0; i < N; i++) {
    cin >> A[i];
  }

  // main procedure
  ll ans = solve(A);

  // output
  cout << ans << endl;

  return 0;
}