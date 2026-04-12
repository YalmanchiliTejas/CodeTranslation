#include <bits/stdc++.h>
using namespace std;

template <class T = long long>
struct edge {
	T len;
	int from;
	int to;
	bool operator<(const edge a) const {
		if(len != a.len) return len < a.len;
		if(from != a.from) return from < a.from;
		return to < a.to;
	}
	bool operator>(const edge a) const {
		if(len != a.len) return len > a.len;
		if(from != a.from) return from > a.from;
		return to > a.to;
	}
};
template <class T = long long>
struct graph {	// 0-indexed
	T const INF = numeric_limits<T>::max() / 3;
	vector<vector<edge<T>>> edges;
	bool directed, weight;
	int ver;

	// constructor
	graph(int vertex, bool direction = 0, bool weigh = 0) : edges(vertex) {
		ver = vertex;
		directed = direction;
		weight = weigh;
		edges.resize(vertex);
	}

	//辺の追加 (0-indexed)
	void update(int from, int to, T len = 1, bool direction = 1) {
		edge<T> e;
		e.len = len;
		e.from = from;
		e.to = to;
		edges[from].push_back(e);
		if(!direction) {
			swap(e.to, e.from);
			edges[to].push_back(e);
		}
	}

	//入力受取 (1-indexed)
	void input(int edge_num, int index = 1) {
		for(int i = 0; i < edge_num; i++) {
			int a;
			int b;
			cin >> a >> b;
			a -= index;
			b -= index;
			T c;
			if(weight)
				cin >> c;
			else
				c = 1;
			update(a, b, c, directed);
		}
	}

