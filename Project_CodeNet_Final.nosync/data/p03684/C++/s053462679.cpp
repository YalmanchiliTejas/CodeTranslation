#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Does coordinate compression.
// Arguments:
// - raw_xs: Values to compress.
// Returns:
// - xs: Compressed values.
// - to_raw: A mapping from a compressed value to a raw value.
// Verified: CF573Div1D
tuple<vector<int>, vector<int>> Compress(const vector<int>& raw_xs) {
  unordered_set<int> raw_x_set(raw_xs.begin(), raw_xs.end());
  vector<int> to_raw(raw_x_set.begin(), raw_x_set.end());
  sort(to_raw.begin(), to_raw.end());
  unordered_map<int, int> to_index;
  for (int i = 0; i < to_raw.size(); i++) {
    to_index[to_raw[i]] = i;
  }
  vector<int> xs;
  for (int raw_x : raw_xs) {
    xs.push_back(to_index[raw_x]);
  }
  return make_tuple(xs, to_raw);
}

// Verified: AOJ-DSL1A
class UFSet {
 private:
  vector<int> ranks;
  vector<int> prevs;

 public:
  UFSet(int n) : ranks(n), prevs(n) {
    for (int i = 0; i < n; i++) prevs[i] = i;
  }

  // Returns a root of a tree which x belongs to.
  int Find(int x) {
    if (x != prevs[x]) prevs[x] = Find(prevs[x]);
    return prevs[x];
  }

  // Merges a set which x blongs to and a set which y belongs to.
  void Union(int x, int y) {
    int x_root = Find(x);
    int y_root = Find(y);
    if (ranks[x_root] > ranks[y_root]) {
      prevs[y_root] = prevs[x_root];
    } else if (ranks[x_root] < ranks[y_root]) {
      prevs[x_root] = prevs[y_root];
    } else if (prevs[x_root] != prevs[y_root]) {
      prevs[y_root] = prevs[x_root];
      ranks[x_root]++;
    }
  }
};

struct WEdge {
  int v1, v2;
  int64 weight;
  WEdge(int v1, int v2, int64 weight) : v1(v1), v2(v2), weight(weight) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> raw_xs(n), raw_ys(n);
  for (int i = 0; i < n; i++) {
    cin >> raw_xs[i];
    cin >> raw_ys[i];
  }

  vector<int> xs, xs_to_raw, ys, ys_to_raw;
  tie(xs, xs_to_raw) = Compress(raw_xs);
  tie(ys, ys_to_raw) = Compress(raw_ys);
  vector<vector<int>> x_to_ps(xs_to_raw.size()), y_to_ps(ys_to_raw.size());
  for (int i = 0; i < n; i++) {
    x_to_ps[xs[i]].push_back(i);
    y_to_ps[ys[i]].push_back(i);
  }

  UFSet uf_set(n);
  for (const auto& ps : x_to_ps) {
    for (int i = 1; i < ps.size(); i++) {
      uf_set.Union(ps[0], ps[i]);
    }
  }
  for (const auto& ps : y_to_ps) {
    for (int i = 1; i < ps.size(); i++) {
      uf_set.Union(ps[0], ps[i]);
    }
  }

  vector<WEdge> edges;
  for (int i = 0; i + 1< x_to_ps.size(); i++) {
    edges.push_back(WEdge(x_to_ps[i][0], x_to_ps[i + 1][0], xs_to_raw[i + 1] - xs_to_raw[i]));
  }
  for (int i = 0; i + 1< y_to_ps.size(); i++) {
    edges.push_back(WEdge(y_to_ps[i][0], y_to_ps[i + 1][0], ys_to_raw[i + 1] - ys_to_raw[i]));
  }
  sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
    return e1.weight < e2.weight;
  });

  int64 ans = 0;
  for (const auto& e : edges) {
    if (uf_set.Find(e.v1) == uf_set.Find(e.v2)) continue;
    ans += e.weight;
    uf_set.Union(e.v1, e.v2);
  }
  cout << ans << endl;
}