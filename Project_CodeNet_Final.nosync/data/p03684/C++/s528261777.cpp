#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;

const int MaxN = 1e5;
int n, fa[MaxN + 5], tot;
struct NODE {
	LL x, y;
	int pos;
}a[MaxN + 5];
struct EDGE {
	int u, v;
	LL w;
}edge[3 * MaxN + 5];

bool cmp1(NODE a, NODE b) {return a.x < b.x;}
bool cmp2(NODE a, NODE b) {return a.y < b.y;}
bool cmp3(EDGE a, EDGE b) {return a.w < b.w;}

int Find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}

void Kruskal() {
	for(int i = 1; i <= n; i++) fa[i] = i;
	sort(edge + 1, edge + tot + 1, cmp3);
	LL ans = 0;
	for(int i = 1; i <= tot; i++) {
		int u = edge[i].u, v = edge[i].v;
		if(Find(u) != Find(v)) {
			ans += edge[i].w;
			fa[Find(u)] = Find(v);
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
		a[i].pos = i;
	}
	tot = 0;
	sort(a + 1, a + n + 1, cmp1);
	for(int i = 1; i < n; i++) {
		edge[++tot].u = a[i].pos;
		edge[tot].v = a[i + 1].pos;
		edge[tot].w = abs(a[i].x - a[i + 1].x);
	}
	sort(a + 1, a + n + 1, cmp2);
	for(int i = 1; i < n; i++) {
		edge[++tot].u = a[i].pos;
		edge[tot].v = a[i + 1].pos;
		edge[tot].w = abs(a[i].y - a[i + 1].y);
	}
	Kruskal();
}