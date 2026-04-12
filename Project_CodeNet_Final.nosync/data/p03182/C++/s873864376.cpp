#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

struct Node {
  int l, r;
  ll v, lazy;
  Node *ls, *rs;

  ll get() const { return v + lazy; }

  void upd() {
    v = max(ls->get(), rs->get());
  }

  void pd() {
    if (lazy) {
      v += lazy;
      ls->lazy += lazy;
      rs->lazy += lazy;
      lazy = 0;
    }
  }

  void ch(int l, int r, ll v) {
    if (this->l == l && this->r == r) {
      lazy += v;
      return;
    }
    pd();
    if (r <= ls->r)
      ls->ch(l, r, v);
    else if (l >= rs->l)
      rs->ch(l, r, v);
    else {
      ls->ch(l, ls->r, v);
      rs->ch(rs->l, r, v);
    }
    upd();
  }

  void*operator new(size_t) {
    static Node pool[N * 2];
    static Node* ptop = pool;
    return ptop++;
  }
};

int n;
vector<pair<int, int>> apply[N];

Node* build(int l, int r) {
  Node* p = new Node;
  p-> l = l;
  p->r =r ;
  if (l == r)
    return p;
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  return p;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int l, r, a;
    scanf("%d%d%d", &l, &r, &a);
    apply[r].emplace_back(l, a);
  }
  Node* seg = build(1, n);
  for (int i = 1; i <= n; ++i) {
    seg->ch(i, i, seg->get());
    for (const auto& pr : apply[i])
      seg->ch(pr.first, i, pr.second);
  }
  printf("%lld\n", max(seg->get(), 0LL));

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
