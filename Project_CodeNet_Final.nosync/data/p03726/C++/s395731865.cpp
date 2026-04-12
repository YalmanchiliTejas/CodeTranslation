#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

#define X first
#define Y second
#define N 100010
#define M 500010

typedef unsigned long long ull;
typedef long long ll;
const int INF = 1 << 30;
const int Mod = 1000000007;

int father[N];
bool vis[N];
vector<int> E[N];
vector<int> lis;

void DFS(int x)
{
	for (int i = 0; i <E[x].size(); ++i)
	{
		int y = E[x][i];
		if (y == father[x]) continue;
		father[y] = x, DFS(y);
	}
	lis.push_back(x);
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n, x, y;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	DFS(1);
	if (n & 1) puts("First");
	else
	{
		int cnt = 0; vis[0] = true;
		for (int i = 0; i < lis.size(); ++i)
		{
			int x = lis[i];
			if (!vis[x] && !vis[father[x]]) cnt++, vis[x] = vis[father[x]] = true;
		}
		puts(cnt == n / 2? "Second":"First");
	}
	return 0;
}