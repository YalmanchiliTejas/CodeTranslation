#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const int MOD = (int)1e9 + 7;
const int INF = (int)1e15;


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
			int d = dist[i -> from] + i->weight;
			if (dist[i->to] == d) {
				cnt[i->to] = (cnt[i->to] + cnt[i->from]) % MOD;
			} else if(dist[i -> to] > d){
                dist[i -> to] = dist[i -> from] + i -> weight;
				cnt[i->to] = cnt[i->from];
                Q.push(Edge(i -> from, i -> to, dist[i -> to]));
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

signed main(){
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	Edges es;
	Graph g(N + 1);
	for(int i = 0; i < M; ++i) {
		int U, V,D;
		cin >> U >> V >> D;
		es.push_back(Edge(U, V, D));
		addUndirectedEdge(g, U, V, D);
	}
	vector<int> dist, rdist, prev, rprev, cnt, rcnt;
	dijkstra(g, S, dist, prev, cnt);
	dijkstra(g, T, rdist, rprev, rcnt);

	/*
	for(int i = 1; i <= N; ++i) {
		cerr << cnt[i] << "," << rcnt[i] << "," << dist[i] << "," << rdist[i] << endl;
	}
	*/

	int res = cnt[T] * cnt[T] % MOD;
	//cerr << res << endl;
	for(auto e: es) {
		int u = e.from, v = e.to;
		if (dist[u] >  dist[v])
			swap(u,v);
		if (dist[u] + e.weight + rdist[v] != dist[T])
			continue;
		// if(rdist[u] < dist[u] || dist[v] < rdist[v])
		if (dist[u] * 2 >= dist[T] || rdist[v] * 2 >= dist[T])
			continue;
		res = (res - (cnt[u] * rcnt[v] % MOD) *  (cnt[u] * rcnt[v] % MOD + MOD) % MOD + MOD) % MOD;
	}
	//cerr << res << endl;
	for(int i = 1; i <= N; ++i) {
		if(dist[i] + rdist[i] == dist[T] && dist[i] == rdist[i]) {
			res = (res - (cnt[i] * rcnt[i] % MOD) * (cnt[i] * rcnt[i] % MOD) % MOD + MOD) % MOD;
		}
	}
	cout << res << endl;

	return 0;
}

