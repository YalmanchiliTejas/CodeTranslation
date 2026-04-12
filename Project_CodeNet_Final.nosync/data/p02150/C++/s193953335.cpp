#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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
const int INF = 1e18;
template<typename T> void cmax(T &a, T b) { a = max(a, b); }
template<typename T> void cmin(T &a, T b) { a = min(a, b); }

signed main() {
  int a, b, x;
  cin >> a >> b >> x;

  if (a > x) {
    cout << x % MOD << endl;
    return 0;
  }
  int m = (x - a) / (a - b) + 1;
  cout << (int)((x + (b % MOD) * (m % MOD)) % MOD) << endl;
  return 0;
}

