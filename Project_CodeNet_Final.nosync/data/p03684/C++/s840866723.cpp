#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const int MAXM = 4e5 + 10;

struct Node {
	int pos, id;
	bool operator < (const Node & obj) {return pos < obj.pos;}
} a[MAXN], b[MAXN];

struct Edge {
	int u, v, w;
	bool operator < (const Edge & obj) {return w < obj.w;}
} e[MAXM];
int tot;

inline void addEdge (int u, int v, int w) {
	e[++tot] = (Edge){u,v,w};
}

int fa[MAXN];
int findSet (int x) {return fa[x] == x ? x : fa[x] = findSet(fa[x]);}
void unionSet (int x, int y) {int xx = findSet(x), yy = findSet(y); if (xx != yy) fa[yy] = xx;}
void initSet (int n) {for (int i = 1; i <= n; i++) fa[i] = i;}

long long kruskal (int n) {
	initSet(n);
	sort(e+1,e+tot+1);

	long long ret = 0;
	for (int i = 1, cnt = 0; i <= tot; i++) {
		int xx = findSet(e[i].u);
		int yy = findSet(e[i].v);
		if (xx != yy) {
			fa[yy] = xx;
			ret += e[i].w;
			if (++cnt == n - 1) return ret;
		}
	}
	return ret;
}

int main (void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].pos, &b[i].pos);
		a[i].id = b[i].id = i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (int i = 1; i <= n; i++) {
		if (i + 1 <= n) {
			addEdge(a[i].id,a[i+1].id,a[i+1].pos - a[i].pos);
			addEdge(a[i+1].id,a[i].id,a[i+1].pos - a[i].pos);
			addEdge(b[i].id,b[i+1].id,b[i+1].pos - b[i].pos);
			addEdge(b[i+1].id,b[i].id,b[i+1].pos - b[i].pos);
		}
		if (i - 1 >= n) {
			addEdge(a[i].id,a[i-1].id,a[i].pos - a[i-1].pos);
			addEdge(a[i-1].id,a[i].id,a[i].pos - a[i-1].pos);
			addEdge(b[i].id,b[i-1].id,b[i].pos - b[i-1].pos);
			addEdge(b[i-1].id,b[i].id,b[i].pos - b[i-1].pos);
		}	
	}
	printf("%lld\n", kruskal(n));
}