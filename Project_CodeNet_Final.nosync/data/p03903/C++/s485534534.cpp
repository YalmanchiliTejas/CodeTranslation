#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int N, M, Q, s, t, a[400009], b[400009], c[400009], p[400009], par[4009], d[4009][4009]; vector<pair<int, int> > g[4009];
int root(int x) { return x == par[x] ? x : par[x] = root(par[x]); }
void dfs(int pos, int pre, int st, int val) {
	d[st][pos] = val;
	for (pair<int, int> i : g[pos]) {
		if (i.first == pre) continue;
		dfs(i.first, pos, st, max(val, i.second));
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]), a[i]--, b[i]--, p[i] = i;
	sort(p, p + M, [](int i, int j) { return c[i] < c[j]; });
	for (int i = 0; i < N; i++) par[i] = i;
	long long sum = 0;
	for (int i = 0; i < M; i++) {
		int pa = root(a[p[i]]), pb = root(b[p[i]]);
		if (pa != pb) {
			par[pa] = pb; sum += c[p[i]];
			g[a[p[i]]].push_back(make_pair(b[p[i]], c[p[i]]));
			g[b[p[i]]].push_back(make_pair(a[p[i]], c[p[i]]));
		}
	}
	for (int i = 0; i < N; i++) dfs(i, -1, i, 0);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &s, &t); s--, t--;
		printf("%lld\n", sum - d[s][t]);
	}
	return 0;
}