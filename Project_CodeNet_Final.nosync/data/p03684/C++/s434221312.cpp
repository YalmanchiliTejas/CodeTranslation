#include <cstdio>
#include <algorithm>

#define R register
#define maxn 100010
typedef long long ll;
struct Poi {
	int x, y, id;
} p[maxn];
int Fa[maxn];
inline int Find(R int x)
{
	return Fa[x] == x ? x : Fa[x] = Find(Fa[x]);
}
inline bool cmp1(const Poi &a, const Poi &b)
{
	return a.x < b.x;
}
inline bool cmp2(const Poi &a, const Poi &b)
{
	return a.y < b.y;
}
struct edge {
	int a, b, w;
	inline bool operator < (const edge &that) const {return w < that.w;}
} e[maxn << 1];
int main()
{
	R int n, ecnt = 0; scanf("%d", &n);
	for (R int i = 1; i <= n; ++i) scanf("%d%d", &p[i].x, &p[i].y), p[i].id = Fa[i] = i;
	std::sort(p + 1, p + n + 1, cmp1);
	for (R int i = 1; i < n; ++i) e[++ecnt] = (edge) {p[i].id, p[i + 1].id, p[i + 1].x - p[i].x};
	std::sort(p + 1, p + n + 1, cmp2);
	for (R int i = 1; i < n; ++i) e[++ecnt] = (edge) {p[i].id, p[i + 1].id, p[i + 1].y - p[i].y};
	std::sort(e + 1, e + ecnt + 1);
	R ll ans = 0;
	for (R int i = 1; i <= ecnt; ++i)
	{
		R int f1 = Find(e[i].a), f2 = Find(e[i].b);
		if (f1 != f2)
		{
			ans += e[i].w;
			Fa[f1] = f2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}