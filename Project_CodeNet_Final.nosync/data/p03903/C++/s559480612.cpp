#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

struct edge{
    ll a, b, c;
    bool operator<(const edge &another) const{
        return (c < another.c);
    }
};

struct UnionFind{
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

ll ma[4040][4040];
vector<pll> G[4040];

void dfs(ll root, ll par, ll now, ll mx){
    if(ma[root][now] != -1) return;
    ma[root][now] = mx;
    REP(i, G[now].size()){
        ll next = G[now][i].first;
        ll cost = G[now][i].second;
        if(next == par) continue;
        dfs(root, now, next, max(mx, cost));
    }
    return;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<edge> edges(M);
    REP(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].c = c;
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(N);
    ll total_weight = 0;
    REP(i, M){
        edge e = edges[i];
        if(uf.merge(e.a, e.b)){
            G[e.a].push_back({e.b, e.c});
            G[e.b].push_back({e.a, e.c});
            total_weight += e.c;
        }
    }

    REP(i, 4040)REP(j, 4040){
        ma[i][j] = -1;
    }

    REP(i, N) dfs(i, -1, i, 0);

    ll Q;
    cin >> Q;
    while(Q--){
        ll S, T;
        cin >> S >> T;
        S--, T--;
        cout << total_weight - ma[S][T] << endl;
    }

    return 0;
}