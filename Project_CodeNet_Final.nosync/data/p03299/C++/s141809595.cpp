#include <stdio.h>
#include <vector>
using namespace std;

const int N = 100005, P = 1000000007;
int n, a[N], lg2[N], mn[N][17];

int power(int a, int x) {
  int ans = 1;
  for (; x; x >>= 1, a = 1LL * a * a % P)
    if (x & 1) ans = 1LL * ans * a % P;
  return ans;
}

int better(int i, int j) {
  return (a[i] < a[j] || (a[i] == a[j] && i < j)) ? i : j;
}
int query(int l, int r) {
  int x = lg2[r - l + 1];
  return better(mn[l][x], mn[r - (1 << x) + 1][x]);
}

struct node {
  int c0, c1, c2;
  node(int d0 = 0, int d1 = 0, int d2 = 0) {
    c0 = d0, c1 = d1, c2 = d2;
  }
};

node solve(int l, int r, int h) {
  int pos = query(l, r), mnv = a[pos];
  vector<int> v;
  for (;;) {
    v.push_back(pos);
    if (pos == r) break;
    int nxt_pos = query(pos + 1, r);
    if (a[nxt_pos] == a[pos])
      pos = nxt_pos;
    else
      break;
  }
  node res;
  if (v[0] != l) {
    res = solve(l, v[0] - 1, mnv);
    res.c1 = (res.c0 + res.c1) % P;
    res.c0 = res.c1;
    res.c2 = (2LL * res.c2 + res.c0 + res.c1) % P;
  } else
    res = node(1, 1, 0);
  for (int i = 1; i < (int)v.size(); ++i) {
    if (v[i - 1] + 1 < v[i]) {
      node tmp = solve(v[i - 1] + 1, v[i] - 1, mnv);
      tmp.c1 = (tmp.c0 + tmp.c1) % P;
      tmp.c0 = tmp.c1;
      if (v[i - 1] - l & 1)
        res = node(1LL * res.c0 * tmp.c0 % P, 1LL * res.c1 * tmp.c1 % P,
          (1LL * res.c0 * tmp.c1 + 1LL * res.c1 * tmp.c0 + (0LL + tmp.c0 + tmp.c1 + tmp.c2) * res.c2 + (0LL + res.c0 + res.c1) * tmp.c2) % P);
      else
        res = node(1LL * res.c0 * tmp.c1 % P, 1LL * res.c1 * tmp.c0 % P,
          (1LL * res.c0 * tmp.c0 + 1LL * res.c1 * tmp.c1 + (0LL + tmp.c0 + tmp.c1 + tmp.c2) * res.c2 + (0LL + res.c0 + res.c1) * tmp.c2) % P);
    }
    res.c2 = (2LL * res.c2 + res.c0 + res.c1) % P;
  }
  if (v.back() != r) {
    node tmp = solve(v.back() + 1, r, mnv);
    tmp.c1 = (tmp.c0 + tmp.c1) % P;
    tmp.c0 = tmp.c1;
    if (v.back() - l & 1)
      res = node(1LL * res.c0 * tmp.c0 % P, 1LL * res.c1 * tmp.c1 % P,
        (1LL * res.c0 * tmp.c1 + 1LL * res.c1 * tmp.c0 + (0LL + tmp.c0 + tmp.c1 + tmp.c2) * res.c2 + (0LL + res.c0 + res.c1) * tmp.c2) % P);
    else
      res = node(1LL * res.c0 * tmp.c1 % P, 1LL * res.c1 * tmp.c0 % P,
        (1LL * res.c0 * tmp.c0 + 1LL * res.c1 * tmp.c1 + (0LL + tmp.c0 + tmp.c1 + tmp.c2) * res.c2 + (0LL + res.c0 + res.c1) * tmp.c2) % P);
  }
  res = node(mnv == h + 1 ? res.c0 : 1LL * (res.c0 + res.c1) * power(2, mnv - h - 2) % P,
    mnv == h + 1 ? res.c1 : 1LL * (res.c0 + res.c1) * power(2, mnv - h - 2) % P, res.c2);
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    mn[i][0] = i;
  }
  for (int i = 2; i <= n; ++i)
    lg2[i] = lg2[i >> 1] + 1;
  for (int j = 1; 1 << j <= n; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      mn[i][j] = better(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
  node res = solve(1, n, 0);
  int ans = (0LL + res.c0 + res.c1 + res.c2) % P;
  printf("%d\n", ans);
  return 0;
}