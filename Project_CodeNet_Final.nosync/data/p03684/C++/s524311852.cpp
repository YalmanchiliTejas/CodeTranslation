#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int MaxN = 1e5;
const LL MOD = 1e9 + 7;

int n, tot;
struct point
{
	int x, y;
	int id;
}PP[MaxN + 5];
struct Edge
{
	int u, v;
	int w;
}ed[2 * MaxN + 5];
int fa[MaxN + 5];

int cmpx(point a, point b) {return a.x < b.x;}
int cmpy(point a, point b) {return a.y < b.y;}
int cmpe(Edge x, Edge y) {return x.w < y.w;}

int find(int x)
{
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		tot = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d", &PP[i].x, &PP[i].y);
			PP[i].id = i;
		}
		sort(PP + 1, PP + n + 1, cmpx);
		for(int i = 1; i <= n - 1; i++)
		{
			ed[++tot].u = PP[i].id;
			ed[tot].v = PP[i + 1].id;
			ed[tot].w = min(abs(PP[i].x - PP[i + 1].x), abs(PP[i].y - PP[i + 1].y));
		}
		sort(PP + 1, PP + n + 1, cmpy);
		for(int i = 1; i <= n - 1; i++)
		{
			ed[++tot].u = PP[i].id;
			ed[tot].v = PP[i + 1].id;
			ed[tot].w = min(abs(PP[i].x - PP[i + 1].x), abs(PP[i].y - PP[i + 1].y));
		}
		
		LL ans = 0;
		for(int i = 1; i <= n; i++) fa[i] = i;
		sort(ed + 1, ed + tot + 1, cmpe);
		for(int i = 1; i <= tot; i++)
		{
			int u = ed[i].u, v = ed[i].v;
			if(find(u) != find(v))
			{
				ans += (LL)ed[i].w;
				fa[find(v)] = find(u);
			}
		}
		printf("%lld\n", ans);
		
		memset(PP, 0, sizeof(PP));
		memset(ed, 0, sizeof(ed));
	}
	return 0;
}