#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, x, n) for (int i = (x); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e8;
template<typename T> void cmax(T &a, T b) { a = max(a, b); }
template<typename T> void cmin(T &a, T b) { a = min(a, b); }

signed main() {
  int n, l, r;
  while (cin >> n >> l >> r) {
    if (n == 0 && l == 0 && r == 0) break;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    loop(i, l, r + 1) {
      bool flag = true;
      rep(j, n) {
        if (i % a[j] == 0) {
          if ((j + 1) % 2 == 1) ans++;
          flag = false;
          break;
        }
      }
      if (flag && n % 2 == 0) ans++;
    }
    cout << ans << endl;
  }

  return 0;
}

