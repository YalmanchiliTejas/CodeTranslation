#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> P(51), A(51);

ll solve(ll N, ll X) {
  if (N == 0)
    return (X <= 0 ? 0 : 1);
  else if (X <= A[N - 1] + 1)
    return solve(N - 1, X - 1);
  else
    return P[N - 1] + solve(N - 1, X - (A[N - 1] + 2)) + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, X;
  cin >> N >> X;
  P[0] = 1;
  A[0] = 1;
  for (int i = 1; i <= 50; i++) {
    P[i] = 2 * P[i - 1] + 1;
    A[i] = 2 * A[i - 1] + 3;
  }
  cout << solve(N, X) << '\n';
  return 0;
}
