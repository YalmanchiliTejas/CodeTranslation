#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
template< typename T > using Vec = vector< T >;
typedef long long lint;
template< typename T > void modAdd(T& a, T b, T mod) { a = (a + b) % mod; }

struct Edge {
	int v;
	lint d;
	bool operator > (const Edge& e) const { return d > e.d; }
};

int N, M, S, T, U[200005], V[200005];
lint D[200005];
Vec< Vec< Edge > > edge;

lint dst[2][100005];
void calcDist(int piv, int start) {
	priority_queue< Edge, Vec< Edge >, greater< Edge > > que;
	que.push(Edge{start, 0});
	dst[piv][start] = 0;
	while (!que.empty()) {
		Edge e = que.top(); que.pop();
		if (dst[piv][e.v] < e.d) continue;
		for (const Edge& ei : edge[e.v]) {
			if (dst[piv][ei.v] == -1 || dst[piv][ei.v] > e.d + ei.d) {
				dst[piv][ei.v] = e.d + ei.d;
				que.push(Edge{ei.v, dst[piv][ei.v]});
			}
		}
	}
}

lint numpath[2][100010];
const lint MOD = (lint)1e9 + 7;
void countPaths(int piv, int start) {
	Vec< Vec< int > > dag(N, Vec< int >());
	
	queue< int > que;
	que.push(start);
	Vec< bool > vis(N, false);
	vis[start] = true;
	
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (const Edge& e : edge[v]) {
			if (dst[1-piv][v] == dst[1-piv][e.v] + e.d) {
				dag[v].push_back(e.v);
				if (vis[e.v]) continue;
				que.push(e.v);
				vis[e.v] = true;
			}
		}
	}
	
	Vec< int > indeg(N, 0);
	for_(v,0,N) for (int u : dag[v]) ++indeg[u];
	
	que.push(start);
	numpath[piv][start] = 1;
	
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (int u : dag[v]) {
			modAdd(numpath[piv][u], numpath[piv][v], MOD);
			--indeg[u];
			if (indeg[u] == 0) que.push(u);
		}
	}
}

void solve() {
	memset(dst, -1, sizeof(dst));
	calcDist(0, S);
	calcDist(1, T);
	
	memset(numpath, 0, sizeof(numpath));
	countPaths(0, S);
	countPaths(1, T);
		
	lint collision = 0;
	
	Vec< bool > flag(N, false);
	
	for_(v,0,N) {
		if (dst[0][v] == dst[1][v]) {
			lint num = (numpath[0][v] * numpath[1][v]) % MOD;
			modAdd(collision, num * num, MOD);
			flag[v] = true;
		}
	}
	
	double thr = (double)dst[0][T] / 2.;
	for_(i,0,M) {
		int u = U[i], v = V[i], d = D[i];
		if (flag[u] || flag[v]) continue;
		if (abs(dst[0][v] - dst[0][u]) == d) {
			if (dst[0][v] + d == dst[0][u]) swap(u, v);
			if ((double)dst[0][u] < thr && (double)(dst[0][u] + d) > thr) {
				lint num = (numpath[0][u] * numpath[1][v]) % MOD;
				modAdd(collision, num * num, MOD);
			}
		}
	}
	
	cout << ((numpath[0][T] * numpath[1][S] - collision + MOD) % MOD) << endl;
}

int main() {
	cin >> N >> M;
	cin >> S >> T;
	--S; --T;
	
	edge.assign(N, Vec< Edge >());
	for_(i,0,M) {
		cin >> U[i] >> V[i] >> D[i];
		--U[i]; --V[i];
		edge[U[i]].push_back(Edge{V[i], D[i]});
		edge[V[i]].push_back(Edge{U[i], D[i]});
	}
	
	solve();
}