#include<bits/stdc++.h>
using namespace std;

class UnionFind {
 public:
  void unite(int a, int b) {p_[find(b)] = find(a);}
  int find(int x) {return p_[x] == x ? x : p_[x] = find(p_[x]);}
  int make() {p_.push_back(p_.size()); return p_.size() - 1;}
 private:
  vector<int> p_;
};

class SegmentTree {
 public:
  SegmentTree(int n) : size_(1) {
    while(size_ < n) size_ <<= 1;
    root_ = make_unique<Node>();
  }
  void add(int a, int b, int v) {add(a, b+1, v, root_, 0, size_);}
  int find(int x) {return find(x, root_, 0, size_);}
 private:
  struct Node {
    int v, lazy;
    unique_ptr<Node> l, r;
  };
  void push(const auto& n) {
    if(not n->l) n->l = make_unique<Node>();
    if(not n->r) n->r = make_unique<Node>();
    if(n->lazy) {
      n->l->lazy += n->lazy;
      n->r->lazy += n->lazy;
      n->v += n->lazy;
      n->lazy = 0;
    }
  }
  void add(int a, int b, int v, const auto& n, int l, int r) {
    push(n);
    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {n->lazy = v; return;}
    add(a, b, v, n->l, l, (l+r)/2);
    add(a, b, v, n->r, (l+r)/2, r);
  }
  int find(int x, const auto& n, int l, int r) {
    push(n);
    if(x==l && x+1==r) return n->v;
    auto m = (l+r)/2;
    if(x < m) find(x, n->l, l, m);
    else      find(x, n->r, m, r);
  }
  int size_;
  unique_ptr<Node> root_;
};

struct Node {
  int l, r, id;
  Node(int x) : l(x), r(2e9), id(2e9) {}
  Node(int l, int r, int id) : l(l), r(r), id(id) {}
  bool operator<(auto n) const {return make_tuple(l, r, id) < make_tuple(n.l, n.r, n.id);}
};

enum {Y_IN, X, Y_OUT};
struct Event {
  int y, type, l, r;
  bool operator<(auto e) {return make_tuple(y, type, l, r) < make_tuple(e.y, e.type, e.l, e.r);}
};

int main() {
  int W, H, N;
  cin >> W >> H >> N;

  vector<Event> event;
  for(auto i = 0; i < N; ++i) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if(B == D) event.push_back({B, X, A, C});
    else {
      event.push_back({B, Y_IN, A, C});
      event.push_back({D, Y_OUT, A, C});
    }
  }
  event.push_back({0, X, 0, W});
  event.push_back({H, X, 0, W});
  event.push_back({0, Y_IN, 0, 0});
  event.push_back({0, Y_IN, W, W});
  event.push_back({H, Y_OUT, 0, 0});
  event.push_back({H, Y_OUT, W, W});
  for(auto& i: event) {++i.l; ++i.r;}
  sort(begin(event), end(event));

  long long ans = 0;

  SegmentTree flag(W+3);
  UnionFind uf;
  set<Node> dp;
  dp.emplace(0, W+3, uf.make());
  for(auto q: event) {
    if(q.type == Y_IN) {
      auto n = --dp.upper_bound(q.l);
      auto f = flag.find(n->l);
      auto i = f ? uf.make() : n->id;
      auto j = uf.make();
      flag.add(n->l, n->r-1, -f);
      ans += f;
      uf.unite(i, j);
      dp.emplace(n->l, q.l, i);
      dp.emplace(q.l, n->r, j);
      dp.erase(n);
    } else if(q.type == X) {
      auto l = --dp.upper_bound(q.l);
      auto r = --dp.upper_bound(q.r);
      if(l->l != q.l) ++l;
      if(r->r != q.r) --r;
      flag.add(l->l, r->r-1, 1);
    } else {
      auto l = --dp.upper_bound(q.l);
      auto r = l--;
      auto fl = flag.find(l->l);
      auto fr = flag.find(r->l);
      auto i = fl ? uf.make() : l->id;
      auto j = fr ? uf.make() : r->id;
      flag.add(l->l, l->r-1, -fl);
      flag.add(r->l, r->r-1, -fr);
      ans += fl + fr - (uf.find(i)==uf.find(j) ? 0 : 1);
      uf.unite(i, j);
      dp.emplace(l->l, r->r, j);
      dp.erase(l);
      dp.erase(r);
    }
  }

  cout << ans << endl;
}