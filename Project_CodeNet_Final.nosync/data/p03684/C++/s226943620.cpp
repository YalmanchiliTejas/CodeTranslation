//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

#define MAX_N 200000

class UnionFind {
private:
  // 親と木の深さ
  int par[MAX_N];
  int rank[MAX_N];
  int s[MAX_N];
public:
  void init(int n);
  int find(int x);
  void unite(int x, int y);
  bool same(int x, int y);
};

// 要素数nで初期化
void UnionFind::init (int n) {
  for(int i=0; i<n; i++) {
    par[i] = i;
    rank[i] = 0;
    s[i] = 1;
  }
}

// 要素xの親を求める
int UnionFind::find(int x) {
  if(par[x] == x) return x;
  else return par[x] = find(par[x]);
}

// xとyの属する集合を併合
void UnionFind::unite(int x, int y) {
  // xとyの親
  x = find(x);
  y = find(y);
  if(x == y) return;

  // yのほうが深さが深い　xの親はyの親
  if(rank[x] < rank[y]) {
    par[x] = y;
    s[y] = s[x] + s[y];
  }
  else {
    par[y] = x;
    s[x] = s[x] + s[y];
    if( rank[x] == rank[y] ) rank[x]++;
  }
}

// xとyが同じ集合に属するか
bool UnionFind::same(int x, int y) { return find(x) == find(y);}

UnionFind uf;
PII x[100010], y[100010];
struct edge{int u, v, cost;};
bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}
edge es[400010];
signed main(void)
{
  int n;
  cin >> n;
  REP(i, n) {
    int a, b;
    cin >> a >> b;
    x[i] = {a, i};
    y[i] = {b, i};
  }

  //辺を張る
  sort(x, x+n);
  sort(y, y+n);
  FOR(i, 1, n) {
    es[i-1] = (edge){x[i].second, x[i-1].second, abs(x[i].first - x[i-1].first)};
    es[n+i-1] = (edge){x[i-1].second, x[i].second, abs(x[i].first - x[i-1].first)};
  }
  FOR(i, 1, n) {
    es[2*n+i-2] = (edge){y[i].second, y[i-1].second, abs(y[i].first - y[i-1].first)};
    es[3*n+i-3] = (edge){y[i-1].second, y[i].second, abs(y[i].first - y[i-1].first)};
  }

  sort(es, es+n*4-4, comp);
  uf.init(n);
  int res = 0;
  REP(i, 4*n-4) {
    edge e = es[i];
    if(!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  cout << res << endl;
  return 0;
}
