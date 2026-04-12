#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) cin >> xs[i];

  vector<vector<int64>> dp = Make2DVector<int64>(n + 1, n + 1, INT64_MIN);
  function<int64(int, int)> solve = [&](int s, int t) -> int64 {
    if (dp[s][t] != INT64_MIN) return dp[s][t];

    if (s == t) return 0;
    int64 max = INT64_MIN;
    if (xs[s] - solve(s + 1, t) > max) {
      max = xs[s] - solve(s + 1, t);
    }
    if (xs[t - 1] - solve(s, t - 1) > max) {
      max = xs[t - 1] - solve(s, t - 1);
    }
    dp[s][t] = max;
    return max;
  };
  cout << solve(0, n) << endl;
}
