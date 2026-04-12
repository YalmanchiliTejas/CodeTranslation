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
lint numpath[2][100010];
const lint MOD = (lint)1e9 + 7;

void calcDist(int piv, int start) {
	priority_queue< Edge, Vec< Edge >, greater< Edge > > que;
	que.push(Edge{start, 0});
	dst[piv][start] = 0;
	numpath[piv][start] = 1;
	while (!que.empty()) {
		Edge e = que.top(); que.pop();
		if (dst[piv][e.v] < e.d) continue;
		for (const Edge& ei : edge[e.v]) {
			if (dst[piv][ei.v] == -1 || dst[piv][ei.v] > e.d + ei.d) {
				dst[piv][ei.v] = e.d + ei.d;
				numpath[piv][ei.v] = numpath[piv][e.v];
				que.push(Edge{ei.v, dst[piv][ei.v]});
			} else if (dst[piv][ei.v] == e.d + ei.d) {
				modAdd(numpath[piv][ei.v], numpath[piv][e.v], MOD);
			}
		}
	}
}

void solve() {
	memset(dst, -1, sizeof(dst));
	calcDist(0, S);
	calcDist(1, T);
	
	lint collision = 0;	
	
	for_(v,0,N) {
		if (dst[0][v] == dst[1][v] && dst[0][v] + dst[1][v] == dst[0][T]) {
			lint num = (numpath[0][v] * numpath[1][v]) % MOD;
			modAdd(collision, num * num, MOD);
		}
	}
	
	double thr = (double)dst[0][T] / 2.;
	for_(i,0,M) {
		int u = U[i], v = V[i], d = D[i];
		if (abs(dst[0][v] - dst[0][u]) == d) {
			if (dst[0][v] + d == dst[0][u]) swap(u, v);
			if (dst[0][u] + dst[1][v] + d == dst[0][T] && (double)dst[0][u] < thr && (double)(dst[0][u] + d) > thr) {
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