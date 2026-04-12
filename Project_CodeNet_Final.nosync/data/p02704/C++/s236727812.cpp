#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define cerr if (false) cerr

struct Edge {
	int u, v;
	int cap, flow;

	Edge(int u_, int v_, int cap_, int flow_) : u(u_), v(v_), cap(cap_), flow(flow_){}
};

const int N = 502;
const int LIM = N * N;

namespace MaxFlow {
	const int INF = 1e9 + 239;
	const int MAX_LOG = 1;

	int n;
	int start;
	int end;

	int d[LIM];
	int pnt[LIM];
	vector<int> g[LIM];

	vector<Edge> ed;

	int dfs(int u, int flow) {
		if (flow == 0) {
			return 0;
		}
		if (u == end) {
			return flow;
		}
		for (; pnt[u] < (int)g[u].size(); pnt[u]++) {
			int ind = g[u][pnt[u]];
			int to = ed[ind].v;
			if (d[to] < d[u] + 1) {
				continue;
			}
			int pushed = dfs(to, min(flow, ed[ind].cap - ed[ind].flow));
			if (pushed > 0) {
				ed[ind].flow += pushed;
				ed[ind ^ 1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	bool bfs(int lim) {
		for (int i = 0; i < n; i++) {
			d[i] = INF;
		}
		d[start] = 0;
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto ind : g[u]) {
				int to = ed[ind].v;
				if (d[to] > d[u] + 1 && ed[ind].flow + lim <= ed[ind].cap) {
					d[to] = d[u] + 1;
					q.push(to);
				}
			}
		}
		return d[end] < INF;
	}

	void init(int n_, int start_, int end_) {
		n = n_;
		start = start_;
		end = end_;
		ed.clear();
		fill(d, d + n, 0);
		fill(pnt, pnt + n, 0);
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
	}

	int add_edge(int u, int v, int c) {
		assert(u < n);
		assert(v < n);
		int pnt_ed = (int)ed.size();
		ed.push_back(Edge(u, v, c, 0));
		ed.push_back(Edge(v, u, 0, 0));
		g[u].push_back(pnt_ed);
		g[v].push_back(pnt_ed + 1);
		return pnt_ed;
	}

	int solve() {
		int ans = 0;
		for (int i = MAX_LOG; i >= 0; i--) {
			while (bfs(1LL << i)) {
				fill(pnt, pnt + n, 0);
				while (true) {
					int nw = dfs(start, INF);
					if (nw > 0) {
						ans += nw;
					} else {
						break;
					}
				}
			}
		}
		return ans;
	}
};

int s[N];
int t[N];
int ub[N];
int vb[N];
int tans[N][N];

int solve_bit(int n) {
	int all_ok = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tans[i][j] = -1;
		}
	}
	auto safe_set = [&](int i, int j, int val) {
		if (tans[i][j] != -1 && tans[i][j] != val) {
			all_ok = 0;
		}
		tans[i][j] = val;
	};
	vector<int> need_row(n, -1);
	vector<int> need_col(n, -1);
	for (int i = 0; i < n; i++) {
		if (s[i] == 0 && ub[i] == 1) {
			// cerr << "R " << i << ' ' << 0 << endl;
			for (int j = 0; j < n; j++) {
				safe_set(i, j, 1);
			}
		} else if (s[i] == 1 && ub[i] == 0) {
			// cerr << "R " << i << ' ' << 1 << endl;
			for (int j = 0; j < n; j++) {
				safe_set(i, j, 0);
			}
		} else {
			if (s[i] == 0) {
				need_row[i] = 0;
			} else {
				need_row[i] = 1;
			}
		}

	}
	for (int j = 0; j < n; j++) {
		if (t[j] == 0 && vb[j] == 1) {
			for (int i = 0; i < n; i++) {
				safe_set(i, j, 1);
			}
		} else if (t[j] == 1 && vb[j] == 0) {
			for (int i = 0; i < n; i++) {
				safe_set(i, j, 0);
			}	
		} else {
			if (t[j] == 0) {
				need_col[j] = 0;
			} else {
				need_col[j] = 1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tans[i][j] == -1 && need_row[i] != -1 && need_row[i] == need_col[j]) {
				cerr << "ADD " << i << ' ' << j << endl;
				safe_set(i, j, need_row[i]);
			}
			if (tans[i][j] != -1) {
				if (tans[i][j] == need_row[i]) {
					need_row[i] = -1;
				}
				if (tans[i][j] == need_col[j]) {
					need_col[j] = -1;
				}
			}
		}
	}
	{
		cerr << "need_row: " << endl;
		for (auto x : need_row) {
			cerr << x << ' ';
		}
		cerr << endl;
	}
	
