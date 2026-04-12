#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 7;

#define inc(i, x, y) for (int i = x; i <= y; ++i)
#define dec(i, x, y) for (int i = x; i >= y; --i)
#define gc getchar

bool chkmin(int &x, int y) { return x > y ? x = y, 1 : 0; }
bool chkmax(int &x, int y) { return x < y ? x = y, 1 : 0; }

int rd() {
	int ret = 0; bool fl = 0; char ch = 0;
	while (!isdigit(ch)) fl |= (ch == '-'), ch = gc();
	while (isdigit(ch)) ret = (ret << 1) + (ret << 3) + (ch ^ 48), ch = gc();
	return fl ? -ret : ret;
}

#define go(i, v, x) for (int i = head[x], v = e[i].to; i; i = e[i].nxt, v = e[i].to)
struct edge { int nxt, to; } e[N << 1];
int head[N], cnt;
void add(int u, int v) {
	e[++cnt] = (edge) { head[u], v }; head[u] = cnt;
	e[++cnt] = (edge) { head[v], u }; head[v] = cnt;
}

int dfs(int x, int fa) {
	int ret = 0;
	go(i, v, x) if (v != fa) ret += dfs(v, x);
	if (ret > 1) puts("First"), exit(0);
	return (ret ^ 1);
} 

int main() {
	int n = rd();
	inc(i, 1, n - 1) add(rd(), rd());
	puts(dfs(1, -1) ? "First" : "Second");
}