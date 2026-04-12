#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
  if (!v.empty()) {
    out << '[';
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}
template <class T, class U>
void chmin(T& t, U f) {
  if (t > f) t = f;
}
template <class T, class U>
void chmax(T& t, U f) {
  if (t < f) t = f;
}

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) {}
  UnionFind(const UnionFind& u) { data = u.data; }
  bool unionSet(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

int N;
vector<int> x, y;
map<pair<int, int>, vector<pair<int, int>>> m;

void hoge(int i, int j) {
  //-2x(x2-x1)-2y(y2-y1)+()+()
  ll a = -2 * (x[j] - x[i]);
  ll b = -2 * (y[j] - y[i]);
  ll c = (x[j] * x[j] - x[i] * x[i]) + (y[j] * y[j] - y[i] * y[i]);
  for (int k = 0; k < N; ++k) {
    for (int l = k + 1; l < N; ++l) {
      if (abs(a * x[l] + b * y[l] + c) == abs(a * x[k] + b * y[k] + c) &&
          (x[k] - x[l]) * (y[i] - y[j]) == (y[k] - y[l]) * (x[i] - x[j])) {
        m[{i, j}].push_back({k, l});
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  x.resize(N), y.resize(N);
  for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      hoge(i, j);
    }
  }

  UnionFind start(N);
  vector<pair<UnionFind, int>> dp;
  dp.push_back({start, 0});
  int mi = N;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      vector<pair<UnionFind, int>> v;
      for (auto& p : dp) {
        if (p.first.findSet(i, j)) continue;
        UnionFind next(p.first);
        for (auto& q : m[{i, j}]) {
          next.unionSet(q.first, q.second);
        }
        for (int k = 1; k < N; ++k) {
          if (!next.findSet(0, k)) {
            v.push_back({next, p.second + 1});
            break;
          }
          if (k == N - 1) chmin(mi, p.second + 1);
        }
      }
      for (auto& q : v) {
        dp.push_back(q);
      }
    }
  }
  cout << mi << endl;
}