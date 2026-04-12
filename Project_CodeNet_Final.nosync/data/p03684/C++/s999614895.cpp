#include<bits/stdc++.h>
#define x      first
#define y      second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;

struct data {
   int id; LL x, y;
   data() {}; data(int id, LL x, LL y) : id(id), x(x), y(y) {};
};
struct edge {
   int u, v; LL w;
   edge() {}; edge(int u, int v, LL w) : u(u), v(v), w(w) {};
};

bool cmpX(data a, data b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
bool cmpY(data a, data b) { return a.y < b.y || (a.y == b.y && a.x < b.x); }
bool cmp(edge a, edge b) { return a.w < b.w; }
LL dis(data a, data b) { return min(abs(a.x - b.x), abs(a.y - b.y)); }

const int N = 1e5 + 4;
int n, par[N];
data a[N];
vector<edge> E;

int root(int v) { return (par[v] < 0) ? v : (par[v] = root(par[v])); }

void kruskal() {
   sort(E.begin(), E.end(), cmp);
   for (int i = 1; i <= n; ++i) par[i] = -1;
   int Count = 0; LL ans = 0;

   for (int i = 0; i < E.size(); ++i) {
      if (Count == n-1) break;

      int u = E[i].u, v = E[i].v;
      if ((u = root(u)) == (v = root(v))) continue;

      if (par[u] > par[v]) swap(u, v);
      par[u] += par[v]; par[v] = u;

      ans += E[i].w; Count++;
   }

   cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   //freopen("nhap.inp", "r", stdin);
   //freopen("nhap.out", "w", stdout);

   cin >> n;
   LL x, y;
   for (int i = 1; i <= n; ++i) {
      cin >> x >> y;
      a[i] = data(i, x, y);
   }

   sort(a+1, a+n+1, cmpX);
   for (int i = 1; i < n; ++i) E.push_back(edge(a[i].id, a[i+1].id, dis(a[i], a[i+1])));

   sort(a+1, a+n+1, cmpY);
   for (int i = 1; i < n; ++i) E.push_back(edge(a[i].id, a[i+1].id, dis(a[i], a[i+1])));

   kruskal();

   return 0;
}
