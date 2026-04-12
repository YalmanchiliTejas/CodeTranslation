#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

const int N = 200005;
const long long inf = (long long) 1e18;

int n, m;
long long st[4 * N];
long long lazy[4 * N];
vector < pair <int, int> > op[N], cl[N];

int left(int x) {
  return (x << 1);
}

int right(int x) {
  return (x << 1) + 1;
}

void update(int p, int L, int R, int i, int j, long long val) {
  if (lazy[p]) {
    st[p] += lazy[p];
    if (L != R) {
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  if (L > j || R < i) return;
  if (i <= L && R <= j) {
    st[p] += val;
    if (L != R) {
      lazy[left(p)] += val;
      lazy[right(p)] += val;
    }
    return;
  }
  int mid = (L + R) >> 1;
  update(left(p), L, mid, i, j, val);
  update(right(p), mid + 1, R, i, j, val);
  st[p] = max(st[left(p)], st[right(p)]);
}

long long query(int p, int L, int R, int i, int j) {
  if (i > j) return 0;
  if (lazy[p]) {
    st[p] += lazy[p];
    if (L != R) {
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  if (L > j || R < i) return -inf;
  if (i <= L && R <= j) {
    return st[p];
  }
  int mid = (L + R) >> 1;
  return max(query(left(p), L, mid, i, j), query(right(p), mid + 1, R, i, j));
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    op[x].push_back({x - 1, a});
    cl[y].push_back({x - 1, -a});
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto it : op[i]) {
      update(1, 0, n, 0, it.first, it.second);
    }
    long long x = query(1, 0, n, 0, i - 1);
    ans = max(ans, x);
    update(1, 0, n, i, i, x);
    for (auto it : cl[i]) {
      update(1, 0, n, 0, it.first, it.second);
    }
  }
  cout << ans << endl;
  return 0;
}