	// 辺の長さを全て1とみたときの単一始点最短経路 (無理なときはINF)
	vector<T> bfs(int start) {
		// https://atcoder.jp/contests/abc007/submissions/me
		vector<T> ret(ver, INF);
		queue<int> q;
		q.push(start);
		ret[start] = 0;
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(ret[e.to] != INF) continue;
				q.push(e.to);
				ret[e.to] = ret[now] + 1;
			}
		}
		return ret;
	}

	//長さが負のpathがないときの単一始点最短経路<vll> O((ver)log(ver)+(edge))
	vector<T> dijkstra(int start) {
		vector<T> ret(ver, (T)INF);
		// pqup<pair<T, int>> p;														   //{dist,place}
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> p;  //{dist,place}
		p.push({0, start});
		ret[start] = 0;

		while(!p.empty()) {
			T dist = p.top().first;
			int place = p.top().second;
			p.pop();
			if(ret[place] < dist) continue;
			for(auto &next : edges[place]) {
				int nextplace = next.to;
				T dis = next.len;
				if(ret[nextplace] > dist + dis) {
					ret[nextplace] = dist + dis;
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	//単一始点最短経路 O((ver)*(edge))
	//辿り着けないとき ret[i] = INF;
	//ある頂点までのコストが無限に小さくなり得るとき→ ret[i] = -INF;
	vector<T> BellmanFord(int start) {
		// https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
		vector<T> ret(ver, INF);
		ret[start] = 0;
		for(int loop = 0; loop < ver - 1; loop++) {
			for(int v = 0; v < ver; v++) {
				if(ret[v] == INF) continue;
				for(auto &e : edges[v]) {
					ret[e.to] = min(ret[e.to], ret[v] + e.len);
				}
			}
		}

		//無限降下点の検索
		queue<int> q;
		vector<bool> chk(ver, 0);
		for(int v = 0; v < ver; v++) {
			if(ret[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(ret[e.to] > ret[v] + e.len) {
					ret[e.to] = ret[v] + e.len;
					if(!chk[e.to]) {
						q.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		for(int i = 0; i < ver; i++)
			if(chk[i]) ret[i] = -INF;

		return ret;
	}

	//閉路に含まれない頂点列挙
	//要素数がver未満なら閉路が存在、そうでなければ閉路は存在しない
	vector<int> topo_sort() {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_A
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
		assert(directed);
		vector<int> num_input(ver);
		// 入次数
		for(int i = 0; i < ver; i++) {
			for(auto e : edges[i]) {
				num_input[e.to]++;
			}
		}
		// 入次数が0のノードをqueueで管理する
		queue<int> que;
		for(int i = 0; i < ver; i++) {
			if(num_input[i] == 0) {
				que.push(i);
			}
		}
		vector<int> ans;
		while(!que.empty()) {
			auto node = que.front();
			que.pop();
			ans.push_back(node);
			// 頂点の削除
			for(auto e : edges[node]) {
				num_input[e.to]--;
				// 行き先の入次数が0になったらqueueに追加
				if(num_input[e.to] == 0) {
					que.push(e.to);
				}
			}
		}
		return ans;
	}

	//{{端点、端点},直径の大きさ}
	pair<pair<int, int>, T> DiameterOfTree(bool weigh = true) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A
		vector<T> vec;
		vec = weigh ? dijkstra(0) : bfs(0);
		int v1 = -1;
		T dia = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				dia = vec[i];
				v1 = i;
			}

		vec = weigh ? dijkstra(v1) : bfs(v1);
		dia = -1;
		int v2 = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				v2 = i;
				dia = vec[i];
			}

		pair<pair<int, int>, T> ans = {{v1, v2}, dia};
		return ans;
	}

	//無向木構造を根から葉に伸びる有向木構造に書き換える
	graph<T> RootToLeaf(int root) {	 // 0-indexed
		graph<T> ret(ver, 1, weight);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(now, e.to, e.len, 1);
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	//無向木構造を葉から根に伸びる有向木構造に書き換える
	graph<T> LeafToRoot(int root) {	 // 0-indexed
		graph<T> ret(ver, 1, weight);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(e.to, now, e.len, 1);
				dfs(e.to);
			}
		};
		dfs(root);
		ret.update(root, root, 0);
		return ret;
	}

	// LeafToRootのvector版.par[i]=iの親の頂点
	vector<int> par(int root) {	 // 0-indexed
		vector<int> ret(ver, -1);
		ret[root] = root;  // rootの親はroot
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(ret[e.to] != -1) continue;
				ret[e.to] = now;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}
	vector<edge<T>> ParentAndDistance(int root) {  // 0-indexed
		vector<edge<T>> ret(ver);
		for(int i = 0; i < ver; i++) ret[i].to = -1;
		ret[root].to = root;  // rootの親はroot
		ret[root].len = 0;	  // rootの親との距離は0
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(ret[e.to].to != -1) continue;
				ret[e.to].to = now;
				ret[e.to].len = e.len;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	//隣接sheet.主にwarshall用
	vector<vector<T>> GraphArray(void) {
		vector<vector<T>> ret(ver, vector<T>(ver, INF));
		for(int from = 0; from < ver; from++) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}

	graph<T> Prim(int start = 0) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A
		graph<T> ret(ver, 0, 1);
		priority_queue<edge<T>, vector<edge<T>>, greater<edge<T>>> p;
		for(auto &e : edges[start]) {
			p.push(e);
		}
		vector<bool> chk(ver, 0);
		chk[start] = 1;
		while(!p.empty()) {
			auto ed = p.top();
			p.pop();
			if(chk[ed.to]) continue;
			chk[ed.to] = 1;
			ret.update(ed.from, ed.to, ed.len);
			for(auto &e : edges[ed.to]) {
				p.push(e);
			}
		}
		return ret;
	}

	//各頂点を根としたときの木の高さ
	vector<T> height(int start = 0) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_B
		vector<T> fir(ver, -1), sec(ver, -1);
		function<T(int, int)> dfs = [&](int now, int par) {
			T f = 0, s = 0;	 // startを根としたときのnowからの深さ1番目、2番目
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				s = max(s, dfs(e.to, now) + e.len);
				if(f < s) swap(f, s);
			}
			sec[now] = s;
			return fir[now] = f;
		};
		dfs(start, -1);
		function<void(int, int, T, T, T)> sol = [&](int now, int par, T parf, T pars, T parlen) {
			if(fir[now] + parlen == parf) parf = pars;
			sec[now] = max(sec[now], parf + parlen);
			if(fir[now] < sec[now]) swap(fir[now], sec[now]);
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				sol(e.to, now, fir[now], sec[now], e.len);
			}
			return;
		};
		sol(start, -1, -1, -1, -1);
		return fir;
	}

	// lowest common ancestor
	// max-flow -> 別ファイル
	// 強連結成分分解
	// HL分解
};

struct LCA {
	// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C
	int ver;
	int h;	//最大ダブリング回数
	int rt;
	vector<int> par;
	vector<vector<int>> anc;
	vector<int> depth;

	LCA(int _ver, vector<int> _par) : ver(_ver), par(_par), depth(_ver, -1) {
		for(int i = 0; i < ver; i++) {
			if(i == par[i]) rt = i;
		}
		anc.push_back(_par);
		vector<int> nxt(_ver);
		bool f = 1;
		int i = 0;
		while(f) {
			f = 0;
			for(int j = 0; j < _ver; j++) {
				if((nxt[j] = anc[i][anc[i][j]]) != rt) {
					f = 1;
				}
			}
			anc.push_back(nxt);
			i++;
		}
		h = (int)anc.size();
	}

	int dep(int now) {
		if(depth[now] != -1) return depth[now];
		if(now == rt) return depth[rt] = 0;
		return depth[now] = dep(par[now]) + 1;
	}

	int Lowest_Common_Ancestor(int x, int y) {
		int dx = dep(x), dy = dep(y);
		// 深さを揃える
		if(dx < dy) {
			int diff = dy - dx;
			for(int i = 0; i < h; i++) {
				if(diff & (1 << i)) {
					y = anc[i][y];
				}
			}
		} else {
			int diff = dx - dy;
			for(int i = 0; i < h; i++) {
				if(diff & (1 << i)) {
					x = anc[i][x];
				}
			}
		}
		if(x == y) return x;
		for(int i = h - 1; i > -1; i--) {
			if(anc[i][x] != anc[i][y]) {
				x = anc[i][x];
				y = anc[i][y];
			}
		}
		return par[x];
	}

	int distance(int x, int y) { return dep(x) + dep(y) - 2 * dep(Lowest_Common_Ancestor(x, y)); }
};

template <class T>	// WarshallFloyd
void warshall(vector<vector<T>> &v, T dekai = numeric_limits<T>::max()) {
	int n = v.size();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++) {
				if(v[j][i] == dekai || v[i][k] == dekai) continue;
				v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
			}
	return;
}

