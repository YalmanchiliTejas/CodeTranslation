#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
struct Node {
  int val, size;
  Node *ls, *rs;
  Node(int _val, int _size, Node *_ls, Node *_rs) : val(_val), size(_size), ls(_ls), rs(_rs){}
  Node(){}
  inline void pushup() {
    if (!ls->size) return ;
    val = rs->val, size = ls->size + rs->size;
  }
}pool[MAXN<<1], *st[MAXN<<1], *root, *null; int cnt, a[MAXN];
inline Node *newNode(int val, int size, Node *ls, Node *rs) {
  return &(*st[cnt++] = Node(val, size, ls, rs));
}
Node *merge(Node *ls, Node *rs) {
  if (ls->size > rs->size * 4) 
    return ls->rs = merge(ls->rs, rs), ls->pushup(), ls;
  if (rs->size > ls->size * 4) 
    return rs->ls = merge(ls, rs->ls), rs->pushup(), rs;
  return newNode(rs->val, ls->size+rs->size, ls, rs);
}
Node *build(int l, int r) {
  if (l == r) return newNode(a[l], 1, null, null);
  int mid = l+r>>1;
  Node *cur = newNode(0, 0, build(l,mid), build(mid+1,r));
  return cur->pushup(), cur;
} 
inline void maintain(Node *cur) {
  Node *&ls = cur->ls, *&rs = cur->rs;
  if (ls->size > rs->size*4) 
    rs = merge(ls->rs, rs), st[--cnt] = ls, ls = ls->ls;
  if (rs->size > ls->size*4) 
    ls = merge(ls, rs->ls), st[--cnt] = rs, rs = rs->rs;
}

inline void insert(Node *cur, int x) {
  if (cur->size == 1) 
      cur->ls = newNode(min(x, cur->val), 1, null, null), 
      cur->rs = newNode(max(x, cur->val), 1, null, null);
  else insert(cur->ls->val >= x ? cur->ls : cur->rs, x);
  cur->pushup();
  maintain(cur);
}

inline void erase(Node *cur, Node *fa, int x) {
  if (cur->size == 1) *fa = fa->ls->val == x ? *fa->rs : *fa->ls;
  else erase(cur->ls->val >= x ? cur->ls : cur->rs, cur, x);
  cur->pushup();
}

inline int kth(Node *cur, int k) {
  if (cur->size == 1) return cur->val;
  return cur->ls->size>=k?kth(cur->ls, k) : kth(cur->rs, k-cur->ls->size);
}

inline int Rank(Node *cur, int x) {
  if (cur->size == 1) return x > cur->val;
  return cur->ls->val >= x ? Rank(cur->ls, x) : Rank(cur->rs, x) + cur->ls->size;
}

int main(void) {
  int n;
  scanf("%d",&n);
  for(int i = 0; i < (MAXN<<1); ++i) st[i] = &pool[i];  
  null = new Node(0, 0, 0, 0);
  root = newNode(2147483647, 1, null, null);
  for(int i = 1; i <= n; ++i) scanf("%d", a+i), insert(root, a[i]);
//  root = build(1, n);
	for(int i = 1; i <= n; ++i) {
		erase(root, null, a[i]);
		printf("%d\n", kth(root, n/2));
		insert(root, a[i]);
	}
  return 0;
}