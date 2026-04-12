// 基本テンプレート
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

// 移動元と行先と辺のコストを記録する構造体
template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge() {}
    Edge(int s, T d) : to(s), cost(d) {}
    Edge(int f, int s, T d) : from(f), to(s), cost(d) {}

    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

template <typename T>
using Graph = vector< vector< Edge<T> > >;
 
void print_vec(vector<pii> vec) {
    for(size_t i=0; i<vec.size(); i++) {
        fprintf(stderr, "index = %zu, dist = %lld, pat = %lld\n", i+1, vec[i].first, vec[i].second);
    }
}

vector<pii> calc(Graph<int> &G, int root) {
    int N = G.size();
    vector<pii> dist(N, make_pair(INF, 0));
    dist[root] = make_pair(0, 1);
 
    priority_queue< pii, vector<pii>, greater<pii> >que;
    que.push(make_pair(0, root));
 
    while(que.size()) {
        pii cur = que.top(); que.pop();
        int v = cur.second;
        for(auto e : G[v]) {
            // 真に大きい → 最短路更新
            if(dist[e.to].first > cur.first + e.cost) {
                dist[e.to] = make_pair(cur.first + e.cost, dist[v].second);
                que.push(make_pair(dist[e.to].first, e.to));
            }
            // 同じ → パターン数が増える
            else if(dist[e.to].first == cur.first + e.cost) {
                (dist[e.to].second += dist[v].second) %= MOD;
                // printf("to = %lld, from = %lld, add = %lld, cnt = %lld\n", e.to+1, v+1, dist[v].second, dist[e.to].second);
            }
        }
    }
 
    return dist;
}

int dist[100010], dist2[100010];
Edge<int> edges[200010];
signed main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--; T--;
    Graph<int> G(N);
    rep(i,0,M) {
        int u, v, d; cin >> u >> v >> d;
        u--; v--;
        G[u].push_back(Edge<int>(v, d));
        G[v].push_back(Edge<int>(u, d));
        edges[i] = Edge<int>{u, v, d};
    }

    vector<int> dp(N), dp2(N);
    /*
    // dijkstra
    priority_queue< pii, vector<pii>, greater<pii> > que;
    fill(dist, dist + N, INF);
    dist[S] = 0;
    que.push(make_pair(0, S));

    while(que.size()) {
        pii cur = que.top(); que.pop();
        int v = cur.second;
        for(auto e : G[v]) {
            if(dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    // S からの最短経路の数
    vector<pii> ds(N);
    rep(i,0,N) ds[i] = (make_pair(dist[i], i));
    sort(ds.begin(), ds.end());

    dp[S] = 1;
    rep(i,0,N) {
        int v = ds[i].second;
        for(auto e : G[v]) {
            if(dist[v] + e.cost == dist[e.to]) {
                (dp[e.to] += dp[v]) %= MOD;
            }
        }
    }

    // T からの最短経路の数
    reverse(ds.begin(), ds.end());
    dp2[T] = 1;
    rep(i,0,N) {
        int v = ds[i].second;
        for(auto e : G[v]) {
            if(dist[v] == dist[e.to] + e.cost) {
                (dp2[e.to] += dp2[v]) %= MOD;
            }
        }
    }
    */

    vector<pii> A = calc(G, S), B = calc(G, T);
    rep(i,0,N) {
        dp[i] = A[i].second;
        dp2[i] = B[i].second;
        dist[i] = A[i].first;
        dist2[i] = B[i].first;
        // printf("dist %lld: %lld\n", i+1, dist[i]);
    }

    int ans = (dp[T] * dp[T]) % MOD;

    // 頂点で出会う
    rep(i,0,N) {
        if(2*dist[i] == dist[T]) {
            int sub = (dp[i] * dp2[i]) % MOD;
            (sub *= sub) %= MOD;
            ans = (ans - sub + MOD) % MOD;
        }
    }

    rep(i,0,M) {
        int u = edges[i].from, v = edges[i].to, cost = edges[i].cost;
        if(dist[u] > dist[v]) swap(u, v);

        if(2*dist[u] < dist[T] && 2*dist[v] > dist[T] && dist[u] + cost == dist[v] && dist[u] + dist2[v] + cost == dist[T]) {
            int sub = (dp[u] * dp2[v]) % MOD;
            (sub *= sub) %= MOD;
            // printf("u = %lld, v = %lld, sub = %lld\n", u+1, v+1, sub);
            ans = (ans - sub + MOD) % MOD;
            // printf("sub2 (%lld, %lld): %lld\n", u+1, v+1, sub);
            // printf("dp[u] = %lld, dp2[v] = %lld\n", dp[u], dp2[v]);
        }
    }

    cout << ans << endl;
}