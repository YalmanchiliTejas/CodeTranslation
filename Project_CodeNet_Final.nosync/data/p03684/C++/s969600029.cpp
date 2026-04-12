#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 200010;

int n, m;
struct node
{
	int x, y;
	int id;
}p[MAXN], e[MAXN];

int F[MAXN];

int father(int x)
{
	return (F[x] == x) ? x : F[x] = father(F[x]);
}

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].id = i;
	}
	sort(p+1, p+n+1, [](const node &a, const node &b){return a.x<b.x;});
	for (int i = 1; i < n; ++ i)
		e[++ m] = node{p[i].id, p[i+1].id, p[i+1].x-p[i].x};
	sort(p+1, p+n+1, [](const node &a, const node &b){return a.y<b.y;});
	for (int i = 1; i < n; ++ i)
		e[++ m] = node{p[i].id, p[i+1].id, p[i+1].y-p[i].y};
	
	for (int i = 1; i <= n; ++ i)
		F[i] = i;
	sort(e+1, e+m+1, [](const node &a, const node &b){return a.id<b.id;});
	int ans = 0;
	for (int i = 1; i <= m; ++ i)
	{
		int x = e[i].x, y = e[i].y, w = e[i].id;
		int fx = father(x), fy = father(y);
		if (fx == fy) continue;
		ans += w;
		F[fx] = fy;
	}
	cout << ans << endl;
	
	return 0;
}
