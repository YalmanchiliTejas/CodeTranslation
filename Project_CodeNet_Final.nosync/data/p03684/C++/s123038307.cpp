#include <bits/stdc++.h>
#define int long long
#define ll long long 
#define rep(i,a,b) for(signed i=a;i<(b);++i)
#define erep(i,a,b) for(signed i=a;i<=(b);++i)
#define per(i,a,b) for(signed i=(a);i>(b);--i)
#define eper(i,a,b) for(signed i=(a);i>=b;--i)
#define fore(i, x, a) for(auto &&x:a) 
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define pb emplace_back
#define mp make_pair
#define ALL(x) begin(x),end(x)
#define F first
#define S second
#define debug(x)  cout << #x << ": " << (x) << '\n';
const long long INF=1001001001001001001;
const int MOD=(int)1e9 + 7;
const double EPS=1e-9;
using namespace std;
using Pii = pair<int,int>;
using vii = vector<int>;
template<class T>using  PS_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>using vv = vector<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){fill( (T*)array, (T*)(array+N), val );}
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T>T gcd(T a, T b){ return b ? gcd(b, a % b) : a; }
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct edge { int from, to, cost; };
int dy[]={0, 1, -1, 0}; int dx[]={1, 0, 0, -1};
// cout << fixed;
// cout << setprecision(10) << val;

template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 1, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
      x = root(x); y = root(y);
      if (x == y) return false;
      if (rank[x] < rank[y]) swap(x, y);
      rank[x] += rank[y];
      par[y] = x;
      return true;
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};
#define MAX_E 200005
edge es[MAX_E];

bool cmp(const edge& e1, const edge& e2) {
  return (e1.cost < e2.cost);
}

int kruskal(int V, int E) {
  sort(es, es + E, cmp);
  UnionFind<int> uf(V);
  int res = 0;
  rep(i, 0, E) {
    edge e = es[i];
    if (!uf.issame(e.from, e.to)) {
      uf.unite(e.from, e.to);
      res += e.cost;
    }
  }
  return res;
}

int N;

signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
  cin >> N;
  vv<Pii> x, y;
  rep(i, 0, MAX_E) es[i] = {0, 0, INF};
  rep(i, 0, N) {
    int a, b;
    cin >> a >> b;
    x.pb(a, i); y.pb(b, i);
  }
  sort(ALL(x)); sort(ALL(y));
  int k = 0;
  rep(i, 0, N-1) {
    edge ex = {x[i].S, x[i+1].S, abs(x[i].F - x[i+1].F)};
    edge ey = {y[i].S, y[i+1].S, abs(y[i].F - y[i+1].F)};
    es[k++] = ex;
    es[k++] = ey;
  }
  cout << kruskal(N, k) << endl;
  return 0;
}

