#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

#define N 10005

int n;

vector<pr> to[N];

array<int, N> ans;
array<int, N> dis1;
array<int, N> pre1;
array<int, N> dis2;
array<int, N> pre2;

void dfs1(int u, int f)
{
	dis1[u] = dis2[u] = 0;
	
	for (auto e : to[u])
	{
		int v = e.first;
		int w = e.second;
		
		if (v == f)
			continue;
			
		dfs1(v, u);
		
		int tmp = dis1[v] + w;
		
		if (tmp >= dis1[u])
		{
			dis2[u] = dis1[u];
			pre2[u] = pre1[u];
			dis1[u] = tmp;
			pre1[u] = v;
		}
		else if (tmp >= dis2[u])
		{
			dis2[u] = tmp;
			pre2[u] = v;
		}
	}
}

void dfs2(int u, int f, int d)
{
	ans[u] = max(dis1[u], d);
	
	for (auto e : to[u])
	{
		int v = e.first;
		int w = e.second;
		
		if (v == f)
			continue;
		
		if (v == pre1[u])
			dfs2(v, u, max(d, dis2[u]) + w);
		else
			dfs2(v, u, max(d, dis1[u]) + w);
	}
}

signed main(void)
{
	cin >> n;
	
	for (int i = 1; i < n; ++i)
	{
		int x, y, w; 
		cin >> x >> y >> w;
		to[x].push_back(make_pair(y, w));
		to[y].push_back(make_pair(x, w));
	}
	
	memset(begin(pre1), -1, sizeof(pre1));
	memset(begin(pre2), -1, sizeof(pre2));
	
	dfs1(0, -1);
	dfs2(0, -1, 0);
	
	for (int i = 0; i < n; ++i)
		cout << ans[i] << endl;
}