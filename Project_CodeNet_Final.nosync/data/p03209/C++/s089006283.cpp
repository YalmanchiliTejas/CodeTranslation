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
template<typename T> void cmin(T &a, T b) { a = min(a, b); }
template<typename T> void cmax(T &a, T b) { a = max(a, b); }
int n, x;
int beef[100], sum[100];
int f(int l, int x) {
  int res = 0;
  if (x <= 0) return 0;
  if (x >= sum[l]) return beef[l];

  res += f(l - 1, x - 1);

  if (x > sum[l - 1] + 1) res++;
  res += f(l - 1, x - sum[l - 1] - 2);
  return res;
}

signed main() {
  cin >> n >> x;
  beef[0] = 1;
  sum[0] = 1;
  rep(i, n + 1) {
    beef[i + 1] = beef[i] * 2 + 1;
    sum[i + 1] = sum[i] * 2 + 3;
  }
  cout << f(n, x) << endl;
  return 0;
}
