// need
#include <iostream>
#include <algorithm>

// data structure
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
//#include <deque>
#include <valarray>

// stream
//#include <istream>
//#include <sstream>
//#include <ostream>
#include <fstream>

// etc
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>

// input
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest&...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int i=0; i<n; ++i){MACRO_VEC_ROW_Scan(i, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest&...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { std::cin >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest&...rest) { std::cin >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& r:c)for(auto& i:r)std::cin>>i;

// output
#define OUT(d) std::cout<<(d);
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<(d);
#define SOUT(n, c, d) std::cout<<std::setw(n)<<std::setfill(c)<<(d);
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(i, n) std::cout<<(i + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define SHOW(d) {std::cerr << #d << "\t:" << (d) << "\n";}
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t:";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}

// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define FORLL(i, a, b) for(ll i=ll(a);i<ll(b);++i)
#define RFORLL(i, a, b) for(ll i=ll(b)-1;i>=ll(a);--i)
#define REPLL(i, n) for(ll i=0;i<ll(n);++i)
#define RREPLL(i, n) for(ll i=ll(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
template<typename T> inline T CHMAX(T& a, const T b) { return a = (a < b) ? b : a; }
template<typename T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }
#define EXCEPTION(msg) throw std::string("Exception : " msg " [ in ") + __func__ + " : " + std::to_string(__LINE__) + " lines ]"
#define TRY(cond, msg) try {if (cond) EXCEPTION(msg);}catch (std::string s) {std::cerr << s << std::endl;}
void CHECKTIME(std::function<void()> f) { auto start = std::chrono::system_clock::now(); f(); auto end = std::chrono::system_clock::now(); auto res = std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count(); std::cerr << "[Time:" << res << "ns  (" << res / (1.0e9) << "s)]\n"; }

// test
template<class T> std::vector<std::vector<T>> VV(int n, int m, T init = T()) {
	return std::vector<std::vector<T>>(n, std::vector<T>(m, init));
}
template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = 1 << 30;                          // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                          // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
constexpr double EPS = 1e-9;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;

template<class T, size_t N> void FILL(T(&a)[N], const T& val) { for (auto& x : a) x = val; }
template<class ARY, size_t N, size_t M, class T> void FILL(ARY(&a)[N][M], const T& val) { for (auto& b : a) FILL(b, val); }
template<class T> void FILL(std::vector<T>& a, const T& val) { for (auto& x : a) x = val; }
template<class ARY, class T> void FILL(std::vector<std::vector<ARY>>& a, const T& val) { for (auto& b : a) FILL(b, val); }

// ------------>8------------------------------------->8------------

//Union-Find
class UnionFind {
private:
	std::vector<int> parent;
	std::vector<int> height;
	std::vector<int> m_size;

public:
	UnionFind(int size_) : parent(size_), height(size_, 0), m_size(size_, 1) {
		for (int i = 0; i < size_; ++i) parent[i] = i;
	}
	void init(int size_) {
		parent.resize(size_);
		height.resize(size_, 0);
		m_size.resize(size_, 0);
		for (int i = 0; i < size_; ++i) parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		int t = size(x) + size(y);
		m_size[x] = m_size[y] = t;
		if (height[x] < height[y]) parent[x] = y;
		else parent[y] = x;
		if (height[x] == height[y]) ++height[x];
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		if (parent[x] == x) return m_size[x];
		return size(parent[x] = find(parent[x]));
	}
};

// write [ LCA lca(g, root); ] when using this snippet.
class LCA {
private:
	const std::vector<std::vector<int>>& graph; // graph's list expression
	int root;
	int n; // the number of nodes
	int log2n; // = floor(log2(n)) + 1
	std::vector<std::vector<int>> parent; // parent[x][v] = a parent(above 2^x) of v (nonexistence -> -1)
	std::vector<int> depth; // the depth of each node

public:
	LCA(const std::vector<std::vector<int>>& graph, int root) :
		graph(graph), root(root), n(graph.size()),
		log2n(std::floor(std::log2(n) + 1)),
		parent(log2n, std::vector<int>(n, 0)), depth(n, 0)
	{
		init();
	}

	// Check the depth of each node(node "v" -> parent is "p", depth is "d")
	void dfs(int v, int p, int d) {
		std::stack<int> stack;
		stack.push(v);
		parent[0][v] = p;
		depth[v] = d;
		while (!stack.empty()) {
			int now = stack.top(); stack.pop();
			for (int i = 0; i < graph[now].size(); ++i) {
				int to = graph[now][i];
				if (to == parent[0][now]) continue;
				parent[0][to] = now;
				depth[to] = depth[now] + 1;
				stack.push(to); // Check each child of v
			}
		}
	}

	// Initialize
	void init() {
		// Initialize "parent[0]" and "depth"
		dfs(root, -1, 0);

		// Initialize "parent"
		for (int k = 0; k < log2n - 1; ++k) {
			for (int v = 0; v < n; ++v) {
				if (parent[k][v] < 0) { // If parent above 2^k of v is nonexistence
					parent[k + 1][v] = -1;
				}
				else {
					parent[k + 1][v] = parent[k][parent[k][v]];
				}
			}
		}
	}

	// Find LCA of (u, v)
	int lca(int u, int v) {
		// go up parent while depth of u and v is same
		if (depth[u] > depth[v]) std::swap(u, v);
		for (int k = 0; k < log2n; ++k) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v]; // go up to 2^k if k-th binary is 1
			}
		}

		if (u == v) return u; // this case is that v is in u's subtree

		// Find LCA by binary searching
		for (int k = log2n - 1; k >= 0; --k) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};

signed main() {
	INIT;

	VAR(int, n, m);
	VEC_ROW(int, m, a, b, c);
	std::vector<std::vector<PAIR>> g(n);
	std::vector<PAIR> edge(m);
	REP(i, m) {
		--a[i]; --b[i];
		g[a[i]].emplace_back(b[i], c[i]);
		g[b[i]].emplace_back(a[i], c[i]);
		edge[i] = PAIR(c[i], i);
	}
	std::sort(ALL(edge));

	// 最小全域木
	std::vector<std::vector<PAIR>> G(n); // (to, cost)
	std::vector<std::vector<int>> G_(n); // 辺情報のみ(LCAで使う)
	UnionFind uf(n);
	int sum = 0;
	for (auto& p : edge) {
		auto ei = p.second;
		int A = a[ei], B = b[ei], C = c[ei];
		if (uf.same(A, B)) continue;
		uf.unite(A, B);
		G[A].emplace_back(B, C);
		G[B].emplace_back(A, C);
		G_[B].emplace_back(A);
		G_[A].emplace_back(B);
		sum += C;
	}

	// LCA構成，根を0とする
	LCA lca(G_, 0);

	// 親を調べる
	std::vector<PAIR> par(n, PAIR(-1, 0)); // (親, 親へのコスト)
	std::function<void(int, int)> dfs = [&](int v, int pa) {
		for (auto& e : G[v]) if (e.first != pa) {
			par[e.first] = PAIR(v, e.second);
			dfs(e.first, v);
		}
	};
	dfs(0, -1);

	// クエリ
	VAR(int, Q);
	REP(_, Q) {
		VAR(int, s, t);
		--s; --t;

		int u = lca.lca(s, t);
		int ma = 0;
		while (s != u) {
			CHMAX(ma, par[s].second);
			s = par[s].first;
		}
		while (t != u) {
			CHMAX(ma, par[t].second);
			t = par[t].first;
		}
		OUT(sum - ma)BR;
	}

	return 0;
}