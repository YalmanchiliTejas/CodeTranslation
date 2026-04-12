#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REREP(i,n) for(int i = int(n - 1); i >= 0; i--)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define REFOR(i, m, n) for(int i = int(n - 1);i >= int(m);i--)
#define ALL(obj) (obj).begin(),(obj).end()

#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VD vector<double>
#define VVD vector<vector<double>>
#define VVVD vector<vector<vector<double>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VVVL vector<vector<vector<ll>>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define VVVB vector<vector<vector<bool>>>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVVS vector<vector<vector<string>>>

#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<ll,ll>
#define VPII vector<pair<int,int>>
#define VVPII vector<vector<pair<int,int>>>
#define VVVPII vector<vector<vector<pair<int,int>>>>
#define VPLL vector<pair<ll,ll>>
#define VVPLL vector<vector<pair<ll,ll>>>
#define VVVPLL vector<vector<vector<pair<ll,ll>>>>

#define SUMI(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SUMD(obj) accumulate((obj).begin(), (obj).end(), 0.)
#define SUML(obj) accumulate((obj).begin(), (obj).end(), 0LL)
#define SORT(obj) sort((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) sort((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;

//integer
class Integer {
public:
	int gcd(int a, int b) {
		if (a == 0 || b == 0) return 0;
		if (a < b) swap(a, b);
		while (b != 0) {
			a = a%b;
			swap(a, b);
		}
		return a;
	}

	int lcm(int a, int b) {
		if (a == 0 || b == 0) return 0;
		return a / gcd(a, b)*b;
	}
};

//eratosthenes
class Eratosthenes{
public:
	vector<bool> primary(int N) {
		vector<bool> primary(N + 1, true);
		primary[0] = false;
		if (N == 0) return primary;
		primary[1] = false;
		for (int i = 1; i*i <= N; i++) if (primary[i]) for (int j = 2 * i; j <= N; j += i) primary[j] = false;
		return primary;
	}
};

//combination mod
class Combination_Mod {
public:
	VL factorial;

	//N! table
	void set(ll N, ll quotient){
		factorial.resize(N + 1, 1);
		for (ll i = 1; i <= N; i++) {
			factorial[i] *= factorial[i - 1] * i;
			factorial[i] %= quotient;
		}
		return;
	}

	//repeat square method y = x^n mod quotient 
	ll rsm(ll x, ll n, ll quotient) {
		ll y = 1;
		while (n > 0) {
			if ((n & 1) == 1) {
				y *= x;
				y %= quotient;
			}
			x *= x;
			x %= quotient;
			n >>= 1;
		}
		return y;
	}

	//modulus of nCk - combination mod 
	ll nCk(ll n, ll k, ll quotient) {
		if (n < k || k == 0) return 0;
		ll nCk = (factorial[n] % quotient);
		nCk *= rsm(factorial[k], quotient - 2, quotient);
		nCk %= quotient;
		nCk *= rsm(factorial[n - k], quotient - 2, quotient);
		return (nCk % quotient);
	}
};

//union-find
class Union_Find {
public:
	VI node;
	void set(int n){
		node.resize(n);
		REP(i, n) node[i] = i;
	}

	int root(int n) {
		if (node[n] == n) return n;
		else return node[n] = root(node[n]);
	}

	void unite(int n, int m) {
		if (n > m) swap(n, m);
		n = root(n);
		m = root(m);
		if (n == m) return;
		else node[m] = n;
	}
};

//dijkstra
class Dijkstra{
public:
	VVPII edge;
	VVI dist;
	void set(int N, int inf){
		edge.resize(N);
		dist.resize(N);
		REP(i, N) dist[i].resize(N);
		REP(i, N)REP(j, N) dist[i][j] = inf;
	}

	void make_edge(int from, int to, int cost) {
		edge[from].push_back({ to,cost });
	}

	void dijkstra(int start) {
		priority_queue<PII, vector<PII>, greater<PII>> pq;
		dist[start][start] = 0;
		pq.push({ 0,start });
		while (!pq.empty()) {
			int from = pq.top().second;
			pq.pop();
			REP(i, edge[from].size()) {
				int to = edge[from][i].first;
				if (dist[start][to] > dist[start][from] + edge[from][i].second) {
					dist[start][to] = dist[start][from] + edge[from][i].second;
					pq.push({ dist[start][from] + edge[from][i].second,to });
				}
			}
		}
	}
};

//bellman-ford
class Bellman_Ford {
public:
	struct edge{
		int from, to, cost;
	};
	int N;
	VI node;
	vector<edge> graph;

	void set(int node_, int inf) {
		N = node_;
		node.resize(node_);
	}

	void make_edge(int from,int to, int cost){
		graph.push_back({from,to,cost});
	}

	void bellman_ford(int start,int inf) {
		REP(i, N) node[i] = inf;
		node[start] = 0;		
		REP(i, N - 1) REP(j, graph.size()) if (node[graph[j].to] > node[graph[j].from] + graph[j].cost) node[graph[j].to] = node[graph[j].from] + graph[j].cost;
	}
};

//ford fulkerson
class Ford_Fulkerson{
public:
	struct edge {
		int to, cap, rev;
	};

