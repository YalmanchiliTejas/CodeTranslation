#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MaxN = 100000;
const int Top = 1e9 + 7;
int n, father[MaxN + 5];
struct Point {
	int x, y, num;
}a[MaxN + 5];
struct EDGE {
	int u, v, w;
}edge[MaxN * 2];

bool cmp(Point A, Point B) {
	if (A.x == B.x) return A.y < B.y;
	return A.x < B.x;
}

bool cmp2(Point A, Point B) { 
	if (A.y == B.y) return A.x < B.x;
	return A.y < B.y;
}

bool cmp1(EDGE A, EDGE B) {
	return A.w < B.w;
}

int Find(int x)
{
	if (father[x] == x) return x;
	return father[x] = Find(father[x]);
}

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i].x, &a[i].y);
			a[i].num = i;
		}
		int tot = 0;
		sort(a + 1, a + n + 1, cmp);
		for (int i = 2; i <= n; i++) {
			edge[++tot].u = a[i].num;
			edge[tot].v = a[i - 1].num;
			edge[tot].w = abs(a[i].x - a[i - 1].x);
		}
		sort(a + 1, a + n + 1, cmp2);
		for (int i = 2; i <= n; i++) {
			edge[++tot].u = a[i].num;
			edge[tot].v = a[i - 1].num;
			edge[tot].w = abs(a[i].y - a[i - 1].y);
		}
		sort(edge + 1, edge + tot + 1, cmp1);
		for (int i = 1; i <= n; i++) father[i] = i;
		int ans = 0;
		for (int i = 1; i <= tot; i++) {
			if (Find(edge[i].u) != Find(edge[i].v)) {
				//printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].w);
				father[Find(edge[i].u)] = edge[i].v;
				ans += edge[i].w;
			}
		}
		printf("%d\n", ans);
	}
}