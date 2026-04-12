#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const int INF = (int)1e10;
const int MOD = (int)1e9 + 7;

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
    priority_queue<Edge> Q;     // a < b <-> a.weight > b.weight
    Q.push(Edge(-2, s, 0));
	cnt[s] = 1;
    while(!Q.empty()){
        Edge e = Q.top(); Q.pop();
        if(prev[e.to] != -1) continue;
        prev[e.to] = e.from;
        EACH(i, g[e.to]){
        //for(Edges::const_iterator i=g[e.to].begin(); i!=g[e.to].end(); ++i){    //マクロが使えないとき
            if(dist[i -> to] > dist[i -> from] + i -> weight){
				cnt[i->to] = cnt[i->from];
                dist[i -> to] = dist[i -> from] + i -> weight;
                Q.push(Edge(i -> from, i -> to, dist[i -> to]));
            } else if(dist[i -> to] == dist[i -> from] + i -> weight){
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

signed main(){
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	Graph g(N+1);
	Edges es;
	for(int i = 0; i < M; ++i){
		int l, r, d;
		cin >> l >> r >> d;
		es.push_back(Edge(l,r,d));
		addUndirectedEdge(g, l, r, d);
	}

	vector<Weight> dist(N + 1), prev(N+1), cnt(N+1);
	vector<Weight> rdist(N + 1), rprev(N+1), rcnt(N+1);

	dijkstra(g, S, dist, prev, cnt);
	dijkstra(g, T, rdist, rprev, rcnt);

	int sum = 0, L = dist[T];
	for(int i = 0; i < M; ++i) {
		int u = es[i].from, v = es[i].to;
		if(dist[u] > dist[v]) swap(u,v);
		if(dist[u] * 2 < L && rdist[v] * 2 < L && dist[u] + rdist[v] + es[i].weight == L) {
			int t = (cnt[u] * rcnt[v]) % MOD;
			sum += (t * t) % MOD;
			sum %= MOD;
		}
	}
	for(int i = 1; i <= N; ++i) {
		if(dist[i] * 2 == L && dist[i] == rdist[i]) {
			int t = (cnt[i] * rcnt[i]) % MOD;
			sum += (t * t) % MOD;
			sum %= MOD;
		}
	}
	int res = cnt[T] * cnt[T] % MOD;
	res = (res - sum + MOD * 10) % MOD;
	cout << res << endl;
	return 0;
}
