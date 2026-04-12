// Copyright lzt
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
#include<ctime>
using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<long long, long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, j, k)  for (register int i = (int)(j); i <= (int)(k); i++)
#define rrep(i, j, k) for (register int i = (int)(j); i >= (int)(k); i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)

inline ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * f;
}

const int maxn = 200200;
int n, m;
int l[maxn], r[maxn], a[maxn];
ll sum[maxn];
vector<int> vec[maxn];

#define lc (i << 1)
#define rc (i << 1 | 1)
struct Node {
  int l, r;
  ll val, tag;
} tr[maxn << 2];

void build(int i, int l, int r) {
  tr[i].l = l; tr[i].r = r;
  if (tr[i].l == tr[i].r) return;
  int md = (l + r) >> 1;
  build(lc, l, md); build(rc, md + 1, r);
}
void pushdown(int i) {
  if (!tr[i].tag) return;
  tr[lc].val += tr[i].tag;
  tr[rc].val += tr[i].tag;
  tr[lc].tag += tr[i].tag;
  tr[rc].tag += tr[i].tag;
  tr[i].tag = 0;
}
void add(int i, int l, int r, ll v) {
  if (tr[i].l >= l && tr[i].r <= r) {
    tr[i].val += v; tr[i].tag += v;
    return;
  }
  if (tr[i].l > r || tr[i].r < l) return;
  pushdown(i);
  add(lc, l, r, v); add(rc, l, r, v);
  tr[i].val = max(tr[lc].val, tr[rc].val);
}
ll ask(int i, int l, int r) {
  if (tr[i].l >= l && tr[i].r <= r) return tr[i].val;
  if (tr[i].l > r || tr[i].r < l) return -1e18;
  pushdown(i);
  return max(ask(lc, l, r), ask(rc, l, r));
}

void work() {
  n = read(), m = read();
  rep(i, 1, m) {
    l[i] = read(), r[i] = read();
    a[i] = read(); sum[l[i]] += a[i]; vec[r[i]].pb(i);
  }
  build(1, 0, n);
  ll ans = 0;
  rep(i, 1, n) {
    add(1, 0, i - 1, sum[i]);
    ll nw = ask(1, 0, i - 1);
    ans = max(ans, nw);
    add(1, i, i, nw);
    rep(j, 0, vec[i].size() - 1) {
      int x = vec[i][j];
      add(1, 0, l[x] - 1, -a[x]);
    }
  }
  printf("%lld\n", ans);
}

int main() {
  #ifdef LZT
    freopen("in", "r", stdin);
  #endif

  work();

  #ifdef LZT
    Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
  #endif
}
