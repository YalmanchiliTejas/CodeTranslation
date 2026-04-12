#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 10;

struct flow_network {
	int n;
	struct edge { int v; ll c; int rev; };
	vector< vector<edge> > G;
	flow_network(int _n) : n(_n), G(_n) {}
	void add_edge(int u, int v, ll c) {
		edge e = {v, c, (int)G[v].size()}, _e = {u, 0, (int)G[u].size()};
		G[u].push_back(e); G[v].push_back(_e);
	}
	ll dfs(int u, int t, ll f, vector<bool>& vis) {
		if (u == t) return f;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++) {
			edge& e = G[u][i];
			if (vis[e.v] || e.c == 0) continue;
			ll d = min(e.c, dfs(e.v, t, min(f, e.c), vis));
			if (d == 0) continue;
			e.c -= d;
			G[e.v][e.rev].c += d;
			return d;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		ll res = 0;
		for (;;) {
			vector<bool> vis(n);
			ll f = dfs(s, t, LLONG_MAX, vis);
			if (f == 0) return res;
			res += f;
		}
	}
};

int main() {
	for (;;) {
		int H, W, C, M, NW, NC, NM;
		cin >> H >> W >> C >> M >> NW >> NC >> NM;
		if (H < 0) break;
		vector<vector<bool> >
			hw(H+1, vector<bool>(W+NW+1)),
			wc(W+NW+1, vector<bool>(C+NC+1)),
			cm(C+NC+1, vector<bool>(M+NM+1));
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W+NW; j++)
				hw[i][j] = (i < H) ^ (j < W);
		for (int i = 0; i < W+NW; i++)
			for (int j = 0; j < C+NC; j++)
				wc[i][j] = (i < W) ^ (j < C);
		for (int i = 0; i < C+NC; i++)
			for (int j = 0; j < M+NM; j++)
				cm[i][j] = (i < C) ^ (j < M);
		for (int i = 0; i < W; i++) {
			int n; cin >> n;
			while (n--) {
				int j; cin >> j;
				hw[j - 1][i] = true;
			}
		}
		for (int i = 0; i < C; i++) {
			int n; cin >> n;
			while (n--) {
				int j; cin >> j;
				wc[j - 1][i] = true;
			}
		}
		for (int i = 0; i < M; i++) {
			int n; cin >> n;
			while (n--) {
				int j; cin >> j;
				cm[j - 1][i] = true;
			}
		}
		flow_network fn((H + W+NW + C+NC + M+NM) * 2 + 2);
		int h = 0, w = H, c = H + W+NW, m = H + W+NW + C+NC;
		int x = H + W+NW + C+NC + M+NM, s = x * 2, t = x * 2 + 1;
		for (int j = 0; j < H; j++)
			fn.add_edge(s, h+j, INF);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W+NW; j++)
				fn.add_edge(x+h+i, w+j, hw[i][j]);
		for (int i = 0; i < W+NW; i++)
			for (int j = 0; j < C+NC; j++)
				fn.add_edge(x+w+i, c+j, wc[i][j]);
		for (int i = 0; i < C+NC; i++)
			for (int j = 0; j < M+NM; j++)
				fn.add_edge(x+c+i, m+j, cm[i][j]);
		for (int i = 0; i < M+NM; i++)
			fn.add_edge(x+m+i, t, INF);
		for (int i = 0; i < H; i++)
			fn.add_edge(h+i, x+h+i, 1);
		for (int i = 0; i < W+NW; i++)
			fn.add_edge(w+i, x+w+i, 1);
		for (int i = 0; i < C+NC; i++)
			fn.add_edge(c+i, x+c+i, 1);
		for (int i = 0; i < M+NM; i++)
			fn.add_edge(m+i, x+m+i, 1);
		cout << fn.max_flow(s, t) << endl;
	}
}