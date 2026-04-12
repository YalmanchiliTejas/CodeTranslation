#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> P;

vector< vector<P> > G;

struct Union_Find {
    //各要素が属する集合の代表(根)を管理する
    //もし、要素xが根であればdata[x]は負の値を取り、-data[x]はxが属する集合の大きさに等しい
    vector<int> data;
    
    Union_Find(int size) : data(size, -1) {}
    bool Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        bool is_union = (x != y);
        if (is_union) {
            if (data[x] > data[y]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return is_union;
    }
    int Find(int x) {
        if (data[x] < 0) { //要素xが根である
            return x;
        } else {
            data[x] = Find(data[x]); //data[x]がxの属する集合の根でない場合、根になるよう更新される
            return data[x];
        }
    }
    bool same(int x, int y) {
        return Find(x) == Find(y);
    }
    int size(int x) {
        return -data[Find(x)];
    }
};

struct Edge {
    int u, v;
    ll cost;
    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
}; 

struct Graph {
    int n; //頂点数
    vector<Edge> es; //辺集合
    
    ll kruskal() {
        sort(es.begin(), es.end());
        Union_Find uf(n);
        ll min_cost = 0;
        for(int i = 0; i < (int)es.size(); i++) {
            Edge e = es[i];
            if (!uf.same(e.u, e.v)) {
                min_cost += e.cost;
                uf.Union(e.u, e.v);
                G[e.u].emplace_back(e.v, e.cost);
                G[e.v].emplace_back(e.u, e.cost);
            }
        }
        return min_cost;
    }
};

Graph input() {
   Graph g;
   int m;
   cin >> g.n >> m;
   g.es = vector<Edge>(m);
   for(int i = 0; i < m; i++) {
        cin >> g.es[i].u >> g.es[i].v >> g.es[i].cost;
        g.es[i].u--;
        g.es[i].v--;
   }
   return g;
}

void dfs(int cur, int par, vector<ll>& d) {
    for (P nex : G[cur]) {
        if (nex.first == par) continue;
        d[nex.first] = max(d[cur], nex.second);
        dfs(nex.first, cur, d);
    }
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	Graph g = input();
    G.resize(g.n);
    ll sum = g.kruskal();
    vector< vector<ll> > maxc(g.n, vector<ll>(g.n, 0));
    for (int i = 0; i < g.n; i++) {
        dfs(i, -1, maxc[i]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        cout << sum - maxc[s][t] << endl;
    }
	return 0;
}