	{
		cerr << "need_col: " << endl;
		for (auto x : need_col) {
			cerr << x << ' ';
		}
		cerr << endl;
	}
	if (!all_ok) {
		return 0;
	}
	cerr << "HR " << endl;
	vector<pair<int, int>> iv;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tans[i][j] == -1) {
				cerr << "EMP " << i << ' ' << j << endl;
				iv.push_back({i, j});
			}
		}
	}
	//who if0 if1
	int pnt = (int)iv.size();
	vector<int> v_row(n, -1);
	vector<int> v_col(n, -1);
	for (int i = 0; i < n; i++) {
		if (need_row[i] != -1) {
			cerr << "R: " << i << ' ' << need_row[i] << '\n';
			v_row[i] = pnt;
			pnt++;
		}
	}
	for (int j = 0; j < n; j++) {
		if (need_col[j] != -1) {
			cerr << "C: " << j << ' ' << need_col[j] << '\n';
			v_col[j] = pnt;
			pnt++;
		}
	}
	int st = pnt;
	int en = pnt + 1;
	MaxFlow::init(pnt + 2, st, en);
	cerr << "INIT OK" << endl;
	vector<int> ed_i(iv.size(), -1);
	vector<int> ed_r(iv.size(), -1);
	vector<int> ed_c(iv.size(), -1);
	for (int i = 0; i < (int)iv.size(); i++) {
		cerr << "+" << endl;
		ed_i[i] = MaxFlow::add_edge(st, i, 1);
		int ri, rj;
		tie(ri, rj) = iv[i];
		cerr << ri << ' ' << rj << endl;
		if (v_row[ri] != -1) assert(need_row[ri] != need_col[rj]);
		if (v_row[ri] != -1) {
			ed_r[i] = MaxFlow::add_edge(i, v_row[ri], 1);
		}
		if (v_col[rj] != -1) {
			ed_c[i] = MaxFlow::add_edge(i, v_col[rj], 1);
		}
		cerr << "~" << endl; 		
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (v_row[i] != -1) {
			MaxFlow::add_edge(v_row[i], en, 1);
			c++;
		}
	}
	for (int j = 0; j < n; j++) {
		if (v_col[j] != -1) {
			MaxFlow::add_edge(v_col[j], en, 1);
			c++;
		}
	}
	cerr << "STARTING FLOW " << c << endl;
	int fl = MaxFlow::solve();
	cerr << "FLOW OK" << endl;
	if (c != fl) {
		return 0;
	}
	for (int i = 0; i < (int)iv.size(); i++) {
		int ri, rj;
		tie(ri, rj) = iv[i];
		if (ed_r[i] != -1 && MaxFlow::ed[ed_r[i]].flow) {
			tans[ri][rj] = need_row[ri];
		} else if (ed_c[i] != -1 && MaxFlow::ed[ed_c[i]].flow) {
			tans[ri][rj] = need_col[rj];
		}  else {
			assert(MaxFlow::ed[ed_i[i]].flow == 0);
			tans[ri][rj] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			assert(tans[i][j] == 0 || tans[i][j] == 1);
		}
	}
	return 1;
}

typedef unsigned long long ull; 

const int K = 64;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<ull>> ans(n, vector<ull> (n));
	vector<ull> u(n);
	vector<ull> v(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (auto &x : u) {
		cin >> x;
	}
	for (auto &x : v) {
		cin >> x;
	}
	int ok = 1;
	for (int i = 0; i < K; i++) {
		vector<int> nu(n);
		vector<int> nv(n);
		for (int j = 0; j < n; j++) {
			ub[j] = ((u[j] >> i) & 1);
			vb[j] = ((v[j] >> i) & 1);
		}
		if (!solve_bit(n)) {
			ok = 0;
		}	
		for (int ff = 0; ff < n; ff++) {
			for (int ss = 0; ss < n; ss++) {
				if (tans[ff][ss] == 1) {
					ans[ff][ss] |= (1LL << i);
				}
			}
		}
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}
