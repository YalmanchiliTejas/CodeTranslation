#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int64> xs(n);
  vector<int64> ys(n);

  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    cin >> ys[i];
  }

  auto solve_1_fn = [&]() -> int64 {
    vector<int64> rs;
    vector<int64> bs;
    for (int i = 0; i < n; i++) {
      if (xs[i] >= ys[i]) {
        rs.push_back(xs[i]);
        bs.push_back(ys[i]);
      } else {
        rs.push_back(ys[i]);
        bs.push_back(xs[i]);
      }
    }
    sort(rs.begin(), rs.end());
    sort(bs.begin(), bs.end());
    return (rs[n - 1] - rs[0]) * (bs[n - 1] - bs[0]);
  };

  auto solve_2_fn = [&]() -> int64 {
    vector<int64> zs;
    for (int64 x : xs) zs.push_back(x);
    for (int64 y : ys) zs.push_back(y);
    sort(zs.begin(), zs.end());
    int64 c1 = zs.back() - zs.front();

    vector<pair<int64, int64>> ps;
    for (int i = 0; i < n; i++) {
      ps.push_back(make_pair(min(xs[i], ys[i]), max(xs[i], ys[i])));
    }
    sort(ps.begin(), ps.end());
    
    set<pair<int64, int>> s;
    for (int i = 0; i < n; i++) {
      s.insert(make_pair(ps[i].first, i));
    }
    int64 c2 = s.rbegin()->first - s.begin()->first;
    for (int i = 0; i < n; i++) {
      s.erase(make_pair(ps[i].first, i));
      s.insert(make_pair(ps[i].second, i));
      UpdateMin(c2, s.rbegin()->first - s.begin()->first);
    }

    return c1 * c2;
  };

  int64 ans1 = solve_1_fn();
  int64 ans2 = solve_2_fn();
  if (DEBUG) cout << "ans1: " << ans1 << endl;
  if (DEBUG) cout << "ans2: " << ans2 << endl;
  int64 ans = min(ans1, ans2);
  cout << ans << endl;
}
