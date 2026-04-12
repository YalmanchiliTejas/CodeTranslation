#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
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
const int INF = 1e9;
template<typename T> void cmax(T &a, T b) { a = max(a, b); }
template<typename T> void cmin(T &a, T b) { a = min(a, b); }

int n, x;
vector<int> a, p;

int f(int N, int X) {
  if (X <= 0) return 0;
  if (X >= a[N]) return p[N];
  int ans = 0;
  ans += f(N - 1, X - 1);
  if (X > a[N - 1] + 1) ans++;
  ans += f(N - 1, X - a[N - 1] - 2);

  return ans;
}

signed main() {
  int n, x;
  cin >> n >> x;
  a.resize(n + 1);
  p.resize(n + 1);
  a[0] = 1;
  p[0] = 1;
  loop(i, 1, n + 1) {
    a[i] = a[i - 1] * 2 + 3;
    p[i] = p[i - 1] * 2 + 1;
  }
  cout << f(n, x) << endl;

  return 0;
}
