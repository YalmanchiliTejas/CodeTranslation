#include <bits/stdc++.h>
using namespace std;
 
#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)
 
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
 
#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()
 
typedef long long ll;
const int INF   = 1e9;
const ll  INFLL = 1e18;
typedef pair<ll, ll> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};
 
const int MOD = 1e9 + 7;
 
struct Edge{
    int from, to, cost;
    Edge(int f, int t, int c) : from(f), to(t), cost(c){}
    Edge(){}
};
typedef vector<vector<Edge>> Graph;
    
void dijkstra(int s, Graph G, vector<ll> &res, vector<ll> &dp)
{
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    
    res.assign(G.size(), INFLL);
    dp.assign(G.size(), 0);
 
    res[s] = 0;
    Q.emplace(0, s);
    dp[s] = 1;
    
    while (Q.size()) {
        PII p = Q.top(); Q.pop();
        int v = p.second;
        if (p.first > res[v]) continue;
 
        for (auto e : G[v]) {
            if (res[e.to] < res[v] + e.cost) {
                continue;
            } else if (res[e.to] > res[v] + e.cost) {
                res[e.to] = res[v] + e.cost;
                dp[e.to] = dp[v];
                Q.emplace(res[e.to], e.to);
            } else {
                (dp[e.to] += dp[v]) %= MOD;
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
 
    int N, M;
    cin >> N >> M;
    Graph G(N);
    int S, T;
    cin >> S >> T;
    S--, T--;
    vector<Edge> E(M);
    rep(i, M) {
        int U, V, D;
        cin >> U >> V >> D;
        U--, V--;
        G[U].emplace_back(U, V, D);
        G[V].emplace_back(V, U, D);
        E[i] = Edge(U, V, D);
    }
 
    vector<ll> dist1, dp1;
    dijkstra(S, G, dist1, dp1);
    vector<ll> dist2, dp2;
    dijkstra(T, G, dist2, dp2);
 
    ll min_dist = dist1[T];
 
    ll ans = dp1[T] * dp1[T] % MOD;
#ifdef DEBUG
    DUMP(ans);
#endif
    rep(v, N) {
        if (dist1[v] * 2 == min_dist) {
            ll tmp = dp1[v] * dp1[v] % MOD * dp2[v] % MOD * dp2[v] % MOD;
            ans = (ans - tmp + MOD) % MOD;
        }
    }
#ifdef DEBUG
    DUMP(ans);
#endif
    for (auto e : E) {
        int u = e.from, v = e.to;
        if (dist1[u] > dist1[v]) swap(u, v);
        if (dist1[u] + dist2[v] + e.cost != min_dist) continue;
        // if (abs(dist1[u] - dist2[v]) < e.cost) {
        // if (2 * dist1[u] < min_dist && min_dist < 2 * (dist1[u] + e.cost) &&
                // 2 * dist2[v] < min_dist && min_dist < 2 * (dist2[v] + e.cost)) {
        if (2 * dist1[u] < min_dist && 2 * dist1[v] > min_dist) {
            ll tmp = dp1[u] * dp1[u] % MOD * dp2[v] % MOD * dp2[v] % MOD;
            ans = (ans - tmp + MOD) % MOD;
        }
#ifdef DEBUG
        cerr << "---------" << endl;
        DUMP2(u, v);
        DUMP(ans);
#endif
    }
    cout << ans << endl;
 
#ifdef DEBUG
    cerr << "dp1:" << endl;
    rep(i, N) cerr << dp1[i] << " ";
    cerr << endl;
    cerr << "dp2:" << endl;
    rep(i, N) cerr << dp2[i] << " ";
    cerr << endl;
#endif
 
}