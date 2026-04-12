# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;
constexpr long long INF = numeric_limits<LL>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourth; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Mfor(i,mf) for(LL i=mf-1;i>=0;i--)
LL h, w, n, m, k, t, s, p, q, last, first, cnt, sum, ans, dp[200000];
Pll a[300000], b[300000];
string str, ss;
bool f[200];
char c, ch[100][100];
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct Edge { LL to, cost; };
struct edge { LL from, to, cost; };
vector<Edge>vec[200000];
vector<edge>v;
map<Pll,LL>ma;
multiset<LL>st;
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
struct Seg {
	LL n;
	vector<LL>node;
	Seg(LL n_) {
		n = 1; while (n < n_)n *= 2;
		node.resize(n * 2 - 1);
		rep(i, n)node[n + i - 1] = 0;
		Mfor(i, n - 2)node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
	}
	void update(LL i, LL x) {
		i = i + n - 1;
		node[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;
			node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
		}
	}
	LL find(LL i, LL a, LL b, LL l, LL r) {
		if (b< l || r < a)return 0;
		if (l <= a && b <= r)return node[i];
		return max(find(i * 2 + 1, a, (a + b) / 2, l, r), find(i * 2 + 2, (a + b + 1) / 2, b, l, r));
	}

};


int  par[100000];  // リーダーの値を格納 
int find(int x) { if (par[x] == x)return x; par[x] = find(par[x]); return par[x]; }
void unite(int x, int y) { x = find(x); y = find(y); if (x == y)return; par[x] = y; }
bool same(int x, int y) { return find(x) == find(y); }
Seg seg(100000);
struct HLD {
	LL n, pos;
	vector<vector<Edge> > G;
	vector<LL> vid, head, sub, hvy, par, dep, inv, type;

	HLD() {}
	HLD(LL sz) :
		n(sz), pos(0), G(n),
		vid(n, -1), head(n), sub(n, 1), hvy(n, -1),
		par(n), dep(n), inv(n), type(n) {}

	void add_edge(LL u, LL v, LL cos) {
		G[u].push_back(Edge{ v ,cos });
		G[v].push_back(Edge{ u,cos });
	}

	void build(vector<LL> rs = vector<LL>(1, 0)) {
		LL c = 0;
		for (LL r : rs) {
			dfs(r);
			bfs(r, c++);
		}
		update(0,-1);
	}

	void update(LL cur,LL par) {
		rep(i,G[cur].size()) {
			if (G[cur][i].to != par) {
				seg.update(vid[G[cur][i].to], G[cur][i].cost);
				update(G[cur][i].to, cur);
			}
		}
	}

	void dfs(LL rt) {
		using T = pair<LL, LL>;
		stack<T> st;
		par[rt] = -1;
		dep[rt] = 0;
		st.emplace(rt, 0);
		while (!st.empty()) {
			LL v = st.top().first;
			LL &i = st.top().second;
			if (i<(LL)G[v].size()) {
				LL u = G[v][i++].to;
				if (u == par[v]) continue;
				par[u] = v;
				dep[u] = dep[v] + 1;
				st.emplace(u, 0);
			}
			else {
				st.pop();
				LL res = 0;
				for (Edge u : G[v]) {
					if (u.to == par[v]) continue;
					sub[v] += sub[u.to];
					if (res<sub[u.to]) res = sub[u.to], hvy[v] = u.to;
				}
			}
		}
	}

	void bfs(LL r, LL c) {
		LL &k = pos;
		queue<LL> q({ r });
		while (!q.empty()) {
			LL h = q.front(); q.pop();
			for (LL i = h; i != -1; i = hvy[i]) {
				type[i] = c;
				vid[i] = k++;
				inv[vid[i]] = i;
				head[i] = h;
				for (Edge j : G[i])
					if (j .to!= par[i] && j.to != hvy[i]) q.push(j.to);
			}
		}
	}

	// for_each(vertex)
	// [l,r] <- attention!!
	void for_each(LL u, LL v, LL x, const function<void(LL, LL)>& f) {
		while (1) {
			if (vid[u] > vid[v]) swap(u, v);
			f(max(vid[head[v]], vid[u]), vid[v]);
			if (head[u] != head[v]) v = par[head[v]];
			else break;
		}
	}

	// for_each(edge)
	// [l,r] <- attention!!
	LL for_each_edge(LL u, LL v, const function<LL(LL, LL)>& f) {
		LL ret = 0;
		while (1) {
			if (vid[u]>vid[v]) swap(u, v);
			if (head[u] != head[v]) {
				ret=max(ret,f(vid[head[v]], vid[v]));
				v = par[head[v]];
			}
			else {
				if (u != v) ret = max(ret, f(vid[u] + 1, vid[v]));
				break;
			}
		}
		return ret;
	}

	LL lca(LL u, LL v) {
		while (1) {
			if (vid[u]>vid[v]) swap(u, v);
			if (head[u] == head[v]) return u;
			v = par[head[v]];
		}
	}

	LL distance(LL u, LL v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}
};
int main() {
	cin >> n >> m;
	for (int i = 0; i<n; i++)par[i] = i;  // このように初期化
	rep(i,m) {
		LL x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		v.push_back(edge{ x,y,z });
	}
	sort(v.begin(), v.end(), [](edge x, edge y) {return x.cost < y.cost; });
	HLD hld(n);
	rep(i, m) {
		if (!same(v[i].to, v[i].from)) {
			unite(v[i].to, v[i].from);
			sum += v[i].cost;
			hld.add_edge(v[i].to, v[i].from, v[i].cost);
		}
	}
	hld.build();
	cin >> q;
	rep(i, q) {
		LL x, y;
		cin >> x >> y;
		x--, y--;
		cout << sum - hld.for_each_edge(x, y, [&](LL s, LL t) {
			return seg.find(0, 0, seg.n - 1, s, t);
		}) << endl;
	}
	return 0;
}
