#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;

class UnionFind {
public:
  UnionFind(int n) :par_(vector<int>(n))
  {
    for (int i = 0; i < n; ++i) {
      par_[i] = i;
    }
  }

  int find(int x) {
    if (par_[x] == x) {
      return x;
    } else {
      return par_[x] = find(par_[x]);
    }
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    par_[y] = x;
  }
private:
  vector<int> par_;
};

const int inf = 1e9 + 9;

int n;
pair<llint, int> x[100010], y[100010];

typedef vector<pair<llint, pair<int, int>>> vecP;
llint solve() {
  sort(x, x+n);
  sort(y, y+n);

  vecP vec;
  for (int i = 0; i < n - 1; ++i) {
    vec.push_back(make_pair(x[i+1].first - x[i].first, make_pair(x[i+1].second, x[i].second)));
    vec.push_back(make_pair(y[i+1].first - y[i].first, make_pair(y[i+1].second, y[i].second)));
  }

  sort(vec.begin(), vec.end());
  UnionFind uf(n);
  llint ret = 0;
  for (int i = 0; i < vec.size(); ++i) {
    int a = vec[i].second.first;
    int b = vec[i].second.second;

    if (!uf.same(a, b)) {
      ret += vec[i].first;
      uf.unite(a, b);
    }
  }

  return ret;
}

void input() {
  cin >> n;
  int a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    x[i] = pair<llint, int>(a, i);
    y[i] = pair<llint, int>(b, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  cout << solve() << endl;

  return 0;
}