#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<ll> A;
ll R;

ll solve() {
  for (ll i = 0; i < N; ++i) {
    R += A[i] / (N + 1);
    A[i] %= N + 1;
  }
  ll a_max = 0;
  for (ll i = 0; i < N; ++i) {
    A[i] += R;
    a_max = max(a_max, A[i]);
  }
  if (a_max >= 2 * N - 1) {
    ll k = a_max - (2 * N - 1);
    R += k * N;
    for (ll i = 0; i < N; ++i) A[i] -= k;
  }
  while (true) {
    auto it = max_element(A.begin(), A.end());
    if (*it <= N - 1) return R;
    ++R;
    *it -= N + 1;
    for (auto &a : A) ++a;
  }
}
int main() {
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; ++i) cin >> A[i];
  cout << solve() << endl;
  return 0;
}
