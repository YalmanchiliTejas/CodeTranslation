#include<bits/stdc++.h>
using namespace std;

class UnionFind {
 public:
  int find(int x) {return (p_[x] == x) ? x : find(p_[x]);}
  void unite(int a, int b) {p_[find(b)] = find(a);}
  int make() {p_.push_back(p_.size()); return p_.size() - 1;}
 private:
  vector<int> p_;
};

// [left, right)
struct Node {
  int id, left, right;
  Node(int x) : id(2e9), left(x), right(2e9) {}
  Node(int i, int l, int r) : id(i), left(l), right(r) {}
  bool operator<(const Node& n) const {
    if(left != n.left) return left < n.left;
    if(right != n.right) return right < n.right;
    return id < n.id;
  }
};

class SegmentTree {
 public:
  SegmentTree(int n) : size_(1) {
    while(size_ < n) size_ <<= 1;
    root_ = make_unique<Node>();
  }
  void add(int a, int b, int v) {add(a, b + 1, v, root_, 0, size_);}
  int find(int x) {return find(x, root_, 0, size_);}
 private:
  struct Node {
    int value;
    int lazy;
    unique_ptr<Node> l_child, r_child;
  };
  inline void push(const unique_ptr<Node>& n) {
    if(not n->l_child) n->l_child = make_unique<Node>();
    if(not n->r_child) n->r_child = make_unique<Node>();
    if(n->lazy) {
      n->l_child->lazy += n->lazy;
      n->r_child->lazy += n->lazy;
      n->value += n->lazy;
      n->lazy = 0;
    }
  }
  void add(int a, int b, int v, const unique_ptr<Node>& n, int l, int r) {
    push(n);
    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {n->lazy = v; return;};
    auto m = (l + r) / 2;
    add(a, b, v, n->l_child, l, m);
    add(a, b, v, n->r_child, m, r);
  }
  int find(int x, const unique_ptr<Node>& n, int l, int r) {
    push(n);
    if(x == l && x == r - 1) return n->value;
    auto m = (l + r) / 2;
    if(x < m) return find(x, n->l_child, l, m);
    else      return find(x, n->r_child, m, r);
  }
  unique_ptr<Node> root_;
  int size_;
};

int main() {
  enum Type {Y_IN, X, Y_OUT};
  struct Event {int y; Type type; int left, right;};

  int W, H, N;
  cin >> W >> H >> N;

  list<Event> event;
  for(auto i = 0; i < N; ++i) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if(B == D) event.push_back({B, X, A, C});
    else {
      event.push_back({B, Y_IN,  A, C});
      event.push_back({D, Y_OUT, A, C});
    }
  }

  event.push_back({0, X, 0, W});
  event.push_back({0, Y_IN, 0, 0});
  event.push_back({0, Y_IN, W, W});
  event.push_back({H, Y_OUT, 0, 0});
  event.push_back({H, Y_OUT, W, W});
  event.push_back({H, X, 0, W});

  event.sort([](auto l, auto r) {
    if(l.y != r.y) return l.y < r.y;
    if(l.type != r.type) return l.type < r.type;
    if(l.left != r.left) return l.left < r.left;
    return l.right < r.right;
  });

  W += 3;
  for(auto& q: event) {++q.left; ++q.right;}

  SegmentTree flag(W);
  UnionFind group;
  set<Node> node;
  node.emplace(group.make(), 0, W);
  long long ans = 0;

  while(!event.empty()) {
//     for(auto i:node)cout<<i.id<<"("<<group.find(i.id)<<")"<<": "<<i.left<<" to "<<i.right<<endl;
//     for(auto i=0;i<W;++i)cout<<" "<<flag.find(i);cout<<endl;
//     cout<<ans<<endl;
//     cout<<endl;
    auto q = event.front();
    event.pop_front();
    if(q.type == Y_IN) {
//       cout<<"split: "<<q.y<<" "<<q.left<<" "<<q.right<<endl;
      auto n = node.upper_bound(q.left);
      --n;
      if(n->right == q.left) continue;
      auto f = flag.find(n->left);
      flag.add(n->left, n->right - 1, -f);
      auto i = f ? group.make() : n->id;
      auto j = group.make();
      ans += f;
      group.unite(i, j);
      node.emplace(i, n->left, q.left);
      node.emplace(j, q.left, n->right);
      node.erase(n);
    } else if(q.type == Y_OUT) {
//       cout<<"merge: "<<q.y<<" "<<q.left<<" "<<q.right<<endl;
      auto l = node.upper_bound(q.left);
      --l;
      if(q.left != l->left) continue;
      auto r = l--;
      auto fl = flag.find(l->left);
      auto fr = flag.find(r->left);
      flag.add(l->left, l->right - 1, -fl);
      flag.add(r->left, r->right - 1, -fr);
      auto i = fl ? group.make() : l->id;
      auto j = fr ? group.make() : r->id;
      ans += fl + fr - 1;
      if(group.find(i) == group.find(j)) ans += 1;
      group.unite(i, j);
      node.emplace(j, l->left, r->right);
      node.erase(l);
      node.erase(r);
    } else {
//       cout<<"separate: "<<q.y<<" "<<q.left<<" "<<q.right<<endl;
      auto l = node.upper_bound(q.left);
      auto r = node.upper_bound(q.right);
      --l;
      --r;
      if(l->left != q.left) ++l;
      if(r->right != q.right) --r;
      if(l == end(node)) continue;
      if(r->right <= l->left) continue;
      flag.add(l->left, r->right - 1, 1);
    }
  }
//   for(auto i:node)cout<<i.id<<"("<<group.find(i.id)<<")"<<": "<<i.left<<" to "<<i.right<<endl;
//   for(auto i=0;i<W;++i)cout<<" "<<flag.find(i);cout<<endl;
//   cout<<endl;

  cout << ans << endl;
}