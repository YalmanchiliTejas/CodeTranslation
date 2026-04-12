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

struct Enclosure {
  ll l, r;
  ll len() const { return r - l; }
  Enclosure add(ll v) const { return {min(l, v), max(r, v)}; }
  bool containsLeft(ll L) const { return l <= L; }
  bool containsRight(ll R) const { return R <= r; }
  bool contains(ll L, ll R) const {
    return containsLeft(L) && containsRight(R);
  }
};

int main() {
  int N;
  while (cin >> N) {
    vector<vector<ll>> xy(N, vector<ll>(2));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 2; j++) {
        cin >> xy[i][j];
      }
    }
    vector<int> ind(2 * N);
    for (int i = 0; i < 2 * N; i++) ind[i] = i;
    sort(ind.begin(), ind.end(),
         [&](int a, int b) { return xy[a / 2][a % 2] < xy[b / 2][b % 2]; });
    vector<int> order;
    vector<bool> used(N, false);
    for (int i = 0; i < 2 * N; i++) {
      int j = i % 2 == 0 ? i / 2 : 2 * N - i / 2 - 1;
      int g = ind[j] / 2;
      if (!used[g]) {
        order.push_back(g);
        used[g] = true;
      }
    }
    vector<ll> mnmn(N + 1, INF), mnmx(N + 1, 0), mxmn(N + 1, INF),
        mxmx(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
      int j = order[i];
      auto p = minmax(xy[j][0], xy[j][1]);
      mnmn[i] = min(mnmn[i + 1], p.first);
      mnmx[i] = max(mnmx[i + 1], p.first);
      mxmn[i] = min(mxmn[i + 1], p.second);
      mxmx[i] = max(mxmx[i + 1], p.second);
    }
    function<ll(int, Enclosure, Enclosure)> dfs =
        [&](int i, const Enclosure& red, const Enclosure& blue) {
          if (i >= N) {
            return red.len() * blue.len();
          }
          ll limL = mnmn[i], limR = mxmx[i], bestR = mnmx[i], bestL = mxmn[i];
          if (red.contains(limL, limR) && blue.containsLeft(limL)) {
            return red.len() * blue.add(bestR).len();
          }
          if (red.contains(limL, limR) && blue.containsRight(limR)) {
            return red.len() * blue.add(bestL).len();
          }
          if (red.containsLeft(limL) && blue.contains(limL, limR)) {
            return red.add(bestR).len() * blue.len();
          }
          if (red.containsRight(limR) && blue.contains(limL, limR)) {
            return red.add(bestL).len() * blue.len();
          }
          int j = order[i];
          ll x = xy[j][0], y = xy[j][1];
          return min(dfs(i + 1, red.add(x), blue.add(y)),
                     dfs(i + 1, red.add(y), blue.add(x)));
        };
    cout << dfs(0, {INF, 0}, {INF, 0}) << endl;
  }
  return 0;
}
