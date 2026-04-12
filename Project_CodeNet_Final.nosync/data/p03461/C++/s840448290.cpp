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
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

int c[128][128];
bool flag[128][128];

void solve(ll A, ll B, vector<vector<ll>> d) {
  REP(x,128) REP(y,128) {
    REP(i,A) REP(j,B) {
      chmax(c[x][y], int(d[i][j]) - x * (i + 1) - y * (j + 1));
    }
  }
  // REP(i,10) { REP(j,10) cout << c[i][j] << " "; cout << endl; }
  vector<tuple<int,int,int>> res;
  REP(s,120) REP(x,128) {
    int y = s - x;
    if (y < 0) continue;
    // if (x == 0 && y == 0)
    // cout << x << " " << y << endl;
    bool ok = false;
    REP(i,A) REP(j,B) {
      if (flag[i][j]) continue;
      if (c[x][y] == int(d[i][j]) - x * (i + 1) - y * (j + 1)) {
        ok = true;
        flag[i][j] = true;
      }
    }
    if (ok) {
      res.emplace_back(x, y, c[x][y]);
      // cout << x << " " << y << " " << c[x][y] << endl;
    }
  }
  bool ng = false;
  REP(i,A) REP(j,B) if (!flag[i][j]) ng = true;
  if (ng) cout << "Impossible" << endl;
  else {
    int V = 2;
    vector<tuple<int,int,string>> edge;
    for (auto t: res) {
      int x, y, cost;
      tie(x, y, cost) = t;
      int pv = 0;
      REP(i,x) {
        edge.emplace_back(pv, V, "X");
        pv = V; ++V;
      }
      REP(i,y) {
        edge.emplace_back(pv, V, "Y");
        pv = V; ++V;
      }
      edge.emplace_back(pv, 1, to_string(cost));
    }
    cout << "Possible" << endl;
    cout << V << " " << edge.size() << endl;
    for (auto e: edge) {
      int s, t; string c;
      tie(s, t, c) = e;
      cout << s + 1 << " " << t + 1 << " " << c << endl;
    }
    cout << 1 << " " << 2 << endl;
  }
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll B;
	ll A;
	scanf("%lld", &A);
	scanf("%lld", &B);
	vector<vector<ll>> d(A-1+1,vector<ll>(B-1+1));
	for (int i = 0 ; i <= A-1 ; i++) {
	  for (int j = 0 ; j <= B-1 ; j++) {
	    scanf("%lld", &d[i][j]);
	  }
	}
	solve(A, B, d);
	return 0;
}
