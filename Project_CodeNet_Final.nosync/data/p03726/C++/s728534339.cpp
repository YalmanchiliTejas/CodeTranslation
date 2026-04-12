#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 101010;

inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
template<typename T>
inline void read(T &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}

int n, Gcnt, x, y;
struct edge {
	int to, next;
	edge(int t = 0, int n = 0):to(t), next(n) {}
};
edge G[N << 1];
int head[N], vis[N];

inline void AddEdge(int from, int to) {
	G[++Gcnt] = edge(to, head[from]); head[from] = Gcnt;
	G[++Gcnt] = edge(from, head[to]); head[to] = Gcnt;
}
inline bool Check(int u, int f) {
	bool ck = 1; int cnt = 0;
	for (int i = head[u]; i; i = G[i].next) {
		if (G[i].to == f) continue;
		ck &= Check(G[i].to, u); cnt++;
	}
	if (!cnt) {
		vis[u] = 1;
		if (!vis[f]) {
			vis[f] = 1; return 1;
		} else return 0;
	}
	if (!vis[u]) vis[u] = vis[f] = 1;
	return ck;
}

int main(void) {
	read(n);
	for (int i = 1; i < n; i++) {
		read(x); read(y);
		AddEdge(x, y);
	}
	if (Check(1, 0) && n % 2 == 0) puts("Second");
	else puts("First");
}