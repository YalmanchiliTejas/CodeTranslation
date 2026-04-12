#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<pair<int, int>, ll> > edg;
pair<pair<ll, ll>, int> pt[100005];
int par[100005];
int n;

int gp(int x) { return par[x]==x?x:par[x]=gp(par[x]); }

ll cst(int a, int b)
{
	return min(abs(pt[a].first.first-pt[b].first.first), abs(pt[a].first.second-pt[b].first.second));
}

ll slv()
{
	for (int i = 0;i < n;i++) par[i] = i;
	ll ans = 0;
	sort(edg.begin(), edg.end(), [](pair<pair<int, int>, ll> a, pair<pair<int, int>, ll> b)->bool {
		return (a.second < b.second);
	});
	for (auto u: edg)
	{
		u.first.first = gp(u.first.first), u.first.second = gp(u.first.second);
		if (u.first.first == u.first.second) continue;
		par[u.first.first] = u.first.second;
		ans += u.second;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%lld%lld", &pt[i].first.first, &pt[i].first.second);
	sort(pt, pt+n); n = unique(pt, pt+n)-pt;
	for (int i = 0;i < n;i++) pt[i].second = i;
	int ptr = -1;
	for (int i = 1;i < n;i++)
	{
		edg.emplace_back(make_pair(pt[i-1].second, pt[i].second), cst(i-1, i));
		if (pt[i].first.first == pt[i-1].first.first)
		{
			if (ptr != -1) edg.emplace_back(make_pair(pt[ptr].second, pt[i].second), cst(ptr, i));
		} else ptr = i-1;
	}
	reverse(pt, pt+n); ptr = -1;
	for (int i = 1;i < n;i++)
	{
		edg.emplace_back(make_pair(pt[i-1].second, pt[i].second), cst(i-1, i));
		if (pt[i].first.first == pt[i-1].first.first)
		{
			if (ptr != -1) edg.emplace_back(make_pair(pt[ptr].second, pt[i].second), cst(ptr, i));
		} else ptr = i-1;
	}
	sort(pt, pt+n, [](pair<pair<ll, ll>, int> a, pair<pair<ll, ll>, int> b)->bool {
		return (a.first.second!=b.first.second)?(a.first.second<b.first.second):(a.first.first<b.first.first);
	});
	ptr = -1;
	for (int i = 1;i < n;i++)
	{
		edg.emplace_back(make_pair(pt[i-1].second, pt[i].second), cst(i-1, i));
		if (pt[i].first.second == pt[i-1].first.second)
		{
			if (ptr != -1) edg.emplace_back(make_pair(pt[ptr].second, pt[i].second), cst(ptr, i));
		} else ptr = i-1;
	}
	reverse(pt, pt+n); ptr = -1;
	for (int i = 1;i < n;i++)
	{
		edg.emplace_back(make_pair(pt[i-1].second, pt[i].second), cst(i-1, i));
		if (pt[i].first.second == pt[i-1].first.second)
		{
			if (ptr != -1) edg.emplace_back(make_pair(pt[ptr].second, pt[i].second), cst(ptr, i));
		} else ptr = i-1;
	}
	printf("%lld\n", slv());
	return 0;
}
