#include<iostream>
#include<vector>
#include<map>
#include<stack>
#define FOR(i,a,b) for(int i=(a); i<int(b); ++i)
#define RFOR(i,a,b) for(int i=(b)-1; i>=int(a); --i)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,int(n)+1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
#define al(d) d.begin(),d.end()
using namespace std;
template <typename T>
void putv(vector<T>& V){
	// cout << "The elements in the vector are: " << endl;
	for(auto x: V)
		cout << x << " ";
	cout << endl;
}
template <class T>
vector<T> getv(int n){
	vector<T> vec;
	rep(i,n){
		T input;
		cin >> input;
		vec.emplace_back(input);
	}
	return vec;
}
using AdjList = vector<vector<int>>;
using Weight = int;
using Flow = int;
struct Edge {
	int src, dst;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

// Recieve edge(=(int,int)) as an adj list.
vector<vector<int>> getadj(int N, int M){
	// Initialize all lists of the graph as a empty vector.
	vector<int> init;
	vector<vector<int>> graph(N,init);

	rep(i,M){
		int a, b;
		cin >> a >> b;
		graph[a-1].emplace_back(b-1);
		graph[b-1].emplace_back(a-1);
	}
// rep(i,N)
// 	putv(graph[i]);
	return graph;
}
const int nmax = 8;
int dfs(int v, int N, const AdjList adj, bool visited[nmax]);
int main(){
	int N,M;
	cin >> N >> M;
	AdjList adj = getadj(N,M);
	int a[N];

	bool visited[nmax];
	rep(i,N)
		visited[i] = false;

	visited[0] = true;
	cout << dfs(0,N,adj,visited) << endl;
	return 0;
}

int dfs(int v, int N, const AdjList adj, bool visited[nmax]){
// cout << "Now I'm at "<< v << endl;
// rep(i,nmax)
// 	cout << visited[i] << "  ";
// cout << endl;
	// If all nodes have already visited , return 1.
	bool all_visited = true;
	rep(i,N)
		if(visited[i] == false){
// cout << i << " has not yet visited." << endl;
			all_visited = false;
		}
	if(all_visited) return 1;

	int ret = 0;

	int n = adj[v].size();
	rep(i,n){
		int u = adj[v][i];
		if(visited[u]) continue;
// cout << "I'll visit " << u << endl;
		visited[u] = true;
		ret += dfs(u,N,adj,visited);
		visited[u] = false;
	}
	return ret;
}