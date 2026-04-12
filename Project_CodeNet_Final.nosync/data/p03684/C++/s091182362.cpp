#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Edge {
  long long w;
  int a, b;
  bool operator<(Edge x) const {
    return make_pair(w, make_pair(a, b)) < make_pair(x.w, make_pair(x.a, x.b));
  }
};

int n;
int fa[N];
int x[N], y[N];
set < pair <int, int> > st, st2;
set <Edge> stx, sty;

/*
void print(Edge &e) {
  cout << "Edge " << e.w << " " << e.a << " " << e.b << endl;
}*/

int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void mrg(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    fa[x] = y;
  }
}

Edge get(set <Edge> &a) {
  auto it = a.begin();
  while (it != a.end()) {
    auto e = *it;
    if (find(e.a) != find(e.b)) {
      return e;
    }
    it = a.erase(it);
  }
  return Edge{-1, -1, -1};
}

Edge get(set < pair <int, int> > &st, pair <int, int> x) {
  auto it = st.lower_bound(x);
  if (it == st.begin()) {
    return Edge{-1, -1, -1};
  }
  auto itx = it--;
  itx++;
  if (itx == st.end()) {
    return Edge{-1, -1, -1};
  }
  Edge a;
  a.w = itx->first - it->first;
  a.a = itx->second;
  a.b = it->second;
  return a;
}

void go(int a) {
  Edge nx = get(st, make_pair(x[a], a));
  Edge ny = get(st2, make_pair(y[a], a));
  st.erase(make_pair(x[a], a));
  st2.erase(make_pair(y[a], a));
  if (nx.w != -1) {
    stx.insert(nx);
  }
  if (ny.w != -1) {
    sty.insert(ny);
  }
}

void erase(set <Edge> &a) {
  auto e = *a.begin();
  a.erase(a.begin());
  mrg(e.a, e.b);
  //go(e.a);
  //go(e.b);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x + i, y + i);
  }
  for (int i = 0; i < n; ++i) fa[i] = i;
  for (int i = 0; i < n; ++i) {
    st.insert(make_pair(x[i], i));
    st2.insert(make_pair(y[i], i));
  }
  pair <int, int> old(-1, -1);
  for (auto p : st) {
    if (old.first == -1) old = p;
    else {
      stx.insert(Edge{p.first - old.first, p.second, old.second});
      old = p;
    }
  }
  old = make_pair(-1, -1);
  for (auto p : st2) {
    if (old.first == -1) old = p;
    else {
      sty.insert(Edge{p.first - old.first, p.second, old.second});
      old = p;
    }
  }
  int sz = n - 1;
  long long ans = 0;
  while (sz--) {
    Edge e1 = get(stx);
    Edge e2 = get(sty);
    if (e1.w == -1) {
      erase(sty);
      //print(e1);
      ans += e2.w;
    } else if (e2.w == -1) {
      erase(stx);
      //print(e1);
      ans += e1.w;
    } else {
      if (e1.w < e2.w) {
	erase(stx);
	//print(e1);
	ans += e1.w;
      } else {
	erase(sty);
	ans += e2.w;
	//print(e2);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
