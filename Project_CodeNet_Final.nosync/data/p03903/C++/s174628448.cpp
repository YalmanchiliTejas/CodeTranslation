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

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

const ll MOD = (ll)1e9 + 7;
const ll MOD2 = 998244353;
const ll LLINF = (ll)1e18;
const ll INTINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template <class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } }
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) { o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o; }
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) { o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o; }
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) { o << "{" << obj.first << ", " << obj.second << "}"; return o; }
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
void print(void) { cout << endl; }
template <class Head> void print(Head&& head) { cout << head; print(); }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) { cout << head << " "; print(forward<Tail>(tail)...); }

void YN(bool flg) { cout << ((flg) ? "YES" : "NO") << endl; }
void Yn(bool flg) { cout << ((flg) ? "Yes" : "No") << endl; }
void yn(bool flg) { cout << ((flg) ? "yes" : "no") << endl; }

//Union Find Tree
class Union_Find_Tree {
public:
	vector<int> parent;
	vector<int> rank;

	Union_Find_Tree(int N = 1) : parent(N), rank(N, 0) {
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	int root(int n) {
		return (parent[n] == n ? n : parent[n] = root(parent[n]));
	}

	bool same(int n, int m) {
		return root(n) == root(m);
	}

	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if (rank[n]<rank[m]) {
			parent[n] = m;
		}
		else {
			parent[m] = n;
			if (rank[n] == rank[m]) rank[n]++;
		}
	}
};

class Lowest_Common_Ancestor {
public:
	int N, MAX_bit;
	vector<vector<int>> edge;
	vector<int> depth;
	vector<vector<int>> parent;
	vector<vector<int>> child;
	vector<vector<int>> descendant;

	Lowest_Common_Ancestor(int N, int MAX_bit = 20) :N(N), MAX_bit(MAX_bit), edge(N), depth(N, -1), parent(N, vector<int>(MAX_bit)), child(N), descendant(N) {
		//do nothing
	}

	//O(1)
	void make_edge(int from, int to) {
		edge[from].push_back(to);
	}

	//O(N)
	void make_depth(int root) {
		queue<int> q;
		depth[root] = 0;
		q.push(root);
		while (q.size()) {
			int from = q.front();
			q.pop();
			for (auto to : edge[from]) {
				if (depth[to] != -1) continue;
				depth[to] = depth[from] + 1;
				q.push(to);
			}
		}
	}

	//O(MAX_bit*N)
	void make_parent() {
		for (int i = 0; i < N; ++i) parent[i][0] = i;
		for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) parent[i][0] = j;
		for (int bit = 1; bit < MAX_bit; ++bit) for (int i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit - 1]][bit - 1];
	}

	//O(N)
	void make_child() {
		for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);
	}

	//O(N^2)
	void make_descendant() {
		vector<pair<int, int>> ord(N);
		for (int i = 0; i < N; ++i) ord[i] = { depth[i],i };
		sort(ord.begin(), ord.end(), greater<>());
		for (int i = 0; i < N; ++i) descendant[i].push_back(i);
		for (int i = 0; i < N; ++i) for (auto j : edge[ord[i].second]) if (depth[ord[i].second] < depth[j]) for (auto k : descendant[j]) descendant[ord[i].second].push_back(k);
	}

	//O(MAX_bit*logN)
	int lca(int l, int r) {
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		for (int bit = 0; bit < MAX_bit; ++bit) if (diff & (1 << bit)) l = parent[l][bit];
		int ok = (1 << MAX_bit), ng = -1, md;
		while (ok - ng>1) {
			md = (ok + ng) / 2;
			int x = l, y = r;
			for (int bit = 0; bit < MAX_bit; ++bit) if (md & (1 << bit)) x = parent[x][bit];
			for (int bit = 0; bit < MAX_bit; ++bit) if (md & (1 << bit)) y = parent[y][bit];
			(x == y ? ok : ng) = md;
		}
		for (int bit = 0; bit < MAX_bit; ++bit) if (ok & (1 << bit)) l = parent[l][bit];
		return l;
	}

	void print() {
		cout << " depth { " << depth[0];
		for (int i = 1; i < N; ++i) cout << ", " << depth[i];
		cout << " }" << endl;

		cout << "parent { " << parent[0][0];
		for (int i = 1; i < N; ++i) cout << ", " << parent[i][0];
		cout << " }" << endl;

		cout << " child { " << child[0];
		for (int i = 1; i < N; ++i) cout << ", " << child[i];
		cout << " }" << endl;

		cout << "descen { " << descendant[0];
		for (int i = 1; i < N; ++i) cout << ", " << descendant[i];
		cout << " }" << endl;
	}

};

int main() {
	int N, M; cin >> N >> M;
	Union_Find_Tree uf(N);
	V<int> a(M), b(M);
	V<ll> c(M);
	V<P<ll, int>> ord(M);
	for(int i = 0; i < M; ++i){
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		ord[i] = { c[i],i };
	}
	sort(ALL(ord));

	Lowest_Common_Ancestor tree(N);
	ll sum = 0;
	for (int i = 0; i < M; ++i){
		int j = ord[i].second;
		if (uf.same(a[j], b[j])) {
			a[j] = b[j] = -1;
		}
		else {
			uf.unite(a[j], b[j]);
			sum += c[j];
			tree.make_edge(a[j], b[j]);
			tree.make_edge(b[j], a[j]);
		}
	}
	tree.make_depth(0);
	V<V<int>> edge(N, V<int>(20,0));
	for (int i = 0; i < M; ++i) {
		if (a[i] == -1 || b[i] == -1) continue;
		if (tree.depth[a[i]] < tree.depth[b[i]]) swap(a[i], b[i]);
		edge[a[i]][0] = c[i];
	}

	tree.make_parent();
	for (int bit = 1; bit < 20; ++bit) {
		for (int i = 0; i < N; ++i) {
			edge[i][bit] = max(edge[tree.parent[i][bit - 1]][bit - 1], edge[i][bit - 1]);
		}
	}
	int Q; cin >> Q;
	V<ll> ans(Q);
	for(int i = 0; i < Q; ++i){
		int s, t; cin >> s >> t;
		s--, t--;
		if (tree.depth[s] < tree.depth[t]) swap(s, t);
		int u = tree.lca(s, t);
		int ds = tree.depth[s] - tree.depth[u];
		int dt = tree.depth[t] - tree.depth[u];
		int es = 0;
		int et = 0;
		for (int bit = 0; bit < 20; ++bit) if (ds & (1 << bit)) {
			es = max(es, edge[s][bit]);
			s = tree.parent[s][bit];
		}
		for (int bit = 0; bit < 20; ++bit) if (dt & (1 << bit)) {
			et = max(et, edge[t][bit]);
			t = tree.parent[t][bit];
		}
		ans[i] = sum - max(es, et);
	}
	for (int i = 0; i < Q; ++i) cout << ans[i] << endl;
	return 0;
}
