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

struct Edge {
    int from, to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
    Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
};

const int MAXN = 4010;
struct UnionFind {
    int node[MAXN];
    UnionFind() {
        memset(node, -1, sizeof(node));
    }
    int find(int x) {
        return node[x] < 0 ? x : node[x] = find(node[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        node[x] += node[y];
        node[y] = x;
        return true;
    }
};

using Graph = vector< vector<Edge> >;
int max_edge[MAXN][MAXN];

void dfs(Graph &G, int cur, int par, int orig) {
    int prev_max = max_edge[orig][cur];
    for(auto e : G[cur]) {
        if(e.to == par) continue;
        chmax(max_edge[orig][e.to], max(prev_max, e.cost));
        dfs(G, e.to, cur, orig);
    }
}
 
UnionFind uf;
signed main() {
    int N, M; cin >> N >> M;
    
    vector<Edge> edges;
    for(int i=0; i<M; i++) {
        int u, v, cost; cin >> u >> v >> cost;
        u--; v--;
        edges.emplace_back(u, v, cost);
    }
    sort(edges.begin(), edges.end());

    int sum = 0;
    Graph MST(N);
    for(int i=0; i<M; i++) {
        Edge e = edges[i];
        if(uf.unite(e.from, e.to)) {
            MST[e.from].emplace_back(e.from, e.to  , e.cost);
            MST[e.to  ].emplace_back(e.to,   e.from, e.cost);
            sum += e.cost;
        }
    }

    for(int i=0; i<N; i++) dfs(MST, i, -1, i);

    /*
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("max_edge[%lld][%lld] = %lld\n", i+1, j+1, max_edge[i][j]);
        }
    }
    */

    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        int s, t; cin >> s >> t;
        s--; t--;
        // printf("max_edge = %lld\n", max_edge[s][t]);
        cout << sum - max(max_edge[s][t], max_edge[t][s]) << endl;
    }
    return 0;
}