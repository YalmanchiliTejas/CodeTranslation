#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    ll mod = 1e9+7;
    ll inf = 1e17;
    vector<vector<pair<int, ll>>> edge(N+1);
    vector<int> u(M), v(M);
    vector<ll> d(M);
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i] >> d[i];
        edge[u[i]].push_back({v[i], d[i]});
        edge[v[i]].push_back({u[i], d[i]});
    }
    
    vector<ll> dist_from_s(N+1, inf), dist_from_t(N+1, inf);
    dist_from_s[S] = 0;
    dist_from_t[T] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    pq.push({0, S});
    while (!pq.empty()) {
        int now = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();
        if (dist > dist_from_s[now]) continue;
        for (auto p : edge[now]) {
            int nxt = p.first;
            ll d = p.second;
            if (dist_from_s[nxt] > dist_from_s[now] + d) {
                dist_from_s[nxt] = dist_from_s[now] + d;
                pq.push({dist_from_s[nxt], nxt});
            }
        }
    }
    
    pq.push({0, T});
    while (!pq.empty()) {
        int now = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();
        if (dist > dist_from_t[now]) continue;
        for (auto p : edge[now]) {
            int nxt = p.first;
            ll d = p.second;
            if (dist_from_t[nxt] > dist_from_t[now] + d) {
                dist_from_t[nxt] = dist_from_t[now] + d;
                pq.push({dist_from_t[nxt], nxt});
            }
        }
    }
    
    vector<ll> dp_s(N+1, 0), dp_t(N+1, 0);
    vector<bool> visited(N+1, false);
    dp_s[S] = 1;
    dp_t[T] = 1;
    
    pq.push({0, S});
    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        if (visited[now]) continue;
        visited[now] = true;
        for (auto p : edge[now]) {
            int nxt = p.first;
            ll d = p.second;
            if (dist_from_t[nxt] + d == dist_from_t[now]) {
                dp_s[nxt] += dp_s[now];
                dp_s[nxt] %= mod;
                pq.push({dist_from_s[nxt], nxt});
            }
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    pq.push({0, T});
    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        if (visited[now]) continue;
        visited[now] = true;
        for (auto p : edge[now]) {
            int nxt = p.first;
            ll d = p.second;
            if (dist_from_s[nxt] + d == dist_from_s[now]) {
                dp_t[nxt] += dp_t[now];
                dp_t[nxt] %= mod;
                pq.push({dist_from_t[nxt], nxt});
            }
        }
    }
    
    ll ans = dp_s[T] * dp_t[S] % mod;
    for (int i = 1; i <= N; i++) {
        if (dist_from_s[i] == dist_from_t[i]) {
            ll rt1 = dp_s[i]*dp_s[i]%mod;
            ll rt2 = dp_t[i]*dp_t[i]%mod;
            ans += mod - rt1 * rt2 % mod;
            ans %= mod;
        }
    }
    
    for (int i = 0; i < M; i++) {
        if (dist_from_s[u[i]] == dist_from_t[u[i]] || dist_from_s[v[i]] == dist_from_t[v[i]]) {
            continue;
        }
        if (dist_from_s[u[i]] + d[i] + dist_from_t[v[i]] == dist_from_s[T]){
            if (dist_from_s[u[i]] < dist_from_t[u[i]] && dist_from_s[v[i]] > dist_from_t[v[i]]) {
                ll rt1 = dp_s[u[i]] * dp_s[u[i]] % mod;
                ll rt2 = dp_t[v[i]] * dp_t[v[i]] % mod;
                ans += mod - rt1 * rt2 % mod;
                ans %= mod;
            }
        }
        else if (dist_from_s[v[i]] + d[i] + dist_from_t[u[i]] == dist_from_s[T]){
            if (dist_from_s[u[i]] > dist_from_t[u[i]] && dist_from_s[v[i]] < dist_from_t[v[i]]) {
                ll rt1 = dp_s[v[i]] * dp_s[v[i]] % mod;
                ll rt2 = dp_t[u[i]] * dp_t[u[i]] % mod;
                ans += mod - rt1 * rt2 % mod;
                ans %= mod;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
