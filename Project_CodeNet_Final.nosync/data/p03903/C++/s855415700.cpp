#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

//Union Find Tree
class UnionFindTree {
public:
	vector<int> parent;
    vector<int> rank;

    UnionFindTree(int N) : parent(N), rank(N,0){
		for (int i = 0; i < N; ++i) parent[i] = i;
	}
 
	int root(int n) {
		return (parent[n] == n ? n : parent[n] = root(parent[n]));
	}

    int same(int n, int m) {
		return root(n) == root(m);
	}
 
	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(rank[n]<rank[m]) {
            parent[n] = m;
        }
        else{
            parent[m] = n;
            if(rank[n] == rank[m]) rank[n]++;
        }
	}
};

//verify https://atcoder.jp/contests/abc097/tasks/arc097_b

template<class Operator> class Tree {
	Operator Op;                            
	using typeDist = decltype(Op.unitDist); 
	size_t num;
	size_t ord;
public:
	vector<vector<pair<size_t,typeDist>>> edge;
	vector<size_t> depth;
	vector<size_t> order;
	vector<typeDist> dist;
	vector<pair<size_t,typeDist>> parent;
	vector<vector<pair<size_t,typeDist>>> child;
	vector<array<pair<size_t,typeDist>,Operator::bit>> ancestor;
	vector<size_t> size;
	Tree(const int num):num(num),edge(num),depth(num,-1),order(num),dist(num){}
	//O(1) anytime
	void makeEdge(const int& from, const int& to, const typeDist w = 1) {
		edge[from].push_back({to,w});
	}
	//O(N) anytime
	void makeDepth(const int root) {
		depth[root] = 0;
		dist[root] = Op.unitDist;
		ord = 0;
		dfs1(root);
		order[ord++] = root;
	}
	//O(N) anytime
	void makeDepth(void) {
		ord = 0;
		for(size_t root = 0; root < num; ++root) {
			if(depth[root] != -1) continue;
			depth[root] = 0;
			dist[root] = Op.unitDist;
			dfs1(root);
			order[ord++] = root;
		}
	}
	//for makeDepth
	void dfs1(int curr, int prev = -1){
		for(auto& e:edge[curr]){
			int next = e.first;
			if(next==prev) continue;
			depth[next] = depth[curr] + 1;
			dist[next]  = Op.funcDist(dist[curr],e.second);
			dfs1(next,curr);
			order[ord++] = next;
		}
	}
	//O(N) after makeDepth
	void makeParent(void) {
		parent.resize(num,make_pair(num,Op.unitDist));
		for (size_t i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] > depth[e.first]) parent[i] = e;
	}
	//O(N) after makeDepth
	void makeChild(void) {
		child.resize(num);
		for (size_t i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] < depth[e.first]) child[i].push_back(e);
	}
	//O(NlogN) after makeDepth and makeParent
	void makeAncestor(void) {
		ancestor.resize(num);
		for (size_t i = 0; i < num; ++i) ancestor[i][0] = (parent[i].first!=num?parent[i]:make_pair(i,Op.unitLca));
		for (size_t j = 1; j < Operator::bit; ++j) {
			for (size_t i = 0; i < num; ++i) {
				size_t k = ancestor[i][j - 1].first;
				ancestor[i][j] = Op.funcLca(ancestor[k][j - 1],ancestor[i][j - 1]);
			}
		}
	}
	//O(logN) after makeAncestor
	//return {lca,lca_dist} l and r must be connected
	pair<size_t,typeDist> lca(size_t l, size_t r) {
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		auto ancl = make_pair(l,Op.unitLca);
		auto ancr = make_pair(r,Op.unitLca);
		for (int j = 0; j < Operator::bit; ++j) {
			if (diff & (1 << j)) {
				ancl = Op.funcLca(ancestor[ancl.first][j],ancl);
			}
		}
		if(ancl.first==ancr.first) return ancl;
		for (int j = Operator::bit - 1; 0 <= j; --j) {
			if(ancestor[ancl.first][j].first!=ancestor[ancr.first][j].first) {
				ancl = Op.funcLca(ancestor[ancl.first][j],ancl);
				ancr = Op.funcLca(ancestor[ancr.first][j],ancr);
			}
		}
		ancl = Op.funcLca(ancestor[ancl.first][0],ancl);
		ancr = Op.funcLca(ancestor[ancr.first][0],ancr);
		return Op.funcLca(ancl,ancr);
	}
	//O(N) anytime
	int diameter(void){
		makeDepth(0);
		int tmp = max_element(depth.begin(), depth.end()) - depth.begin();
		makeDepth(tmp);
		return *max_element(depth.begin(), depth.end());
	}
};
template<class typeDist> struct treeOperator{
	static const size_t bit = 20;
	typeDist unitDist = 0;
	typeDist unitLca = 0;
	typeDist funcDist(const typeDist& parent,const typeDist& w){return parent+w;}
	pair<size_t,typeDist> funcLca(const pair<size_t,typeDist>& l,const pair<size_t,typeDist>& r){return make_pair(l.first,max(l.second,r.second));}
};
 
//depth,dist
//https://atcoder.jp/contests/abc126/tasks/abc126_d
//child
//https://atcoder.jp/contests/abc133/tasks/abc133_e
//lca
//https://atcoder.jp/contests/abc014/tasks/abc014_4
//weighted lca
//diameter
//https://atcoder.jp/contests/agc033/tasks/agc033_c
//eulerTour
//https://yukicoder.me/problems/no/900

// Tree<treeOperator<int>> tree(N);

int main() {
	int N, M; cin >> N >> M;
	UnionFindTree uf(N);
	vector<int> a(M), b(M);
	vector<ll> c(M);
	vector<pair<ll, int>> ord(M);
	for(int i = 0; i < M; ++i){
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		ord[i] = { c[i],i };
	}
	sort(ALL(ord));
 
	Tree<treeOperator<ll>> tree(N);
	ll sum = 0;
	for (int i = 0; i < M; ++i){
		int j = ord[i].second;
		if (uf.same(a[j], b[j])) {
			a[j] = b[j] = -1;
		}
		else {
			uf.unite(a[j], b[j]);
			sum += c[j];
			tree.makeEdge(a[j], b[j], c[j]);
			tree.makeEdge(b[j], a[j], c[j]);
		}
	}
	tree.makeDepth(0);
	vector<vector<int>> edge(N, vector<int>(20,0));
	for (int i = 0; i < M; ++i) {
		if (a[i] == -1 || b[i] == -1) continue;
		if (tree.depth[a[i]] < tree.depth[b[i]]) swap(a[i], b[i]);
		edge[a[i]][0] = c[i];
	}
 
	tree.makeParent();
	tree.makeAncestor();
	for (int bit = 1; bit < 20; ++bit) {
		for (int i = 0; i < N; ++i) {
			edge[i][bit] = max(edge[tree.ancestor[i][bit - 1].first][bit - 1], edge[i][bit - 1]);
		}
	}
	int Q; cin >> Q;
	vector<ll> ans(Q);
	for(int i = 0; i < Q; ++i){
		int s, t; cin >> s >> t;
		s--, t--;
		ans[i] = sum - tree.lca(s, t).second;
	}
	for (int i = 0; i < Q; ++i) cout << ans[i] << endl;
	return 0;
}
