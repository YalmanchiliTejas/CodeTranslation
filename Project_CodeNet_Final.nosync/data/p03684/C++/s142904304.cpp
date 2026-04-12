#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
const int maxn = 1e5 + 10;
typedef long long ll;
struct Node
{
	int x, y, id;
}a[maxn];
struct Edge
{
	int u, v, w;
	Edge() {}
	Edge(const int & _u, const int & _v, const int & _w) : u(_u), v(_v), w(_w) {} 
};
int fa[maxn], n;
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]);}
vector<Edge> E;
bool cmpx(const Node & i, const Node & j) { return i.x < j.x;}
bool cmpy(const Node & i, const Node & j) { return i.y < j.y;}
bool cmpw(const Edge & i, const Edge & j) { return i.w < j.w;}
int kru()
{
	ll ans = 0;
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(auto e : E)
	{
		int u = e.u, v = e.v, w = e.w;
		u = getfa(u), v = getfa(v); 
		if(u == v) continue;
		ans += w;
		fa[u] = v;
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmpx);
	for(int i = 2; i <= n; ++i) E.emplace_back(a[i - 1].id, a[i].id, a[i].x - a[i - 1].x);
	sort(a + 1, a + n + 1, cmpy);
	for(int i = 2; i <= n; ++i) E.emplace_back(a[i - 1].id, a[i].id, a[i].y - a[i - 1].y);
	sort(E.begin(), E.end(), cmpw);
	cout << kru() << endl;
	return 0;
}