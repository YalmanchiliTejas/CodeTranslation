#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <functional>
#include <utility>

using namespace std;

#define MOD 1000000007

typedef long long lli;
typedef pair<lli, int> ip;

class e {
public:
	int v, w;
	e(int v, int w)
		:v(v), w(w)
	{}
};

lli d[2][100001];
int n, m;
vector<e> con[100001];

void dij(int to, int s) {
	priority_queue<ip, vector<ip>, greater<ip> > q;
	q.push(ip(0, s));
	memset(d[to], -1, sizeof(d[to]));
	d[to][s] = 0;
	while (!q.empty()) {
		lli dis = q.top().first;
		int u = q.top().second;
		q.pop();
		if (d[to][u] != dis) continue;
		for (int i = 0; i < con[u].size(); i++) {
			int v = con[u][i].v, w = con[u][i].w;
			if (d[to][v]<0 || d[to][v]>dis + w) {
				d[to][v] = dis + w;
				q.push(ip(d[to][v], v));
			}
		}
	}
}

int s, t;

lli dd[100001];

lli f(int k) {
	if (k == s) return 1;
	if (dd[k] >= 0) return dd[k];
	lli res = 0;
	for (int i = 0; i < con[k].size(); i++) {
		int v = con[k][i].v, w = con[k][i].w;
		if (d[0][v] + w == d[0][k]) {
			res += f(v);
			res %= MOD;
		}
	}
	return dd[k] = res;
}

lli ddd[100001];

lli g(int k) {
	if (k == t) return 1;
	if (ddd[k] >= 0) return ddd[k];
	lli res = 0;
	for (int i = 0; i < con[k].size(); i++) {
		int v = con[k][i].v, w = con[k][i].w;
		if (d[1][v] + w == d[1][k]) {
			res += g(v);
			res %= MOD;
		}
	}
	return ddd[k] = res;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &t);
	while (m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		con[u].push_back(e(v, w));
		con[v].push_back(e(u, w));
	}
	dij(0, s); dij(1, t);
	lli dist = d[0][t];
	memset(dd, -1, sizeof(dd));
	memset(ddd, -1, sizeof(ddd));
	lli res = f(t)*g(s) % MOD;
	for (int i = 1; i <= n; i++) {
		if (d[0][i] == d[1][i] && d[0][i] + d[1][i] == dist) {
			lli w = f(i)*g(i) % MOD;
			w = w*w%MOD;
			res = (res - w + MOD) % MOD;
		}
		else {
			for (int j = 0; j < con[i].size(); j++) {
				int v = con[i][j].v, w = con[i][j].w;
				if (d[0][i]<d[1][i] && d[0][v]>d[1][v] && d[0][i] + d[1][v] + w == dist) {
					lli w = f(i)*g(v) % MOD;
					w = w*w%MOD;
					res = (res - w + MOD) % MOD;
				}
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}