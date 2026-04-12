#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
//#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

const ll inf = 1LL << 63;

struct edge {int to; ll cost; bool use;};
struct node {int pos; ll cost;};
bool operator < (const node &a, const node &b){
    return a.cost > b.cost;
}

vector<ll> dijkstra(vector<vector<edge>> &G, int root){
    vector<ll> ret(G.size(), inf);
    priority_queue<node> pq;
    pq.push({root, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        
        if (ret[t.pos] == inf) ret[t.pos] = t.cost;
        else continue;
        
        for (edge e : G[t.pos]) {
            pq.push({e.to, t.cost + e.cost});
        }
    }
    return ret;
}


vector<ll> C1, C2, D1, D2;

void dfs1(vector<vector<edge>> &G, vector<ll> &D, int cur, int par = -1) {
    for(edge &e: G[cur]){
        if(D[e.to] < D[cur] && e.to != par){
            if(D[cur] - D[e.to] == e.cost) {
                e.use = true;
                dfs1(G, D, e.to, cur);
            }
        }
    }
}


ll dfs(vector<vector<edge>> &G, vector<ll> &C, vector<ll> &D, int cur, int par = -1) {
    ll ret = 0;
    if(C[cur] >= 0) return C[cur];
    for(edge e: G[cur]){
        if(D[e.to] + e.cost == D[cur]) {
            (ret += dfs(G, C, D, e.to, cur)) %= mod;
        }
    }
    return C[cur] = ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--, T--;
    vector<vector<edge>> G(N);
    rep(i, M){
        int u, v;
        ll d;
        cin >> u >> v >> d;
        d *= 2;
        u--, v--;
        G[u].pb({v, d, false});
        G[v].pb({u, d, false});
    }
    
    
    
    D1 = dijkstra(G, S);
    D2 = dijkstra(G, T);
    ll dist = D1[T];
    ll meet = dist / 2;
    
    
    C1.assign(N, -1);
    C1[S] = 1;
    dfs(G, C1, D1, T);
    C2.assign(N, -1);
    C2[T] = 1;
    dfs(G, C2, D2, S);
    
    vector<ll> tak, aok;
    rep(i, N){
        if(D1[i] == meet && D2[i] == meet){
            tak.pb(C1[i]), aok.pb(C2[i]);
        }
    }
    
    rep(i, N){
        for(edge e: G[i]){
            if(D1[i] < meet && D2[e.to] < meet && D1[i] + D2[e.to] + e.cost == dist){
                tak.pb(C1[i]);
                aok.pb(C2[e.to]);
            }
        }
    }
    
    ll ans = C1[T] * C1[T] % mod;
    rep(i, tak.size()){
        ll sub = tak[i] * aok[i] % mod;
        (ans -= sub * sub) %= mod;
    }
    (ans += mod) %= mod;
    output(ans);
    
    return 0;
}
