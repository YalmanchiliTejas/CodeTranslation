#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
const int INF = 1e18 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int n, m;
int S, T;
struct Edge {
    int v, c;
};  
int dist[2][N];
int dp[2][N];
vector <Edge> g[N];
void work(int S, int *dist, int *dp) {
    set <pair <int, int> > ms;
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }   
    dist[S] = 0;
    dp[S] = 1;
    ms.insert({0, S});
    while (ms.size()) {
        int u = ms.begin()->second; ms.erase(ms.begin());
        for (auto e : g[u]) {
            if (dist[u] + e.c < dist[e.v]) {
                ms.erase({dist[e.v], e.v});
                dist[e.v] = dist[u] + e.c;
                dp[e.v] = dp[u];
                ms.insert({dist[e.v], e.v});
            }   
            else if (dist[u] + e.c == dist[e.v]) {
                dp[e.v] = mod(dp[e.v] + dp[u]);
            }   
        }   
    }   
}   
struct Ed {
    int u, v, c;
};  
vector <Ed> ed;
bool check(int x, int y, int c) {
    if (y < x) swap(x, y);
    return y < x + c;
}   
int D;
bool mem(int t, int u, int v, int c) {
    return dist[t][u] + c == dist[t][v] && dist[t][v] + dist[t ^ 1][v] == D;
}
int f(int n) {
    n = mod(n);
    return mod(n * n);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> S >> T;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        ed.push_back({u, v, c});
    }   
    work(S, dist[0], dp[0]); work(T, dist[1], dp[1]);
    D = dist[0][T];
    int ans = mod(dp[0][T] * dp[0][T]);
    for (int i = 1; i <= n; ++i) {
        if (dist[0][i] + dist[1][i] == D && dist[0][i] == dist[1][i]) {
            ans = mod(ans - f(dp[0][i] * dp[1][i]));
        }   
    }   
    for (auto e : ed) {
        if (mem(0, e.u, e.v, e.c) && mem(1, e.v, e.u, e.c)) {
            if (check(dist[0][e.u], dist[1][e.v], e.c)) {
                ans = mod(ans - f(dp[0][e.u] * dp[1][e.v]));
            }   
        }
        else if (mem(1, e.u, e.v, e.c) && mem(0, e.v, e.u, e.c)) {
            if (check(dist[1][e.u], dist[0][e.v], e.c)) {
                ans = mod(ans - f(dp[1][e.u] * dp[0][e.v]));
            }   
        }   
    }   
    cout << ans << '\n';
}   