#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <bitset>
using namespace std;

#define X first
#define Y second
#define N 200020
#define M 
#define maxn 1000

typedef long long ll;
const ll INF = 1ll << 60;
const int Mod = 1000000007;

pair<int, int> p[N];

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
	{
		scanf("%d %d", &p[i].X, &p[i].Y);
		if (p[i].X > p[i].Y) swap(p[i].X, p[i].Y);
	}
	sort(p, p + n);
	if (n == 1) puts("0");
	else
	{
		int mi = 1 << 30, ma = 0, mx;
		for (int i = 0; i < n; ++i) 
		{
			mi = min(mi, p[i].Y);
			ma = max(ma, p[i].Y);
		}
		ll res = 1ll * (p[n - 1].X - p[0].X) * (ma - mi);
		mx = ma;
		mi = p[0].Y;
		ma = max(p[n - 1].X, p[0].Y); 
		for (int i = 1; i < n; ++i)
		{
			res = min(res, 1ll * (mx - p[0].X) * (ma - min(p[i].X, mi)));
			ma = max(ma, p[i].Y);
			mi = min(mi, p[i].Y);
		}
		printf("%lld\n", res);
	}
	return 0;
}