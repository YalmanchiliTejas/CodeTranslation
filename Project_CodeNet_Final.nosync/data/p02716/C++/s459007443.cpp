#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll neg_max = pow(10, 9) * pow(10, 5) * -5;

ll solve(vector<ll> &va, int skip, array<vector<optional<ll>>, 3> &memo,
         int offset = 0) {
  if (offset >= va.size()) {
    return va.size() % 2 == 0 || skip < 2 ? 0 : neg_max;
  }

  if (!memo[skip][offset].has_value()) {
    ll ans = solve(va, skip, memo, offset + 2) + va[offset];
    if (skip > 0) {
      ans = max(ans, solve(va, skip - 1, memo, offset + 1));
    }

    memo[skip][offset] = ans;
  }

  return memo[skip][offset].value();
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  array<vector<optional<ll>>, 3> memo;
  fill(memo.begin(), memo.end(), vector<optional<ll>>(va.size() + 1));

  if (va.size() % 2 == 0) {
    cout << solve(va, 1, memo) << '\n';
  } else {
    cout << solve(va, 2, memo) << '\n';
  }

  return 0;
}