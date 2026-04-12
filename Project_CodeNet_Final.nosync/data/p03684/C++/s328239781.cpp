#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

typedef int Weight;
struct Edge{
    int from, to;
    Weight weight;
    int rev;     // ネットワークフロー時の逆辺
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

struct UnionFind{
    vector<int> parent, rank;
    UnionFind(int n){ parent = vector<int>(n, -1); rank = vector<int>(n, 0); }
    int find(int x){
        if(parent[x] == -1) return x;
        else return (parent[x] = find(parent[x]));
    }
    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y])
            parent[x] = y;
        else
            parent[y] = x;
        if(rank[x] == rank[y])
            ++rank[x];
        return true;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

pair<Weight, Edges> kruskal_e(Edges &edges, int n){
    sort(ALL(edges)); reverse(ALL(edges));  //a < b <-> a.weight > b.weight
    int sz = edges.size();

    UnionFind uf(n);
    Weight total = 0;
    Edges F;
    for(int i = 0; i < sz; ++i){
        if(uf.unite(edges[i].from, edges[i].to)){
            total = total + edges[i].weight;
            F.push_back(edges[i]);
        }
    }
    return make_pair(total, F);
}
pair<Weight, Edges> kruskal_g(const Graph &g){
    int n = g.size();
    vector<Edge> edges;
    for(int i = 0; i < n; ++i) edges.insert(edges.end(), ALL(g[i]));
    return kruskal_e(edges, n);
}

signed main(){
	int N;
	cin >> N;
	vector<int> x(N), y(N);
	vector<pair<int,int>> xp(N), yp(N);
	for(int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
		xp[i] = make_pair(x[i], i);
		yp[i] = make_pair(y[i], i);
	}
	sort(ALL(xp));
	sort(ALL(yp));
	Edges es;
	for(int i = 0; i < N - 1; ++i) {
		es.push_back(Edge(xp[i].second, xp[i+1].second, xp[i+1].first - xp[i].first));
		es.push_back(Edge(yp[i].second, yp[i+1].second, yp[i+1].first - yp[i].first));
	}
	auto res = kruskal_e(es, N);
	cout << res.first << endl;
	return 0;
}
