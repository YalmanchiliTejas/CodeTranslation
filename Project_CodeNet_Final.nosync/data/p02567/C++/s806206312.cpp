#include <atcoder/all>

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using namespace atcoder;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  using T = int;
  auto f = [](T a, T b) {
    return T(max(a, b));
  };

  // identify element
  auto e = []() {
    return T(-1e9);
  };

  segtree<int, f, e> sg(a);

  for (int i = 0; i < q; i++) {
    int t; cin >> t;
    if (t == 1) {
      int x, v; cin >> x >> v;
      x--;
      sg.set(x, v);
    }
    if (t == 2) {
      int l, r; cin >> l >> r;
      l--;
      r--;
      cout << sg.prod(l, r + 1) << endl;
    }
    if (t == 3) {
      int x, v; cin >> x >> v;
      x--;
      auto find = [&](int val) {
        return bool((val < v));
      };

      cout << sg.max_right(x, find) + 1 << endl;
    }
  }

  return 0;
}
