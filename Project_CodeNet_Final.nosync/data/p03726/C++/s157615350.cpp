/*
	首先发现一些性质
	如果一个点接了 ≥ 2 个度数为 1 的点, 那么先手赢
	那么 dfs 的时候, 就会把连在一起的
	一个度数为 1, 一个度数不为 1 的结点 (叶子和上面的那个)
	的两个点去掉不看(先手填叶子上面的), 变成一个子问题
*/
#include <iostream>
#include <cstdio>
#define N 100005

using namespace std;

int n;
int head[N], nex[N << 1], to[N << 1], te;
int deg[N], fa[N], f[N];

inline void read(int &x) {
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}
inline void ade(int u, int v) { 
	nex[++te] = head[u], head[u] = te;
	to[te] = v, ++deg[v];
}

void dfs(int u) {
	for(int i = head[u]; i; i = nex[i]) {
		int v = to[i];
		if(v == fa[u]) continue;
		fa[v] = u, dfs(v);
	}
	if(f[u] >= 2) {
		puts("First");
		exit(0);
	}
	if(deg[u] == 1) ++f[fa[u]];
	if(f[u]) --deg[fa[u]];
}

int main() {
	read(n);
	for(int i = 1, u, v; i < n; ++i) {
		read(u), read(v);
		ade(u, v), ade(v, u);
	}
	if(n == 2) return puts("Second"), 0;
	for(int i = 1; i <= n; ++i) {
		if(deg[i] == 1) continue;
		dfs(i);
		return puts(deg[i] ? "Second" : "First"), 0;
	}
	return 0;
}