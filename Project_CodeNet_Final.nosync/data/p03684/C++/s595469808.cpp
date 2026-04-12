
#define _CRT_SECURE_NO_WARNINGS

#define N (1<<17)

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int n, cnt;
pair<int, int> pos[N];
pair<pair<int, int>, int> pos1[N];
pair<pair<int, int>, int> pos2[N];
long long Ans;
int par[N];
pair<int, int> vv[N << 1];

inline int Fnd(int x)
{
	return (x == par[x]) ? (x) : (par[x] = Fnd(par[x]));
}

inline void Mrg(int u, int v)
{
	u = Fnd(u), v = Fnd(v);
	if (u != v)
	{
		par[v] = u;
	}
}

long long dist(int xx, int yy)
{
	return (long long)min((long long)abs(pos[xx].first - pos[yy].first),
		(long long)abs(pos[xx].second - pos[yy].second));
}

bool cmp2(pair<int, int> &x, pair<int, int> &y)
{
	return dist(x.first, x.second) < dist(y.first, y.second);
}

bool cmp(pair<pair<int, int>, int> &x, pair<pair<int, int>, int> &y)
{
	if (x.first.second != y.first.second)
	{
		return x.first.second < y.first.second;
	}
	else if (x.first.first != y.first.first)
	{
		return x.first.first < y.first.first;
	}
	else
	{
		return x.second < y.second;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d%d", &pos[i].first, &pos[i].second);
		pos2[i].first = pos1[i].first = pos[i];
		pos2[i].second = pos1[i].second = i;
	}
	sort(pos1, pos1 + n);
	sort(pos2, pos2 + n, cmp);
	for (int i = 0;i < n;i++)
	{
		par[i] = i;
	}
	for (int i = 0;i < n - 1;i++)
	{
		vv[cnt++] = make_pair(pos1[i].second, pos1[i + 1].second);
		vv[cnt++] = make_pair(pos2[i].second, pos2[i + 1].second);
	}
	sort(vv, vv + cnt, cmp2);
	for (int i = 0;i < cnt;i++)
	{
		int o1 = Fnd(vv[i].first), o2 = Fnd(vv[i].second);
		if (o1 != o2)
		{
			Mrg(o1, o2);
			Ans += dist(vv[i].first, vv[i].second);
		}
	}
	printf("%lld\n", Ans);
	//system("pause");
	return 0;
}

