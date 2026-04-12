#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Union_Find_Tree{
    vector<int> par, rank, num;
    
    Union_Find_Tree(int N){
        par.assign(N, -1);
        rank.assign(N, 0);
        num.assign(N, 1);
    }
    
    int root(int x){
        if(par[x] < 0 || par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        if(rank[x] == rank[y]) rank[x]++;
        par[y] = x, num[x] += num[y];
        return true;
    }
    
    int size(int x) {return num[root(x)];}
    
    bool same(int x, int y){
        return root(x) == root(y);
    }
    
    void clear(){
        fill(all(par), -1);
        fill(all(rank), 0);
        fill(all(num), 1);
    }
};

struct edge{int u, v, cost;};

int main(){
    int N;
    cin >> N;
    int x[N], y[N];
    rep(i, N) cin >> x[i] >> y[i];

    vector<int> xs(N), ys(N);
    iota(all(xs), 0), iota(all(ys), 0);
    sort(all(xs), [&](int a, int b){return x[a] < x[b];});
    sort(all(ys), [&](int a, int b){return y[a] < y[b];});

    vector<edge> es;
    rep(i, N-1) es.eb((edge){xs[i], xs[i+1], x[xs[i+1]]-x[xs[i]]});
    rep(i, N-1) es.eb((edge){ys[i], ys[i+1], y[ys[i+1]]-y[ys[i]]});
    sort(all(es), [](const edge &a, const edge &b){
        return a.cost < b.cost;
    });

    Union_Find_Tree uf(N);
    int ans = 0;
    for(auto &e: es){
        if(uf.unite(e.u, e.v)) ans += e.cost;
    }
    cout << ans << endl;
}