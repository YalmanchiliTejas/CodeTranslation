#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll neg_max = pow(10, 9) * pow(10, 5) * -5;

ll solve(vector<ll> &va, int skip, array<vector<optional<ll>>, 3> &memo,
         int offset = 0) {
  if (offset >= va.size()) {
    if (va.size() % 2 == 0) {
      return 0;
    } else if (skip >= 2) {
      return neg_max;
    } else {
      return 0;
    }
  }

  if (!memo[skip][offset].has_value()) {
    if (skip > 0) {
      memo[skip][offset] = max(solve(va, skip, memo, offset + 2) + va[offset],
                               solve(va, skip - 1, memo, offset + 1));
    } else {
      memo[skip][offset] = solve(va, skip, memo, offset + 2) + va[offset];
    }
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