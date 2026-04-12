#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

using namespace std;

typedef long long int ll;
const int N = 2e5 + 10;
const ll oo = 1e18;

struct node {
  int l, r;
  node *left, *right;
  ll val, lazy;
  node(int L, int R) {
    val = lazy = 0;
    l = L, r = R;
    if(l == r) return;
    int m = (l + r) >> 1;
    left = new node(l, m);
    right = new node(m + 1, r);
  }
  void prop() {
    if(lazy == 0) return;
    val += lazy;
    left->lazy += lazy, right->lazy += lazy;
    lazy = 0;
  }
  ll get() { return val + lazy; }
  ll query_max(int L, int R) {
    if(R < l || L > r) return -oo;
    if(L <= l && r <= R) return get();
    prop();
    return max(left->query_max(L, R), right->query_max(L, R));
  }
  void update(int L, int R, ll x) {
    if(R < l || L > r) return;
    if(L <= l && r <= R) {
      lazy += x;
      return;
    }
    prop();
    left->update(L, R, x);
    right->update(L, R, x);
    val = max(left->get(), right->get());
  }
};

int n, m;
vector<pair<int, ll>> a[N];
node *st;

void solve() {
  cin >> n >> m;
  st = new node(0, n + 1);
  for(int i = 0; i < m; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    a[l].emplace_back(r, x);
    a[r + 1].emplace_back(l - 1, -x);
  }
  for(int i = 1; i <= n + 1; ++i) {
    for(auto &p : a[i]) {
      st->update(0, p.first, p.second);
    }
    ll cur = st->query_max(0, i);
    st->update(i, i, -(st->query_max(i, i))+cur);
  }
  cout << st->query_max(0, n) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(9);
  cout << fixed;
  solve();
  return 0;
}