	int node, start, goal;
	vector<vector<edge>> graph;
	vector<bool> visit;

	void set(int node_, int start_, int goal_) {
		node = node_;
		start = start_;
		goal = goal_;
		graph.resize(node);
		visit.resize(node);
	}

	void make_edge(int from, int to, int cap) {
		graph[from].push_back({ to,cap,(int)graph[to].size() });
		graph[to].push_back({ from,0,(int)graph[from].size() - 1 });
	}

	int dfs(int from, int flow) {
		if (from == goal) return flow;
		visit[from] = false;
		REP(i, graph[from].size()) {
			if (visit[graph[from][i].to] && (graph[from][i].cap > 0)) {
				int dflow = dfs(graph[from][i].to, min(flow, graph[from][i].cap));
				if (dflow > 0) {
					graph[from][i].cap -= dflow;
					graph[graph[from][i].to][graph[from][i].rev].cap += dflow;
					return dflow;
				}
			}
		}
		return 0;
	}

	int maxflow(void) {
		int maxflow = 0;
		while (1) {
			REP(i, graph.size()) visit[i] = true;
			int flow = dfs(start, 1);
			if (flow == 0) return maxflow;
			maxflow += flow;
		}
	}
};

//least common ancestor
class Least_Common_Ancestor {
public:
	int node;
	int MAXLOG2;
	VVI edge;
	VI depth;
	VVI parent;

	void set(int node_, int MAXLOG2_) {
		node = node_;
		MAXLOG2 = MAXLOG2_;
		edge.resize(node);
		depth.resize(node);
		parent.resize(node);
		REP(i, node) parent[i].resize(MAXLOG2);
	}

	void dfs(int root, int root_from) {
		depth[root] = 0;
		parent[root][0] = root_from;
		stack<pair<int, int>> st;
		st.push({ root,root_from });

		while (!st.empty()) {
			int from = st.top().first;
			int from_from = st.top().second;
			st.pop();
			REP(i, edge[from].size()) {
				int to = edge[from][i];
				if (to != from_from) {
					depth[to] = depth[from] + 1;
					parent[to][0] = from;
					st.push({ to,from });
				}
			}
		}
		return;
	}

	//make table
	void initialize(int N) {
		REP(k, MAXLOG2 - 1) {
			REP(i, N) {
				if (parent[i][k] < 0) parent[i][k + 1] = -1;
				else parent[i][k + 1] = parent[parent[i][k]][k];
			}
		}
		return;
	}

	//get least common ancestor
	int get(int a, int b) {
		if (depth[a] > depth[b]) swap(a, b);
		REP(k, MAXLOG2 - 1) if (((depth[b] - depth[a]) >> k) & 1) b = parent[b][k];
		if (a == b) return a;
		REREP(k, MAXLOG2) {
			if (parent[a][k] != parent[b][k]) {
				a = parent[a][k];
				b = parent[b][k];
			}
		}
		return parent[a][0];
	}
};

//directed acyclic graph
class Directed_Acyclic_Graph{
public:

	int N;
	Dijkstra dijkstra;
	struct edge {
		int dest, cost;
		bool need;
	};
	vector<vector<edge>> output;
	VI input;
	VI topological_order;

	void set(int N_, int inf){
		N = N_;
		dijkstra.set(N, inf);
		output.resize(N);
		input.resize(N,0);
	}

	void make_edge(int from, int to, int cost){
		dijkstra.make_edge(from, to, cost);
		output[from].push_back({to, cost, true});
	}

	void make_dag(int start) {
		dijkstra.dijkstra(start);
		REP(i, N) {
			REP(j, output[i].size()) {
				int from = i;
				edge &e = output[i][j];
				if (dijkstra.dist[start][e.dest] - dijkstra.dist[start][from] != e.cost) e.need = false;
			}
		}
	}

	bool topological_sort(int start){
		REP(i, N) REP(j, output[i].size()) if (output[i][j].need) input[output[i][j].dest]++;

		stack<int> st;
		st.push(start);
		while(!st.empty()){
			int from = st.top();
			st.pop();
			topological_order.push_back(from);
			REP(i, output[from].size()) {
				edge &e = output[from][i];
				if (e.need) {
					input[e.dest]--;
					if (input[e.dest] == 0) st.push(e.dest);
				}
			}
		}
		
		bool valid = true;
		REP(i, N) if (input[i] > 0) valid = false;
		return valid;
	}	
};


void YN(bool flag){
	cout << ((flag) ? "YES" : "NO") << endl;
}

void Yn(bool flag) {
	cout << ((flag) ? "Yes" : "No") << endl;
}

void yn(bool flag) {
	cout << ((flag) ? "yes" : "no") << endl;
}


int main() {
	int N; cin >> N;
	VI X(N),Z(N); REP(i, N) cin >> X[i];
	VPII Y(N); REP(i, N) Y[i] = { X[i],i };
	sort(ALL(Y));
	REP(i,N){
		if (i < N / 2) Z[Y[i].second] = N / 2;
		else Z[Y[i].second] = N / 2 - 1;
	}
	REP(i,N){
		cout << Y[Z[i]].first << endl;
	}
	



	return 0;
}
