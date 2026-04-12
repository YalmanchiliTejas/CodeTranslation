#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second

pair<int,int> dat[200005];
int n;

long long solve1()
{
	int Bmax = dat[n - 1].x;
	int Bmin = dat[0].y;
	if (Bmax < Bmin) swap(Bmax, Bmin);

	for (int i = 1; i < n - 1; i++)
	{
		Bmin = min(Bmin, dat[i].y);
		Bmax = max(Bmax, dat[i].x);
	}

	vector<pair<int, int>> vt;

	for (int i = 1; i < n - 1; i++)
	{
		if (Bmin <= dat[i].x && dat[i].x <= Bmax) continue;
		if (Bmin <= dat[i].y && dat[i].y <= Bmax) continue;

		vt.push_back(dat[i]);
	}

	if (vt.empty())
	{
		return (dat[n - 1].y - dat[0].x) * 1ll * (Bmax - Bmin);
	}

	int Blen = Bmax - vt[0].first;

	for (int i = 0, j; i < vt.size(); i = j)
	{
		for (j = i; j < vt.size() && vt[i].first == vt[j].first; j++)
			Bmax = max(Bmax, vt[j].second);

		Blen = min(Blen, Bmax - (j == vt.size() ? Bmin : vt[i].first));
	}

	return (dat[n - 1].y - dat[0].x) * 1ll * Blen;
}

long long solve2()
{
	int Rmax, Rmin, Bmax, Bmin;
	Rmax = Rmin = dat[0].y;
	Bmax = Bmin = dat[0].x;

	for (int i = 1; i < n; i++)
	{
		Rmin = min(Rmin, dat[i].y);
		Rmax = max(Rmax, dat[i].y);
		Bmin = min(Bmin, dat[i].x);
		Bmax = max(Bmax, dat[i].x);
	}

	return (Rmax - Rmin) * 1ll * (Bmax - Bmin);
}

int main()
{
	scanf("%d",&n);

	if (n == 1)
	{
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d",&dat[i].x,&dat[i].y);
		if (dat[i].x > dat[i].y) swap(dat[i].x, dat[i].y);
	}

	int maxidx = 0;
	for (int i = 1; i < n; i++)
		if (dat[maxidx].y < dat[i].y) maxidx = i;

	swap(dat[maxidx], dat[n - 1]);
	sort(dat, dat + n - 1);

	printf("%lld\n", min(solve1(), solve2()));
}
