#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1ll << 60;

ll solveRB(const vector<vector<ll>>& xy) {
  const int N = xy.size();
  ll rmax = 0, rmin = INF;
  ll bmax = 0, bmin = INF;
  for (int i = 0; i < N; i++) {
    rmax = max(rmax, xy[i][1]);
    rmin = min(rmin, xy[i][1]);
    bmax = max(bmax, xy[i][0]);
    bmin = min(bmin, xy[i][0]);
  }
  return (rmax - rmin) * (bmax - bmin);
}

ll solveRR(const vector<vector<ll>>& xy) {
  const int N = xy.size();
  ll rmax = 0, rmin = INF;
  for (int i = 0; i < N; i++) {
    rmin = min(rmin, xy[i][0]);
    rmax = max(rmax, xy[i][1]);
  }
  ll bmax = 0, bmin = INF;
  ll res = INF;
  for (int i = 0; i < N; i++) {
    bmax = max(bmax, xy[i][1]);
    bmin = min(bmin, xy[i][1]);
    if (i + 1 < N) {
      res = min(res, (rmax - rmin) *
                         (max(bmax, xy[N - 1][0]) - min(bmin, xy[i + 1][0])));
    }
  }
  res = min(res, (rmax - rmin) * (bmax - bmin));
  return res;
}

int main() {
  int N;
  while (cin >> N) {
    vector<vector<ll>> xy(N, vector<ll>(2));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 2; j++) {
        cin >> xy[i][j];
      }
      if (xy[i][0] > xy[i][1]) {
        swap(xy[i][0], xy[i][1]);
      }
    }
    sort(xy.begin(), xy.end(),
         [&](const vector<ll>& a, const vector<ll>& b) { return a[0] < b[0]; });
    cout << min(solveRB(xy), solveRR(xy)) << endl;
  }
  return 0;
}
