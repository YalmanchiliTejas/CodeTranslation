#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const long long MOD = 1000000007;

typedef int Weight;
struct Edge{
    int from, to;
    Weight weight;
    int rev;     // 無向グラフの対の辺
    Edge(int from, int to, Weight weight) :
        from(from), to(to), weight(weight) { }
    Edge(int from, int to, Weight weight, int rev) :
        from(from), to(to), weight(weight), rev(rev){ }
};
bool operator < (const Edge &a, const Edge &b){
    if(a.weight != b.weight) return a.weight > b.weight;
    if(a.from != b.from) return a.from > b.from;
    return  a.to > b.to;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
void addFlowEdge(Graph &g, int a, int b, Weight c){
    g[a].push_back(Edge(a, b, c, g[b].size()));
    g[b].push_back(Edge(b, a, 0, g[a].size() - 1));
}
void addUndirectedEdge(Graph &g, int a, int b, Weight c){
    g[a].push_back(Edge(a, b, c, g[b].size()));
    g[b].push_back(Edge(b, a, c, g[a].size() - 1));
}

const int INF = (int)1e16;

void dijkstra(const Graph &g, int s, vector<Weight> &dist, vector<int> &prev, vector<int> &cnt){
    int n = g.size();
    dist.assign(n, INF);
    dist[s] = 0;
    prev.assign(n, -1);
    cnt.assign(n, 0);
    cnt[s] = 1;
    priority_queue<Edge> Q;     // a < b <-> a.weight > b.weight
    Q.push(Edge(-2, s, 0));
    while(!Q.empty()){
        Edge e = Q.top(); Q.pop();
        if(prev[e.to] != -1) continue;
        prev[e.to] = e.from;
        EACH(i, g[e.to]){
            if(dist[i -> to] > dist[i -> from] + i -> weight){
                cnt[i -> to] = cnt[i->from];
                dist[i -> to] = dist[i -> from] + i -> weight;
                Q.push(Edge(i -> from, i -> to, dist[i -> to]));
            } else if(dist[i-> to] == dist[i->from] + i->weight) {
                cnt[i->to] = (cnt[i->to] + cnt[i->from]) % MOD;
            }
        }
    }
}
vector<int> buildPath(const vector<int> &prev, int t){
    vector<int> path;
    for(int v = t; v >= 0; v = prev[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

void solve(long long N, long long M, long long S, long long T, std::vector<long long> U, std::vector<long long> V, std::vector<long long> D){
    Graph g(N + 1);
    for(int i = 0; i < M; ++i) {
        addUndirectedEdge(g, U[i], V[i], D[i]);
    }

    vector<int> dist, prev, rdist, rprev, cnt, rcnt;
    dijkstra(g, S, dist, prev, cnt);
    dijkstra(g, T, rdist, rprev, rcnt);

    int L = dist[T];
    int res = 0;
    for(int i = 0; i <= N; ++i) {
        cerr << cnt[i];
    }
    cerr << endl;
    for(int i = 0; i <= N; ++i) {
        cerr << rcnt[i];
    }
    cerr << endl;
    for(int i = 0; i < M; ++i) {
        int u = U[i], v = V[i];
        if (dist[u] > dist[v]) {
            swap(u, v);
        }
        if (dist[u] + D[i] + rdist[v] == L) {
            cerr << u << "," << v << "," << D[i] << endl;
        }
        if (dist[u] + D[i] + rdist[v] > L || 2 * dist[u] >= L || 2 * rdist[v] >= L) {
            continue;
        }
        int t = cnt[u] * rcnt[v] % MOD;
        cerr << t << endl;
        res += (t * t)% MOD;
        res %= MOD;
    }
    cerr << dist[T] << cnt[T] << endl;
    for(int i = 1; i <= N; ++i) {
        if (dist[i] == rdist[i]) {
            cerr << ">" << i << endl;
        }
        if (dist[i] == rdist[i] && dist[i] * 2 == L) {
            int t = (cnt[i] * rcnt[i]) % MOD;
            res += (t * t) % MOD;
            res %= MOD;
        }
    }
    cout << (cnt[T] * cnt[T] % MOD - res + MOD) % MOD << endl;
}

signed main(){
	ios::sync_with_stdio(false);
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long S;
    scanf("%lld",&S);
    long long T;
    scanf("%lld",&T);
    std::vector<long long> U(M);
    std::vector<long long> V(M);
    std::vector<long long> D(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&U[i]);
        scanf("%lld",&V[i]);
        scanf("%lld",&D[i]);
    }
    solve(N, M, S, T, std::move(U), std::move(V), std::move(D));
    return 0;
}