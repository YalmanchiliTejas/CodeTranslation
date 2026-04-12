#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

using namespace std;

using ll = long long;

ll solve(vector<ll> &va, vector<ll> &memo) {
  for (int i = 0; i < va.size(); ++i) {
    *upper_bound(memo.begin(), memo.end(), va[i]) = va[i];
  }

  auto r_it = lower_bound(memo.begin(), memo.end(), numeric_limits<ll>::max());
  return distance(memo.begin(), r_it);
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  reverse(va.begin(), va.end());

  vector<ll> memo(n + 1, numeric_limits<ll>::max());
  cout << solve(va, memo) << '\n';
  return 0;
}