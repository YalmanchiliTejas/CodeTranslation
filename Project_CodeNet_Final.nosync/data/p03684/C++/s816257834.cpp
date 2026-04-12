#include <cmath>
#include <cstdio>
#include <limits>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>
#include <array>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for (int i = n-1; i >= 0; --i)
#define REP(i, s, n) for (int i = s; i< (int)(n); ++i)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

class Node {
 public:
  ll cost;
  ll to, from;
  bool operator<(const Node &node) const noexcept{
    return this->cost < node.cost;
  };
};

// Union Find begin

class UnionFind {
 private:
  vector<ll> _par;
  vector<ll> _rank;
 public:
  explicit UnionFind(ll n);
  ll find(ll x);
  void unite(ll x, ll y);
  bool isSame(ll x, ll y);
};

UnionFind::UnionFind(ll n) {
  for (ll i = 0; i < n; ++i) {
    _par.push_back(i);
    _rank.push_back(0);
  }
}

ll UnionFind::find(ll x) {
  if (_par.at(static_cast<unsigned long>(x)) == x) return x;
  else return _par.at(static_cast<unsigned long>(x)) = find(_par.at(static_cast<unsigned long>(x)));
}

void UnionFind::unite(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (_rank.at(static_cast<unsigned long>(x)) < _rank.at(static_cast<unsigned long>(y)))
    _par.at(static_cast<unsigned long>(x)) = y;
  else {
    _par.at(static_cast<unsigned long>(y)) = x;
    if (_rank.at(static_cast<unsigned long>(x)) == _rank.at(static_cast<unsigned long>(y)))
      ++_rank.at(static_cast<unsigned long>(x));
  }

}

bool UnionFind::isSame(ll x, ll y) {
  return find(x) == find(y);
}

// Union Find end

int main() {
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<pair<ll, ll>> px(n), py(n);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    px.at(i).first = x;
    px.at(i).second = i;
    py.at(i).first = y;
    py.at(i).second = i;
  }
  sort(all(px));
  sort(all(py));

  vector<Node> nodes;
  rep(i, n - 1) {
    ll cost = abs(px.at(i).first - px.at(i + 1).first);
    Node node;
    node.cost = cost;
    node.from = px.at(i).second;
    node.to = px.at(i + 1).second;
    nodes.push_back(node);
  }
  rep(i, n - 1) {
    ll cost = abs(py.at(i).first - py.at(i + 1).first);
    Node node;
    node.cost = cost;
    node.from = py.at(i).second;
    node.to = py.at(i + 1).second;
    nodes.push_back(node);
  }
  sort(all(nodes));
  UnionFind unf(n);
  ll ans = 0;
  for (const auto &node : nodes) {
    if (not unf.isSame(node.from, node.to)) {
      unf.unite(node.from, node.to);
      ans += node.cost;
    }
  }

  cout << ans << endl;

  return 0;
}
