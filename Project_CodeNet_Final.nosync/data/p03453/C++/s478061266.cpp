#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1e9 + 7;

int N, M, S, T;
vector<pii> adj[100010];
ll Sdist[100010], Tdist[100010];
priority_queue<pair<ll, int> > pq;

void dijkstra(int st, ll *dist) {
    for(int i = 0; i < N; i++) dist[i] = 1e18;
    pq.push(make_pair(0, st));
    dist[st] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        ll ud = -pq.top().first;
        pq.pop();

        if(ud > dist[u]) continue;

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            ll vd = adj[u][i].second;

            if(dist[v] > ud + vd) {
                dist[v] = ud + vd;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }
}

int Sdp[100010], Tdp[100010], vis[100010];

void Sdfs(int u, int dest) {
    vis[u] = 1;
    if(u == dest) {
        Sdp[u] = 1;
        return;
    }
    Sdp[u] = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        int d = adj[u][i].second;

        if(Sdist[u] + d == Sdist[v]) {
            if(!vis[v]) Sdfs(v, dest);
            Sdp[u] += Sdp[v];
            Sdp[u] %= mod;
        }
    }
}
void Tdfs(int u, int dest) {
    vis[u] = 1;
    if(u == dest) {
        Tdp[u] = 1;
        return;
    }
    Tdp[u] = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        int d = adj[u][i].second;

        if(Tdist[u] + d == Tdist[v]) {
            if(!vis[v]) Tdfs(v, dest);
            Tdp[u] += Tdp[v];
            Tdp[u] %= mod;
        }
    }
}

int main() {
    scanf("%d %d %d %d", &N, &M, &S, &T);
    S--; T--;

    for(int i = 0; i < M; i++) {
        int u, v, d; scanf("%d %d %d", &u, &v, &d);
        u--; v--;

        adj[u].push_back(pii(v, d));
        adj[v].push_back(pii(u, d));
    }

    dijkstra(S, Sdist);
    dijkstra(T, Tdist);
    Sdfs(S, T);

    memset(vis, 0, sizeof(vis));
    Tdfs(T, S);

    int ans = 1LL * Sdp[S] * Sdp[S] % mod;

    for(int i = 0; i < N; i++) if(Sdist[i] == Tdist[i]) {
        int tmp = 1LL * Sdp[i] * Tdp[i] % mod;

        ans += mod - 1LL * tmp * tmp % mod;
        ans %= mod;
    }

    for(int u = 0; u < N; u++) {
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int d = adj[u][i].second;

            if(Sdist[u] + d == Sdist[v] && Tdist[v] + d == Tdist[u] && !(Tdist[u] <= Sdist[u] || Sdist[v] <= Tdist[v])) {
                int tmp = 1LL * Tdp[u] * Sdp[v] % mod;

                ans += mod - 1LL * tmp * tmp % mod;
                ans %= mod;
            }
        }
    }

    printf("%d", ans);
}
