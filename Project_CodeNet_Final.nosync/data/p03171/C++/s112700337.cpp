#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int maxn = 3005;
vector<vector<pair<long long, int>>> dp;

pair<long long, int> f(int left, int right, const vector<int> &v) {
  if (left > right) {
    return {0, 0};
  }

  if (left == right) {
    return {v[left], 0};
  }

  if (dp[left][right] == make_pair(-1LL, -1)) {
    auto a = f(left + 1, right, v);
    auto b = f(left, right - 1, v);

    long long score_a = v[left] + (a.second == 0 ? (f(left + 2, right, v)).first : (f(left + 1, right - 1, v)).first);
    long long score_b = v[right] + (b.second == 0 ? (f(left + 1, right - 1, v)).first : (f(left, right - 2, v)).first);

    if ((score_a - a.first) >= (score_b - b.first)) {
      dp[left][right] = {score_a, 0};
    } else {
      dp[left][right] = {score_b, 1};
    }
  }

  return dp[left][right];
}

int main() { IO;
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  dp.resize(maxn);
  for (auto &v : dp) {
    v.resize(maxn);
    fill(v.begin(), v.end(), make_pair(-1LL, -1));
  }

  auto score = f(0, n - 1, v);
  long long ans = score.first - (score.second == 0 ? (f(1, n - 1, v)).first : (f(0, n - 2, v)).first);
  cout << ans << endl;

  return 0;
}
