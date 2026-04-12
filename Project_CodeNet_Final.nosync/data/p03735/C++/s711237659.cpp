#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 30;

int main() {
  int n;
  scanf("%d", &n);
  vector<ii> a(n);
  int minv = INF, maxv = -INF;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    minv = min(minv, a[i].first);
    maxv = max(maxv, a[i].second);
  }
  int L = -INF, R = INF;
  for (int i = 0; i < n; ++i) {
    L = max(L, a[i].first);
    R = min(R, a[i].second);
  }
  int64 ret = (int64)(L - minv) * (maxv - R);
  sort(a.begin(), a.end(), [](const ii& a, const ii& b) {
      return a.first < b.first;
    });
  int u = a[0].second, v = a[0].second;
  for (int i = 0; i < n; ++i) {
    u = min(u, a[i].second);
    v = max(v, a[i].second);
    if (i < n - 1) {
      L = min(u, a[i + 1].first);
      R = max(v, a[n - 1].first);
      ret = min(ret, (int64)(maxv - minv) * (R - L));
    } else {
      ret = min(ret, (int64)(maxv - minv) * (v - u));
    }
  }
  printf("%lld\n", ret);
  return 0;
}
