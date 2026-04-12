#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) x.begin(),x.end()
#define ln '\n'
const double PI = acos(-1.0);
const long long MOD = 1000000007LL;
//const long long MOD = 998244353LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct edge {
    int src,to;
    T cost;

    edge() = default;
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};

template<typename T>
vector<T> Dijkstra(vector<vector<edge<T>>> &G, int s, T inf) {
    vector<T> dist(G.size(),inf);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    dist[s] = 0;
    pq.emplace(dist[s],s);
    while (!pq.empty()) {
        T d; int v;
        tie(d,v) = pq.top(); pq.pop();
        if (d > dist[v]) continue;
        for (auto &e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to],e.to);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;

    vector<vector<edge<int>>> G(N);
    rep(i,N-1) {
        int u,v,w; cin >> u >> v >> w;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }

    auto dist = Dijkstra<int>(G,0,1e9);
    int p = max_element(all(dist)) - dist.begin();
    auto dist2 = Dijkstra<int>(G,p,1e9);
    int q = max_element(all(dist2)) - dist2.begin();
    auto dist3 = Dijkstra<int>(G,q,1e9);
    rep(i,N) cout << max(dist2[i],dist3[i]) << ln;
}