// #pragma region macros_and_aliases
// #define rep(i, n) for(long long i = 0; i < (n); i++)
// #define rrep(i, n) for(long long i = (n)-1; i > -1; i--)
// #define Rep(i, m, n) for(long long i = (m); i < (n); i++)
// #define rRep(i, m, n) for(long long i = (n)-1; i >= (m); i--)
// #define REP(i, m, n, p) for(long long i = m; i < n; i += p)
// #define foa(s, v) for(auto &s : v)
// #define all(v) (v).begin(), (v).end()
// #define rall(v) (v).rbegin(), (v).rend()
// #define pq priority_queue
// #define bcnt(n) __builtin_popcountll(n)
// #define endk endl
// #define ednl endl
// #define enld endl
// using ll = long long;
// using ld = long double;
// using vll = vector<ll>;
// using vvll = vector<vll>;
// using vvvll = vector<vvll>;
// using vb = vector<bool>;
// using mll = map<long long, long long>;
// using pll = pair<long long, long long>;
// using qll = queue<long long>;
// using sll = set<long long>;
// using vpll = vector<pair<long long, long long>>;
// template <class T = ll>
// using V = vector<T>;
// template <class T = ll>
// using VV = V<V<T>>;
// template <class T = ll>
// using VVV = V<V<V<T>>>;
// //昇順pq(小さい方から取り出す)
// template <class T = ll>
// using pqup = priority_queue<T, vector<T>, greater<T>>;
// //降順pq(大きい方から取り出す)
// template <class T = ll>
// using pqdn = priority_queue<T>;
// #define debug(var)              \
// 	std::cout << #var << " : "; \
// 	view(var)
// template <typename T>
// void view(T e) {
// 	std::cout << e << std::endl;
// }
// template <typename T>
// void view(const std::vector<T> &v) {
// 	for(const auto &e : v) {
// 		std::cout << e << " ";
// 	}
// 	std::cout << std::endl;
// }
// template <typename T>
// void view(const std::vector<std::vector<T>> &vv) {
// 	for(const auto &v : vv) {
// 		view(v);
// 	}
// }
// template <typename T1, typename T2>
// ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
// 	os << p.first << " " << p.second;
// 	return os;
// }
// template <typename T1, typename T2>
// istream &operator>>(istream &is, pair<T1, T2> &p) {
// 	is >> p.first >> p.second;
// 	return is;
// }
// #pragma endregion
// #pragma region constants
// long long const limLL = 9223372036854775807;  // POW(2,63)-1 ~ 9.22e18
// long long const dekai = 3e16;
// const long double pi = acos(-1);
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int mod = 1000000007;
// // const int mod = 998244353;
// #pragma endregion
// #pragma region precedures
// template <class T>
// inline bool chmin(T &a, T b) {
// 	if(a > b) {
// 		a = b;
// 		return true;
// 	}
// 	return false;
// }
// template <class T>
// inline bool chmax(T &a, T b) {
// 	if(a < b) {
// 		a = b;
// 		return true;
// 	}
// 	return false;
// }
// #pragma endregion

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	graph<long long> gra(n, 0, 1);
	gra.input(n - 1, 0);
	auto h = gra.height();
	for(auto a:h) cout<<a<<endl;
}

