#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;

const int N = 2e5 + 10;
vector<ii> a[N];
struct Node {
  int a, b;
  Node *left, *right;
  int64 maxv;
  int64 delta;
  void update(int64 C) {
    delta += C;
    maxv += C;
  }
  void pushdown() {
    if (!delta) return;
    left->update(delta);
    right->update(delta);
    delta = 0;
  }
  void pushup() {
    maxv = max(left->maxv, right->maxv);
  }
};
Node pool[N << 1], *last = pool;

Node* new_node(int a, int b) {
  Node* cur = last++;
  cur->a = a;
  cur->b = b;
  cur->maxv = cur->delta = 0;
  return cur;
}

Node* build(int a, int b) {
  Node* cur = new_node(a, b);
  if (a + 1 == b) return cur;
  cur->left = build(a, (a + b) / 2);
  cur->right = build((a + b) / 2, b);
  return cur;
}

int A, B;
int64 C;
void update(Node* cur) {
  if (cur->a >= A && cur->b <= B) {
    cur->update(C);
    return;
  }
  cur->pushdown();
  if ((cur->a + cur->b) / 2 > A) update(cur->left);
  if ((cur->a + cur->b) / 2 < B) update(cur->right);
  cur->pushup();
}

int64 query(Node* cur) {
  if (cur->a >= A && cur->b <= B) {
    return cur->maxv;
  }
  int64 ret = -(1LL << 60);
  cur->pushdown();
  if ((cur->a + cur->b) / 2 > A) ret = max(ret, query(cur->left));
  if ((cur->a + cur->b) / 2 < B) ret = max(ret, query(cur->right));
  return ret;
}

int64 dp[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int L, R, V;
    scanf("%d%d%d", &L, &R, &V);
    a[R].emplace_back(L, V);
  }
  Node* root = build(0, n + 2);
  for (int i = 1; i <= n + 1; ++i) {
    A = 0; B = i;
    dp[i] = query(root);
    A = i; B = A + 1; C = dp[i];
    update(root);
    for (auto& it : a[i]) {
      A = it.first; B = i + 1; C = it.second;
      update(root);
    }
    // trace(i, dp[i]);
  }
  A = 0; B = n + 1;
  int64 ret = query(root);
  printf("%lld\n", ret);
  return 0;
}
