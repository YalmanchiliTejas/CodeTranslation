#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>

using namespace std;
using lli = long long int;
// #define DEBUG
#ifdef DEBUG
#define debug(var) cout << (#var) << ": " << (var) << endl;
template<class T> void dump_array_impl(const T& a) {
  bool first = true;
  for (auto&& x : a) {
    if (!first) { cout << ", "; first = false; }
    cout << x;
  }
}
#define debug_array(a) cout<<(#a)<<": ";dump_array_impl(a);cout<<endl
#else
#define debug(var) {}
#define debug_array(a) {}
#endif
template<class T> void read_n(vector<T>& v, size_t n) {
  v = vector<T>(n);
  for (lli i=0; i<n; ++i) cin >> v[i];
}

int main() {
  lli h, w;
  cin >> h >> w;
  vector<string> v;
  read_n(v, h);
  auto e = remove_if(begin(v), end(v), [](auto& s) {
      return all_of(begin(s), end(s), [](auto c) { return c == '.'; });
  });
  h -= end(v) - e;
  vector<bool> b(w, true);
  for (lli j=0; j<h; ++j) {
    for (lli i=0; i<w; ++i) {
      if (v[j][i] != '.') b[i] = false;
    }
  }
  for (lli j=0; j<h; ++j) {
    lli i = 0;
    auto ee = remove_if(begin(v[j]), end(v[j]), [&](auto c) {
      return b[i++];
    });
    v[j].erase(ee, end(v[j]));
  }
  for (auto it=begin(v); it<e; ++it) cout << *it << endl;
  return 0;
}
