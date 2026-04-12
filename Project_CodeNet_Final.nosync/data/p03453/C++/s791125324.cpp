//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000
#define MAXM 200000

#define M 1000000007

vector<vector<pair<int,long>>> g;
int n, m;
int s, t;

int input() {
	if (scanf("%d %d", &n, &m) < 0) return 0;
	g.resize(n);
	scanf("%d %d", &s, &t);
	s--, t--;
	for (int i=0; i<m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		x--, y--;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	return 1;
}

void init() {
}

void dijkstra(int s, long *d, long *c) {
	typedef pair<long,int> node;
	priority_queue<node,vector<node>,greater<node>> q;
	for (int i=0; i<n; i++) {
		d[i] = LONG_MAX;
		c[i] = 0;
	}
	d[s] = 0;
	c[s] = 1;
	q.push({0, s});
	while (!q.empty()) {
		node x = q.top();
		q.pop();
		int v = x.second;
		if (x.first > d[v]) continue;
		for (auto e: g[v]) {
			int u = e.first;
			long w = d[v] + e.second;
			if (w < d[u]) {
				d[u] = w;
				c[u] = c[v];
				q.push({w, u});
			}
			else if(w == d[u]) {
				c[u] += c[v];
				c[u] %= M;
			}
		}
	}
}

long ds[MAXN], dt[MAXN];
long ns[MAXN], nt[MAXN];

void dec(long &a, long b) {
	a = (a-b) % M;
}

long solve() {
	dijkstra(s, ds, ns);
	dijkstra(t, dt, nt);
	//printa(ds, n); printa(ns, n); printa(dt, n); printa(nt, n);
	long len = ds[t];
	long r = ns[t] * nt[s] % M;
	for (int i=0; i<n; i++)	{
		if (ds[i]==dt[i] && ds[i]*2==len) {
			long x = ns[i]*nt[i] % M;
			dec(r, x * x);
		}
	}
	for (int i=0; i<n; i++) {
		for (auto e: g[i]) {
			int j = e.first;
			if (ds[i] + dt[j] + e.second != len)
				continue;
			if (ds[i]*2 < len && dt[j]*2 < len) {
				long x = ns[i]*nt[j] % M;
				dec(r, x * x);
			}
		}
	}
	if (r<0) r += M;
	return r;
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
	g.clear();
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



