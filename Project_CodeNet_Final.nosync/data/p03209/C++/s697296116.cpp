#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, X;
vector<ll> zeros, ones;

ll dfs(ll p, int L) {
  if (L == 0) return ones[0];

  ll sum = zeros[L] + ones[L];
  if (p == 1) return 0;
  if (p == sum / 2 + 1) return ones[L] / 2 + 1;
  if (p == sum) return ones[L];

  if (p < sum / 2 + 1) {
    return dfs(p - 1, L - 1);
  } else {
    return ones[L] / 2 + 1 + dfs(p - sum / 2 - 1, L - 1);
  }
}

int main() {
  cin >> N >> X;
  zeros.resize(N + 1);
  ones.resize(N + 1);
  zeros[0] = 0;
  ones[0] = 1;
  for (int i = 1; i < N + 1; i++) {
    zeros[i] = zeros[i - 1] * 2 + 2;
    ones[i] = ones[i - 1] * 2 + 1;
  }
  cout << dfs(X, N) << endl;
  return 0;
}
