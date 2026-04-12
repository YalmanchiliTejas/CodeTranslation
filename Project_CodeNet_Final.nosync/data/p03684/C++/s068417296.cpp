#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack> 
#include <set>
#include <map>
using namespace std;

typedef long long ll;
const int mod = 1000000007;

#define N 100010
#define X first
#define Y second

int father[N];

struct node
{
	int x, y, id;
}p[N];

vector<pair<int, pair<int, int> > > lis;

int Find(int x)
{
	if (x == father[x]) return x;
	father[x] = Find(father[x]);
	return father[x];
}

void Merge(int x, int y)
{
	x = Find(x);
	y = Find(y);
	father[x] = y;
}


bool cmp(node a, node b)
{
	return a.x < b.x;
}

bool cmp2(node a, node b)
{
	return a.y < b.y;
}

int main()
{
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);

	int n; ll res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].id = i;
		father[i] = i;
	}
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i < n; ++i)
	{
		lis.push_back(make_pair(p[i + 1].x - p[i].x, make_pair(p[i].id, p[i + 1].id)));
	}
	sort(p + 1, p + n + 1, cmp2);
	for (int i = 1; i < n; ++i)
	{
		lis.push_back(make_pair(p[i + 1].y - p[i].y, make_pair(p[i].id, p[i + 1].id)));
	}

	sort(lis.begin(), lis.end());

	for (int i = 0; i < lis.size(); ++i)
	{
		int x = lis[i].Y.X, y = lis[i].Y.Y, z = lis[i].X;
		if (Find(x) != Find(y))
		{
			res += z;
			Merge(x, y);
		}
	}
	cout << res << endl;
	return 0;
}

