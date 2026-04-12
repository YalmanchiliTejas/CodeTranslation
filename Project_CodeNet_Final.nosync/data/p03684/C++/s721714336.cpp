#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
// #define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

struct UF{
    vector<int> par;
    vector<int> sz;
    UF(){}
    UF(int n){
        par.resize(n);
        sz.resize(n, 1);
        rep(i, 0, n) par[i] = i;
    }
    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

struct edge{
    int u, v, cost;
};

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}


signed main(){
    int n;
    cin >> n;
    vector<int> y, x;
    vector<P> dx, dy;  
    vector<edge> es;
    rep(i, 0, n){
        int ix, iy;
        cin >> ix >> iy;
        x. push_back(ix);
        y. push_back(iy);
        dx. push_back(P(ix, i));
        dy. push_back(P(iy, i));
    }
    sort(all(dx));
    sort(all(dy));
    rep(i, 0, n - 1){
        int now = dx[i].second;
        int next = dx[i + 1].second;
        int cost = min(abs(x[now] - x[next]), abs(y[now] - y[next]));
        es. push_back((edge){now, next, cost}); 
    }
    rep(i, 0, n - 1){
        int now = dy[i].second;
        int next = dy[i + 1].second;
        int cost = min(abs(x[now] - x[next]), abs(y[now] - y[next]));
        es. push_back((edge){now, next, cost}); 
    }
    sort(all(es), comp);
    UF uf(n);
    int ans = 0;
    rep(i, 0, es.size()){
        edge e = es[i];
        if(!uf.same(e.u, e.v)){
            uf.unite(e.u, e.v);
            ans += e.cost;
        }
    }
    cout << ans << endl;
}