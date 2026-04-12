#include<bits/stdc++.h>
using namespace std;

struct Interval {
  int l;
  long long w;
  Interval(int l, long long w) : l(l), w(w) {}
  bool operator<(const Interval& oth) const { return l < oth.l; }
};


struct Seg {
  int l, m, r;
  Seg* ch[2] = {};
  long long ma = 0, tag = 0;
  void pull() {
    ma = max(ch[0]->ma, ch[1]->ma);
  }
  void push() {
    if (tag) {
      for (int i : {0, 1}) ch[i]->tag += tag, ch[i]->ma += tag;
      tag = 0;
    }
  }
  Seg(int l, int r) : l(l), r(r), m(l + r >> 1) {
    if (r - l > 1) {
      ch[0] = new Seg(l, m);
      ch[1] = new Seg(m, r);
    }
  }
  void add(int ql, int qr, long long v) {
    if (ql == qr) return;
    if (ql <= l and r <= qr) ma += v, tag += v;
    else {
      push();
      if (ql < m) ch[0]->add(ql, qr, v);
      if (m < qr) ch[1]->add(ql, qr, v);
      pull();
    }
  }
  long long query(int ql, int qr) {
    if (ql <= l and r <= qr) return ma;
    else {
      long long ans = 0;
      push();
      if (ql < m) ans = max(ans, ch[0]->query(ql, qr));
      if (m < qr) ans = max(ans, ch[1]->query(ql, qr));
      pull();
      return ans;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<vector<Interval>> lb(n + 1);
  for (int i = 0; i < m; ++i) {
    int l, r, w; cin >> l >> r >> w;
    lb[r].emplace_back(l - 1, w);
  }
  for (int i = 0; i <= n; ++i) sort(lb[i].begin(), lb[i].end());
  Seg dp(0, n + 1);
  for (int r = 1; r <= n; ++r) {
    dp.add(r, r + 1, dp.query(0, r));
    for (auto I : lb[r]) {
      dp.add(I.l + 1, r + 1, I.w);
    }
  }
  cout << dp.query(0, n + 1) << '\n';
}
