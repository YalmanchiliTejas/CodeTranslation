#include<bits/stdc++.h>
#define MAXN 200007
using namespace std;
int n;
struct balls
{
	long long val, bag;
}b[2 * MAXN];
long long Rmax, Rmin, Bmax, Bmin, ans;
int ex[MAXN], ou[MAXN];
bool cmp(balls u, balls v)
{
	return u.val < v.val;
}
bool check(int to)
{
	int i;
	memset(ex, 0, sizeof(ex));
	for(i = 2; i <= to; i++)++ex[b[i].bag];
	for(i = 1; i <= n; i++)
	if(!ex[i])return 0;
	return 1;
}
int main()
{
	int i;
	scanf("%d", &n);
	Rmax = Bmax = 0; Bmin = Rmin = 1e9;
	for(i = 1; i <= n; i++)
	{
		scanf("%d%d", &b[2 * i - 1].val, &b[2 * i].val);
		if(b[2 * i - 1].val > b[2 * i].val)swap(b[2 * i - 1], b[2 * i]);
		b[2 * i - 1].bag = b[2 * i].bag = i; 
		Rmax = max(Rmax, b[2 * i].val);
		Bmin = min(Bmin, b[2 * i - 1].val);
	}
	for(i = 1; i <= n; i++)
	{
		Bmax = max(Bmax, b[2 * i - 1].val);
		Rmin = min(Rmin, b[2 * i].val);
	}
	ans = (Bmax - Bmin) * (Rmax - Rmin);

	sort(b + 1, b + 2 * n + 1, cmp);
	Rmin = b[1].val;
	int h = 2, l = 2, r = 2 * n, mid;
	if(b[1].bag != b[2 * n].bag)
	{
		while(l < r - 1)
		{
			mid = (r + l) / 2;
			if(check(mid))r = mid;
			else l = mid;
		}
		++ou[b[1].bag];
		while(ou[b[h-1].bag] < 2&&r <= 2 * n)
		{
			Bmax = b[r].val; Bmin = b[h].val;
			ans = min(ans, (Bmax - Bmin) * (Rmax - Rmin));
			--ex[b[h].bag];
			while(r <= 2 * n && !ex[b[h].bag])++r, ++ex[b[r].bag];
			++ou[b[h].bag];++h;
		}	
	}
	printf("%lld", ans);
	return 0;
}