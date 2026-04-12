#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
struct edge {
	int u, v;
	ll w;
	edge(int u, int v, ll w) : u (u), v (v), w (w) {}
};
struct data {
	ll x, y;
	int id;
} a[N];
int n;
int fa[N];
ll ans;
vector<edge> e;
bool cp(edge x, edge y)
{
	return x.w < y.w;
}
bool cp1(data x, data y)
{
	return x.x < y.x;
}
bool cp2(data x, data y)
{
	return x.y < y.y;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld%lld", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cp1);
	for(int i = 2; i <= n; ++i)
		e.push_back(edge(a[i].id, a[i - 1].id, a[i].x - a[i - 1].x));
	sort(a + 1, a + n + 1, cp2);
	for(int i = 2; i <= n; ++i)
		e.push_back(edge(a[i].id, a[i - 1].id, a[i].y - a[i - 1].y));
	sort(e.begin(), e.end(), cp);
	for(int i = 0; i < e.size(); ++i)
	{
		if(find(e[i].u) == find(e[i].v)) 
			continue;
		ans += e[i].w;
		fa[find(e[i].u)] = find(e[i].v);
	}
	printf("%lld\n", ans);
	return 0;
}