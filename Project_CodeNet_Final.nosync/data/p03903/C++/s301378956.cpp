#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)












class unionfind {
private:
    vector<int> par;
    vector<int> rank;
    vector<int> counter;
public:
    unionfind(int n) : rank(n), counter(n, 1){
        for(int i = 0; i < n; i++){
            par.push_back(i);
        }
    }
    
    int find(int x){
        if (par[x] == x) {
            return x;
        }
        else {
            return par[x] = find(par[x]);
        }
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return;
        
        if (rank[x] < rank[y]) {
            counter[y] += counter[x];
            counter[x] = counter[y];
            par[x] = y;
        }
        else {
            counter[y] += counter[x];
            counter[x] = counter[y];
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
    
    ll count(int x){
        return counter[find(x)];
    }
};


template <typename T>
class kruskal {
private:
    struct edge{
        T cost;
        int u, v;
        
        bool operator<(const edge& e1) const {
            return cost < e1.cost;
        }
    };
    vector<edge> es;
    int n;
public:
    kruskal(int n) : n(n){}
    
    void add_edge(int u, int v, T cost){
        es.push_back({cost, u, v});
        es.push_back({cost, v, u});
    }
    
    pair<vector<pair<pair<ll, ll>, ll>>, T> run(){
        sort(es.begin(), es.end());
    
        unionfind uni(n);
        T res = 0;
        vector<pair<pair<ll, ll>, ll>> edges;
        
        for(auto& e : es){
            if(!uni.same(e.u, e.v)){
                uni.unite(e.u, e.v);
                res += e.cost;
                edges.push_back({{e.u, e.v}, e.cost});
            }
        }
        
        return {edges, res};
    }
};

class LCA {
    ll n, log_n;
    vector<vector<pair<ll, ll>>> parent;
    vector<ll> depth;
    vector<bool> used;
    
private:
    void dfs(const vector<vector<pair<ll, ll>>> &g, ll now, ll par, ll d, ll cost){
        parent[0][now].first = par;
        parent[0][now].second = cost;
        depth[now] = d;
        used[now] = true;
        
        for(auto &edge : g[now]){
            ll child = edge.first, c = edge.second;
            if(child != par){
                dfs(g, child, now, d + 1, c);
            }
        }
    }
    
public:
    LCA(const vector<vector<pair<ll, ll>>> &g) : n(g.size()), log_n(0), depth(n), used(n) {
        for(ll v = n; v > 0; v /= 2){
            log_n++;
        }
        parent.resize(log_n, vector<pair<ll, ll>>(n));
        for(ll i = 0; i < n; i++){
            if(!used[i]){
                dfs(g, i, -1, 0, 0);
            }
        }
        for(ll k = 0; k < log_n - 1; k++){
            for(ll v = 0; v < n; v++){
                if(parent[k][v].first < 0){
                    parent[k + 1][v] = parent[k][v];
                }
                else{
                    parent[k + 1][v].first = parent[k][parent[k][v].first].first;
                    parent[k + 1][v].second = max(parent[k][v].second, parent[k][parent[k][v].first].second);
                }
            }
        }
    }
    
    ll query(ll u, ll v){
        if(depth[u] > depth[v]){
            swap(u, v);
        }
        ll res = 0;
        for(ll k = 0; k < log_n; k++){
            if(((depth[v] - depth[u]) >> k) & 1){
                res = max(res, parent[k][v].second);
                v = parent[k][v].first;
            }
        }
        if(u == v){
            return res;
        }
        for(ll k = log_n - 1; k >= 0; k--){
            if(parent[k][u] != parent[k][v]){
                res = max(res, parent[k][u].second);
                res = max(res, parent[k][v].second);
                u = parent[k][u].first;
                v = parent[k][v].first;
            }
        }
        return res;
    }
};








int main(){
    ll n, m;
    cin >> n >> m;
    kruskal<ll> krus(n);
    REP(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        krus.add_edge(a, b, c);
    }
    
    auto tmp = krus.run();
    auto e = tmp.first;
    ll cost = tmp.second;
    vector<vector<pair<ll, ll>>> g(n);
    REP(i, e.size()){
        ll a = e[i].first.first, b = e[i].first.second, c = e[i].second;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    LCA lca(g);
    ll q;
    cin >> q;
    REP(i, q){
        ll s, t;
        cin >> s >> t;
        s--; t--;
        cout << cost - lca.query(s, t) << endl;
    }
}