#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

const ll MOD = (ll)1e9 + 7;
const ll MOD2 = 998244353;
const ll HIGHINF = (ll)1e18;
const ll LOWINF = (ll)1e15;
const long double PI = 3.1415926535897932384626433;

template<typename T> vector<T> make_v(size_t N,T init){return vector<T>(N,init);}
template<typename... T> auto make_v(size_t N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max<T>(a,b);}
template <class T> void chmin(T& a, const T b){a=min<T>(a,b);}
void YN(bool flg) {cout << ((flg) ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << ((flg) ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << ((flg) ? "yes" : "no") << endl;}

template<class T> class Tree {
public:
	int N;
	int is_weighted;
	int MAX_bit;
	int idx;
	vector<vector<int>> edge;
	vector<vector<T>> weight;
	vector<int> depth;
	vector<int> order;
	vector<T> dist;
	
	vector<int> parent;
	vector<T> parent_dist;
	
	vector<vector<int>> child;
	vector<vector<T>> child_dist;

	vector<vector<int>> ancestor;
	vector<vector<int>> subtree;
	vector<long long> subtree_size;
	vector<long long> omnidirectional_size;

	vector<int> Euler_Tour;
	vector<int> idxl;
	vector<int> idxr;

	Tree(const int N, const int is_weighted = 0, const int MAX_bit = 20) : 
	N(N),
	is_weighted(is_weighted),
	MAX_bit(MAX_bit),
	edge(N),
	depth(N),
	order(N)
	{
		if(is_weighted) weight.resize(N);
		if(is_weighted) dist.resize(N);
	}

	//O(1)
	void make_edge(const int& from, const int& to, const T& w = 0) {
		edge[from].push_back(to);
		if(is_weighted)	weight[from].push_back(w);
	}

	//O(N)
	void make_depth(const int root) {
		depth[root] = 0;
		if(is_weighted) dist[root] = 0;
		idx = 0;
		dfs1(root);
		order[idx++] = root;
	}

	void dfs1(int from, int prev = -1){
		for(int i = 0; i < edge[from].size(); ++i){
			int to = edge[from][i];
			if(to==prev) continue;
			depth[to] = depth[from] + 1;
			if(is_weighted) dist[to] = dist[from] + weight[from][i];
			dfs1(to,from);
			order[idx++] = to;
		}
	}

	int diameter(void){
		make_depth(0);
		int tmp = max_element(depth.begin(), depth.end()) - depth.begin();
		make_depth(tmp);
		return *max_element(depth.begin(), depth.end());
	}

	//O(N)
	void make_parent(void) {
		parent.resize(N);
		iota(parent.begin(),parent.end(),0);
		for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) parent[i] = j;

		if(is_weighted) {
			parent_dist.resize(N);
			for (int i = 0; i < N; ++i) for (int j = 0; j < edge[i].size(); ++j) if (depth[i] > depth[edge[i][j]]) parent_dist[i] = weight[i][j];
		}
	}

	//O(N)
	void make_child(void) {
		child.resize(N);
		for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);

		if(is_weighted) {
			child_dist.resize(N);
			for (int i = 0; i < N; ++i) for (int j = 0; j < edge[i].size(); ++j) if (depth[i] > depth[edge[i][j]]) child_dist[i].push_back(weight[i][j]);
		}
	}

	//O(NlogN)
	void make_ancestor(void) {
		ancestor.resize(N,vector<int>(MAX_bit));
		for (int i = 0; i < N; ++i) ancestor[i][0] = i;
		for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) ancestor[i][0] = j;
		for (int bit = 1; bit < MAX_bit; ++bit) for (int i = 0; i < N; ++i) ancestor[i][bit] = ancestor[ancestor[i][bit - 1]][bit - 1];
	}

	//O(N^2)
	void make_subtree(void) {
		subtree.resize(N);
		for (int i = 0; i < N; ++i) subtree[i].push_back(i);
		for (int i = 0; i < N; ++i) for (auto j : edge[order[i]]) if (depth[order[i]] < depth[j]) for(auto k: subtree[j]) subtree[order[i]].push_back(k);
	}
	
	//O(N)
	void make_subtree_size(void){
		subtree_size.resize(N,1);
		for(auto i:order) if(i != parent[i]) subtree_size[parent[i]] += subtree_size[i];
	}
	//O(N)
	void make_omnidirectional_size(void){
		omnidirectional_size.resize(N,0);
		for(int i = N-1; 0 <= i; --i) {
			int j = order[i];
			long long sum = omnidirectional_size[j];
			for(auto k:child[j]) sum += subtree_size[k];
			for(auto k:child[j]) omnidirectional_size[k] = sum - subtree_size[k] + 1;
		}
	}
	
	//O(N)
	void make_Euler_Tour(const int& root){
		dfs2(root);
		idxl.resize(N);
		idxr.resize(N);
		for(int i = 0; i < Euler_Tour.size(); ++i) idxr[Euler_Tour[i]] = i;
		for(int i = Euler_Tour.size()-1; 0 <= i; --i) idxl[Euler_Tour[i]] = i;
		return;
	}

	void dfs2(int from, int prev = -1){
		Euler_Tour.push_back(from);
		for(auto to:edge[from]){
			if(to == prev) continue;
			dfs2(to,from);
			Euler_Tour.push_back(from);
		}
	}

	//O(logN)
	int LCA(int l, int r) {
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		for (int bit = 0; bit < MAX_bit; ++bit) if (diff & (1 << bit)) l = ancestor[l][bit];
		if(l==r) return l;
		for (int bit = MAX_bit - 1; 0 <= bit; --bit) if(ancestor[l][bit]!=ancestor[r][bit]) l = ancestor[l][bit], r = ancestor[r][bit];
		return ancestor[l][0];
	}
};

//depth,dist
//https://atcoder.jp/contests/abc126/tasks/abc126_d

//LCA
//https://atcoder.jp/contests/abc014/tasks/abc014_4

//diameter
//https://atcoder.jp/contests/agc033/tasks/agc033_c


int main() {
	int N; cin >> N;
	V<int> ord(N,0),sum(N,0);
	V<V<int>> edge(N);
	for(int i = 0; i < N -1; ++i){
		int u,v; cin >> u >> v;
		u--,v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
		ord[u]++;
		ord[v]++;
	}

	queue<int> q;
	for(int i = 0; i < N; ++i) if(ord[i]==1) q.push(i);
	V<int> c(N,0);
	while(q.size()){
		int x = q.front();
		q.pop();
		if(c[x]) continue;
		
		int flg = 1;
		for(auto i:edge[x]) if(!c[i]) flg = 0;
		corner(flg,"First");
		
		int y;
		for(auto i:edge[x]) if(!c[i]) y = i;
		c[x] = c[y] = 1;
		for(auto i:edge[y]) ord[i]--;
		for(auto i:edge[y]) if(ord[i]==1&&!c[i]) q.push(i);
	}
	cout << "Second" << endl;
    return 0;
}
