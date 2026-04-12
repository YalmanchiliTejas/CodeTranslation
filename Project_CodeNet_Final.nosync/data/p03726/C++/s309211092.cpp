#include <bits/stdc++.h>

const int MAXN = 100010;
int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int dfs(int u, int b = 0, int fa = 0) {
	int sc = 0;
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa)
		sc += dfs(to[i], fa == 0, u);
	if (sc + b > 1) std::cout << "First\n" << std::endl, exit(0);
	return sc ^ 1;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 1, t1, t2; i < n; ++i)
		std::cin >> t1 >> t2, addedge(t1, t2);
	for (int i = 1; i <= n; ++i) if (!nxt[head[i]]) { dfs(i); break; }
	std::cout << "Second" << std::endl;
	return 0;
}
