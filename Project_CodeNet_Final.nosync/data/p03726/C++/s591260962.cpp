#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct edge {
	int to, next;
} e[N * 2];
int head[N], ecnt, mark[N];
inline void adde(int from, int to) {
	e[++ecnt] = (edge){to, head[from]}, head[from] = ecnt;
	e[++ecnt] = (edge){from, head[to]}, head[to] = ecnt;
}
void dfs(int u, int f) {
	mark[u] = 1; int ct = 0;
	for (int i = head[u]; i; i = e[i].next)
		if (e[i].to != f) dfs(e[i].to, u), ct += mark[e[i].to];
	if (ct > 1 || (u == 1 && ct == 0)) puts("First"), exit(0);
	if (ct == 1) mark[u] = 0;
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1, a, b; i < n; i++) scanf("%d%d", &a, &b), adde(a, b);
	dfs(1, 0), puts("Second");
}