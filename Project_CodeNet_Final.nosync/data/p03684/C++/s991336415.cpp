#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb emplace_back

using pii = pair<int, int>;
using vi = vector<int>;
using lint = long long;

const int inf = 1001001001;
const lint linf = 1001001001001001001ll;
const int mod = 1e9 + 7;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; } return a > b; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; } return a < b; }
template<typename T> inline void print(const T &x, string s = "\n") { cout << x << s; }
template<typename T> inline void print(const vector<T> &v, string s = " ") 
{ rep(i, v.size()) cout << v[i] << (i + 1 == v.size() ? "\n" : s); }
inline bool inside(int y, int x, int H, int W) { return 0 <= y && y < H && 0 <= x && x < W; }
inline lint in() { lint x; std::cin>>x; return x; }

struct UnionFind{
	vector<int> r,p;
	UnionFind(){}
	UnionFind(int size){init(size);}
	void init(int size){
		r.resize(size,0);
		p.resize(size,0);
		for(int i=0;i<size;i++) r[i]=1,p[i]=i;
	}
	int find(int x){
		return (x==p[x]?x:p[x]=find(p[x]));
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y) return;
		if(r[x]<r[y]) swap(x,y);
		r[x]+=r[y];
		p[y]=x;
	}
};
struct edge{
	int from,to,cost;
	edge(){}
	edge(int from,int to,int cost):from(from),to(to),cost(cost){}
	bool operator<(const edge& e) const{
		return cost<e.cost;
	}
};
int kruskal(int N,vector<edge> edges){
	int res=0;
	sort(edges.begin(),edges.end());
	UnionFind uf(N+1);
	for(int i=0;i<(int)edges.size();i++){
		edge e=edges[i];
		if(!uf.same(e.from,e.to)){
			res+=e.cost;
			uf.unite(e.from,e.to);
		}
	}
	return res;
}


int main(){
	int n = in();
	vector<pii> x(n), y(n);
	rep(i, n) {
	 int u = in(), v = in();
 	 x[i].fs = u; x[i].sc = i;
	 y[i].fs = v; y[i].sc = i;
	}

	sort(all(x));
	sort(all(y));

	int V = n, E = (n - 1);
	vector<edge> edges(4 * E);

	rep(i, E) {
		edges[i].to = x[i].sc;
		edges[i].from = x[i + 1].sc;
		edges[i].cost = abs(x[i].fs - x[i + 1].fs);

		edges[i + E].to = y[i].sc;
		edges[i + E].from = y[i + 1].sc;
		edges[i + E].cost = abs(y[i].fs - y[i + 1].fs);
		
		edges[i + 2 * E].from = x[i].sc;
		edges[i + 2 * E].to = x[i + 1].sc;
		edges[i + 2 * E].cost = abs(x[i].fs - x[i + 1].fs);

		edges[i + 3 * E].from = y[i].sc;
		edges[i + 3 * E].to = y[i + 1].sc;
		edges[i + 3 * E].cost = abs(y[i].fs - y[i + 1].fs);
	}

	//for(int i = 0; i < E; i++)
		//cin >> edges[i].from >> edges[i].to >> edges[i].cost;
	cout << kruskal(V, edges) <<endl;
	return 0;
}

