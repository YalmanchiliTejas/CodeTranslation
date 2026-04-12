#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(_v) for(auto _x:_v){cout<<_x<<" ";}cout<<endl
#define printVS(_vs) for(auto _x : _vs){cout << _x << endl;}
#define printVV(_vv) for(auto _v:_vv){for(auto _x:_v){cout<<_x<<" ";}cout<<endl;} cout << endl;
#define printP(_p) cout << _p.first << " " << _p.second << endl
#define printVP(_vp) for(auto _p : _vp) printP(_p);

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
const int inf = 1e9;
const int mod = 1e9 + 7;

class UnionFind {
private:
    const int n;
    vector<int> uni;
public:
    UnionFind(int _n) : n(_n), uni(_n, -1) {}
    int root(int x) {
        if (uni[x] < 0) return x;
        return uni[x] = root(uni[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (uni[x] > uni[y]) swap(x, y);
        uni[x] += uni[y];
        uni[y] = x;
        return true;
    }
    void print() {
        for (auto x : uni) cout << x << " ";
        cout << endl;
    }
};

struct edge {
    int from, to, cost;
    edge(){}
    edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}
    bool operator< (const edge& e) const {
        return cost == e.cost ? (from == e.from ? to < e.to : from < e.from) : cost < e.cost;
    }
};

class Kruskal {
private:
    int n;
    vector<edge> edges;
    UnionFind uf;
public:
    Kruskal(int _n) : n(_n), uf(_n) {}
    void addEdge(int _from, int _to, int _cost) {
        edges.emplace_back(_from, _to, _cost);
    }
    pair<int, vector<edge>> calc() {
        sort(all(edges));
        int res = 0;
        vector<edge> selected_edges;
        rep(i, edges.size()) {
            if (uf.unite(edges[i].from, edges[i].to)) {
                res += edges[i].cost;
                selected_edges.emplace_back(edges[i]);
            }
        }
        return make_pair(res, selected_edges);
    }
};

// a.cpp

int ma[4001][4001];
typedef vector<vector<Pii>> Graph; // Pii = {to, cost}

void dfs(const Graph& G, int s, int now, int pre, int ma_cost) {
    ma[s][now] = ma_cost;
    for (auto e : G[now]) {
        if (e.first == pre) continue;
        dfs(G, s, e.first, now, max(e.second, ma_cost));
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;
    Kruskal ks(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        ks.addEdge(a, b, c);
    }

    int cost;
    vector<edge> edges;
    tie(cost, edges) = ks.calc();

    Graph G(n);
    rep(i, edges.size()) {
        G[edges[i].from].emplace_back(edges[i].to, edges[i].cost);
        G[edges[i].to].emplace_back(edges[i].from, edges[i].cost);
    }

    rep(i, n) {
        dfs(G, i, i, -1, 0);
    }

    int Q;
    cin >> Q;
    rep(i, Q) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        cout << cost - ma[s][t] << endl;
    }


}
