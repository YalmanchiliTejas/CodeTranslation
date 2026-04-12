#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 10;
int ans, n, m;
struct edge {
	int v, next;
}e[maxn * maxn * 2];
int head[maxn], cnt;
bool vis[maxn];

void adde(const int &u, const int &v) {
	e[++cnt] = (edge) {v, head[u]};
	head[u] = cnt;
}

void dfs(int u, int step) {
	vis[u] = 1;
	if(step == n) {
		++ans, vis[u] = 0;
		return;
	}
	for(register int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(!vis[v]) {
			dfs(v, step + 1);
		}
	}
	vis[u] = 0;
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for(register int i = 1; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	dfs(1, 1);
	printf("%d", ans);
	return 0;
}