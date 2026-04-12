#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#define X first
#define Y second
#define pb push_back
typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 2e5+5;
int n;

ii foo[maxn];

int cnt[maxn];

int tot = 0;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i<= n; i++)
	{
		scanf("%d %d", &foo[i].X, &foo[i].Y);
		if(foo[i].X> foo[i].Y) swap(foo[i].X, foo[i].Y);
	}
	sort(foo+1, foo+n+1);
	vector< ii > mon;
	for(int i = 1; i<= n; i++)
	{
		if(mon.empty() || foo[i].Y> mon.back().Y) mon.pb(foo[i]);
	}
	ll res = 4e18;
	int minx = 1e9, maxx = -1e9;
	int miny = 1e9, maxy = -1e9;
	for(int i = 1; i<= n; i++)
	{
		minx = min(foo[i].X, minx);
		maxx = max(foo[i].X, maxx);
		miny = min(foo[i].Y, miny);
		maxy = max(foo[i].Y, maxy);
	}
	res = 1LL*(maxx-minx)*(maxy-miny);
	if((int) mon.size() == 1)
	{
		printf("%lld\n", res);
		return 0;
	}
	vector< ii > vec;
	for(int i = 1; i<= n; i++)
	{
		vec.pb(ii(foo[i].X, i));
		vec.pb(ii(foo[i].Y, i));
	}
	sort(vec.begin(), vec.end());
	int width = 1e9+5;
	int pt = 0;
	for(int i = 0; i< (int) vec.size(); i++)
	{
		if(i) 
		{
			cnt[vec[i-1].Y]--;
			if(cnt[vec[i-1].Y] == 0) tot--;
		}
		while(pt< (int) vec.size() && tot< n)
		{
			cnt[vec[pt].Y]++;
			if(cnt[vec[pt].Y] == 1) tot++;
			pt++;
		}
		if(tot == n)
		{
			width = min(width, vec[pt-1].X-vec[i].X);
		}
	}
	res = min(res, 1LL*width*(mon.back().Y-mon[0].X));
	printf("%lld\n", res);
}
