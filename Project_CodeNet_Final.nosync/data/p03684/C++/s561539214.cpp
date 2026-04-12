#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "YES"; }
  string_type do_falsename() const { return "NO"; }
};

class UnionFind {
  vector<int> p;
public:
  UnionFind (int n) : p(n, -1) {}
  int root(int x) {
    return p[x] < 0 ? x : p[x] = root(p[x]);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (p[y] < p[x]) swap(x, y);
    if (p[x] == p[y]) --p[x];
    p[y] = x;
    return true;
  }
};

void solve(ll N, vector<ll> x, vector<ll> y) {
  vector<pair<int,int>> ex, ey;
  REP(i,N) ex.emplace_back(x[i], i);
  REP(i,N) ey.emplace_back(y[i], i);
  sort(ALL(ex)); sort(ALL(ey));
  vector<tuple<int,int,int>> es;
  REP(i,N-1) es.emplace_back(ex[i+1].first - ex[i].first, ex[i].second, ex[i+1].second);
  REP(i,N-1) es.emplace_back(ey[i+1].first - ey[i].first, ey[i].second, ey[i+1].second);
  sort(ALL(es));
  UnionFind uf(N);
  ll res = 0;
  for (auto t: es) {
    int c, a, b;
    tie(c, a, b) = t;
    if (!uf.same(a, b)) {
      res += c;
      uf.unite(a, b);
    }
  }
  cout << res << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll N;
	scanf("%lld", &N);
	vector<ll> x(N-1+1);
	vector<ll> y(N-1+1);
	for (int i = 0 ; i <= N-1 ; i++) {
	  scanf("%lld", &x[i]);
	  scanf("%lld", &y[i]);
	}
	solve(N, x, y);
	return 0;
}
