#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<typename U, typename V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

const ll MOD = 1e9 + 7;

int main() {
    FAST_IO();
    int N, M; cin >> N >> M;
    int S, T; cin >> S >> T;
    vector<vector<pll>> adj(N);
    --S, --T;
    rep(i, M) {
        ll u, v, d; cin >> u >> v >> d;
        adj[u-1].push_back({v-1, 2*d});
        adj[v-1].push_back({u-1, 2*d});
    }
    // Dijkstra on S
    vector<ll> dist(N, LONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[S] = 0;
    pq.push({dist[S], S});
    while(!pq.empty()) {
        ll here = pq.top().second;
        ll d = pq.top().first; pq.pop();
        if(dist[here] < d) continue;
        for(auto &e : adj[here]) {
            ll &next = e.first;
            if(dist[next] > dist[here] + e.second) {
                dist[next] = dist[here] + e.second;
                pq.push({dist[next], next});
            }
        }
    }
    ll D = dist[T] / 2;
    vector<pii> B;
    rep(u, N) {
        if(dist[u] == D) {
            B.push_back({u, u});
        } else {
            for(auto &e : adj[u]) {
                ll &v = e.first;
                if(dist[u] + e.second == dist[v] && dist[u] < D && dist[v] > D) {
                    B.push_back({u, v});
                }
            }
        }
    }
    // calculate cnt(S, u), cnt(v, T)
    vector<ll> cntS(N), cntT(N);
    cntS[S] = 1; cntT[T] = 1;
    vector<pll> sorted(N);
    rep(i, N) sorted[i] = {dist[i], i};
    sort(all(sorted));
    rep(i, N) {
        int j = sorted[i].second;
        for(auto &e : adj[j]) {
            if(dist[j] + e.second == dist[e.first]) {
                cntS[e.first] = (cntS[e.first] + cntS[j]) % MOD;    
            }
        }
    }
    rep(i, N) {
        int j = sorted[N - 1 - i].second;
        for(auto &e : adj[j]) {
            if(dist[j] - e.second == dist[e.first]) {
                cntT[e.first] = (cntT[e.first] + cntT[j]) % MOD;
            }
        }
    }
    ll sum = 0, sq_sum = 0;
    for(auto &p : B) {
        ll Y = (cntS[p.first] * cntT[p.second]) % MOD;
        sum = (sum + Y) % MOD;
        sq_sum = (sq_sum + Y*Y%MOD) % MOD;
    }
    cout << (sum*sum%MOD - sq_sum + MOD) % MOD << "\n";
}
