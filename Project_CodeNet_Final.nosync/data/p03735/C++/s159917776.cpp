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

void solve(ll N, vector<ll> x, vector<ll> y) {
  int minpos = 0, maxpos = 0;
  REP(i,N) {
    if (x[i] > y[i]) swap(x[i], y[i]);
    if (x[i] < x[minpos]) minpos = i;
    if (y[i] > y[maxpos]) maxpos = i;
  }
  ll red = *max_element(ALL(x));
  ll blue = *min_element(ALL(y));
  ll res = (red - x[minpos]) * (y[maxpos] - blue);
  if (minpos == maxpos) { cout << res << endl; return; }
  vector<pair<ll,int>> vec;
  REP(i,N) {
    if (i != minpos) vec.emplace_back(x[i], i);
    if (i != maxpos) vec.emplace_back(y[i], i);
  }
  sort(ALL(vec));
  ll min_dist = 1e18;
  int lb = 0, ub = 0;
  map<ll,int> mapsto;
  for (;;) {
    // cout << lb << " " << ub << endl;
    if (int(mapsto.size()) == N) {
      chmin(min_dist, vec[ub-1].first - vec[lb].first);
      mapsto[vec[lb].second] -= 1;
      if (mapsto[vec[lb].second] == 0) {
        auto it = mapsto.lower_bound(vec[lb].second);
        mapsto.erase(it);
      }
      ++lb;
    }
    else {
      if (ub == int(vec.size())) break;
      mapsto[vec[ub].second] += 1;
      ++ub;
    }
  }
  // cout << min_dist << endl;
  chmin(res, (y[maxpos] - x[minpos]) * min_dist);
  cout << res << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll N;
	scanf("%lld", &N);
	vector<ll> y(N-1+1);
	vector<ll> x(N-1+1);
	for (int i = 0 ; i <= N-1 ; i++) {
	  scanf("%lld", &x[i]);
	  scanf("%lld", &y[i]);
	}
	solve(N, x, y);
	return 0;
}
