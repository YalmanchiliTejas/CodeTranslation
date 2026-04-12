#include <bits/stdc++.h>

using namespace std;

string n;

vector<vector<int64_t>> cache;

int64_t calc(int len, int k) {
  if (k < 0)
    return 0;
  if (k == 0)
    return 1;
  auto& result = cache[len][k];
  if (!result) {
    int64_t res = 1;
    for (int64_t i = 0; i < k; ++i) {
      res *= (len - i);
    }
    for (int64_t i = 1; i <= k; ++i) {
      res /= i;
    }
    for (int i = 0; i < k; ++i) {
      res *= 9;
    }
    result = res;
  }
  // cout << " calc " << len << " " << k << " " << result << endl;
  return result;
}

int64_t entry_point(int idx, int k) {
  if (k == 0) {
    return 1;
  }
  if (idx == n.size()) {
    return 0;
  }
  assert(k > 0);
  assert(idx < n.size());
  auto m = n[idx] - '0';
  // cout << " idx k m " << idx << " " << k << " " << m << endl;
  assert(m != '0');
  auto len = n.size() - idx;
  auto res = calc(len - 1, k);
  // cout << " res A " << res << endl;
  res += (m - 1) * calc(len - 1, k - 1);
  // cout << " res B " << res << endl;
  for (int i = idx + 1; ; ++i) {
    if (i == n.size() || n[i] != '0') {
      return res + entry_point(i, k - 1);
    }
  }
}

void solve() {
  int k;
  cin >> n >> k;
  cache.resize(n.size() + 1, vector<int64_t>(k + 1));
  cout << entry_point(0, k) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  // cache.resize(100, vector<int64_t>(100));
  // cout << calc(2, 1) << endl;
}
