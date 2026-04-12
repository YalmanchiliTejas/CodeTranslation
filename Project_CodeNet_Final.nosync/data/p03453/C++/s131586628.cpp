//vl dijkstra(int start, int n, vvi adj, vvi cost){
//    vl dist(n,INF);
//    dist[start] = 0;
//    priority_queue<pll,vpll,greater<pll> > pq;
//    vb visited(n);
//    pq.push({0,start});
//    while(!pq.empty()){
//        int u = pq.top().Y;
//        pq.pop();
//        if(visited[u]) continue;
//        visited[u] = true;
//        rep(i,sz(adj[u])){
//            int v = adj[u][i];
//            int c = cost[u][i];
//            if(dist[v] > dist[u]+c){
//                dist[v] = dist[u]+c;
//                pq.push({dist[v],v});
//            }
//        }
//    }
//    return dist;
//}
//vl ways(int start, int n, vvi adj, vvi cost, vl dist){
//    vpll sorted;
//    rep(i,n)
//        sorted.pb({dist[i],i});
//    vl ways(n);
//    ways[start] = 1;
//    sort(all(sorted));
//    rep(t,sz(sorted)){
//        int u = sorted[t].Y;
//        rep(i,sz(adj[u])){
//            int v = adj[u][i];
//            int c = cost[u][i];
//            if(dist[v] == dist[u]+c){
//                ways[v] += ways[u];
//                if(ways[v] >= MOD) ways[v] -= MOD;
//            }
//        }
//    }
//    return ways;
//}
//void __(){
//    _(int,n);
//    _(int,m);
//    _(int,s);
//    _(int,t);
//    --s, --t;
//    vvi adj(n), cost(n);
//    vector<tuple<int,int,int> > edges;
//    rep(i,m){
//        _(int,u);
//        _(int,v);
//        _(int,w);
//        --u, --v;
//        edges.pb(make_tuple(u,v,w));
//        adj[u].pb(v);
//        cost[u].pb(w);
//        adj[v].pb(u);
//        cost[v].pb(w);
//    }
//    vl ds = dijkstra(s, n, adj, cost);
//    vl dt = dijkstra(t, n, adj, cost);
//    vl ws = ways(s, n, adj, cost, ds);
//    vl wt = ways(t, n, adj, cost, dt);
//    ll ans = ws[t]*wt[s]%MOD;
//    ll opt_dist = ds[t];
//    rep(i,n)
//        if(ds[i]+dt[i] == opt_dist){
//            if(ds[i] == dt[i])
//                ans -= ipow(ws[i]*wt[i]%MOD,2);
//        }
//    for(auto _ : edges){
//        int u,v,w;
//        tie(u,v,w) = _;
//        rep(times,2){
//            if(ds[u]+dt[v]+w == opt_dist){
//                if(abs(ds[u]-dt[v]) < w)
//                    ans -= ipow(ws[u]*wt[v]%MOD,2);
//            }
//            swap(u,v);
//        }
//    }
//    ans = (ans%MOD+MOD)%MOD;
//    print ans;
//}
//
#include <iomanip>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define pb push_back
#define REP_ZERO_INT(i,r) for(int i = 0; i < r; ++i)
#define GET_REP_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_REP_MACRO(__VA_ARGS__,REP_ANY,REP_INT,REP_ZERO_INT)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define sz(v) ll(v.size())
#define Y second
#define T1 template<typename T> static
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const ll INF = ll(2e18) + 666;
const ll MOD = 1e9 + 7;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
T1 istream& read(T, T, istream& = cin);
ll ipow(ll x, ll p, ll mod = MOD){
    if(abs(x) >= mod)
        x %= mod;
    if(x < 0)
        x += mod;
    if(p == 0)
        return 1;
    if(p == 1)
        return x;
    return ipow(x * x % mod, p / 2, mod) * ipow(x, p % 2, mod) % mod;
}
struct _print {
    string sep,end;
    bool space;
    ostream &stream;
    _print(string _sep=" ",string _end="\n",
            ostream &_stream = cout)
        : sep(_sep),end(_end),space(false),
            stream(_stream) {}
    ~_print() { stream << end; }
    template <typename T>
        _print &operator , (const T &t) {
            if (space) stream << sep;
            space = true;
            stream << t;
            return *this;
        }
};
#define print _print(),
#define INPUT_WITHOUT_INIT(type,name) type name; cin >> name
#define GET_INPUT_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define _(...) GET_INPUT_MACRO(__VA_ARGS__,_IWI,_IWI,_IWI,_IWI,_IWI,_IWI,INPUT_WITHOUT_INIT)(__VA_ARGS__)
vl dijkstra(int start, int n, vvi adj, vvi cost){
    vl dist(n,INF);
    dist[start] = 0;
    priority_queue<pll,vpll,greater<pll> > pq;
    vb visited(n);
    pq.push({0,start});
    while(!pq.empty()){
        int u = pq.top().Y;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        rep(i,sz(adj[u])){
            int v = adj[u][i];
            int c = cost[u][i];
            if(dist[v] > dist[u]+c){
                dist[v] = dist[u]+c;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
vl ways(int start, int n, vvi adj, vvi cost, vl dist){
    vpll sorted;
    rep(i,n)
        sorted.pb({dist[i],i});
    vl ways(n);
    ways[start] = 1;
    sort(all(sorted));
    rep(t,sz(sorted)){
        int u = sorted[t].Y;
        rep(i,sz(adj[u])){
            int v = adj[u][i];
            int c = cost[u][i];
            if(dist[v] == dist[u]+c){
                ways[v] += ways[u];
                if(ways[v] >= MOD) ways[v] -= MOD;
            }
        }
    }
    return ways;
}
void __(){
    _(int,n);
    _(int,m);
    _(int,s);
    _(int,t);
    --s, --t;
    vvi adj(n), cost(n);
    vector<tuple<int,int,int> > edges;
    rep(i,m){
        _(int,u);
        _(int,v);
        _(int,w);
        --u, --v;
        edges.pb(make_tuple(u,v,w));
        adj[u].pb(v);
        cost[u].pb(w);
        adj[v].pb(u);
        cost[v].pb(w);
    }
    vl ds = dijkstra(s, n, adj, cost);
    vl dt = dijkstra(t, n, adj, cost);
    vl ws = ways(s, n, adj, cost, ds);
    vl wt = ways(t, n, adj, cost, dt);
    ll ans = ws[t]*wt[s]%MOD;
    ll opt_dist = ds[t];
    rep(i,n)
        if(ds[i]+dt[i] == opt_dist){
            if(ds[i] == dt[i])
                ans -= ipow(ws[i]*wt[i]%MOD,2);
        }
    for(auto _ : edges){
        int u,v,w;
        tie(u,v,w) = _;
        rep(times,2){
            if(ds[u]+dt[v]+w == opt_dist){
                if(abs(ds[u]-dt[v]) < w)
                    ans -= ipow(ws[u]*wt[v]%MOD,2);
            }
            swap(u,v);
        }
    }
    ans = (ans%MOD+MOD)%MOD;
    print ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        __();
}
