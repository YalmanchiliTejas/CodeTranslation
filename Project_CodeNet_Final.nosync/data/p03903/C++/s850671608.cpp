#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}


typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


class UnionFind {
public:
  int n;
  vi par; //親
  vi ran; //木の深さ
  vi num; //要素数

  UnionFind(int _n) {
    n = _n;
    par.resize(n); ran.resize(n); num.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; ran[i] = 0; num[i] = 1;
    }
  }

  //木の根を求める
  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = find(par[x]);
    }
  }

  //xとyの属する集合を併合
  void unite(int x, int y) {
    x = find(x); y = find(y);
    int numsum = num[x] + num[y];
    if (x == y) {
      return;
    }
    if (ran[x]<ran[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
      if (ran[x] == ran[y]) {
        ran[x]++;
      }
    }
    num[x] = num[y] = numsum;
  }

  //xとyが同じ集合に属するか否か
  bool same(int x, int y) {
    return find(x) == find(y);
  }

};

vector< pair<ll, pll> > edges;
const int N = 4010;
vector<vector<pll> > G(N), G2(N);
bitset<N> used;
vii max_c(N, vi(N));

ll kruskal(int n) {
  sort(edges.begin(), edges.end());
  UnionFind uf(n);
  ll res = 0;
  for (int i = 0; i < edges.size(); i++) {
    if (!uf.same(edges[i].second.first, edges[i].second.second)) {
      uf.unite(edges[i].second.first, edges[i].second.second);
      res += edges[i].first;
      int u = edges[i].second.first, v = edges[i].second.second;
      ll c = edges[i].first;
      G2[u].push_back(pll(c, v));
      G2[v].push_back(pll(c, u));
    }
  }
  return res;
}



void dfs(int s, int now, int ma) {
  used[now] = true;
  max_c[s][now] = ma;
  rep (i, G2[now].size()) {
    int v = G2[now][i].second;
    if (used[v]) continue;
    dfs(s, v, max(ma, (int)G2[now][i].first));
  }
}



int main() {
  int n, m;
  cin >> n >> m;
  rep (i, m) {
    ll u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    G[u].push_back(pll(c, v));
    G[v].push_back(pll(c, u));
    edges.push_back({c, pll(u, v)});
  }
  sort(all(edges));
  ll sum = kruskal(n);
  rep (i, n) {
    used.reset();
    dfs(i, i, 0);
  }
  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    s--; t--;
    cout << sum - max_c[s][t] << endl;
  }
}
