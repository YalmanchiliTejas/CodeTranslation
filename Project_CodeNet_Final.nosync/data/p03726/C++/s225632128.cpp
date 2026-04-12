//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include<iomanip>

using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
bool mark[N];
bool dp[N][2];
int deg[N];
int n;

void dfs(int v, int par)
{
	mark[v] = true;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int u = graph[v][i];
		if (!mark[u])
		{
			dfs(u, v);
		}
	}
	if (deg[v] == 1)
	{
		dp[v][0] = true;
		dp[v][1] = false;
		return;
	}
	dp[v][0] = true;
	vector<int> vec;
	for (int i = 0; i < graph[v].size(); i++)
	{	
		int u = graph[v][i];
		if (u != par)
		{
			dp[v][0] = dp[v][0] & dp[u][1];
		}
		if (dp[u][1] == false && u != par)
		{
			vec.push_back(u);
		}
	}
	if (vec.size() > 1)
	{
		dp[v][1] = false;
		return;
	}
	if (vec.size() == 1)
	{
		if (dp[vec[0]][0])
		{
			dp[v][1] = true;
		}
		else
		{
			dp[v][1] = false;
		}
		return;
	}
	dp[v][1] = false;
	if (!vec.size())
	{
		for (int i = 0; i < graph[v].size(); i++)
		{
			int u = graph[v][i];
			if (dp[u][0])
			{
				dp[v][1] = true;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
		deg[u - 1]++;
		deg[v - 1]++;
	}
	int root = 0;
	for (int i = 0; i < n; i++)
	{
		if (deg[i] > 1)
		{
			root = i;
		}
	}
	dfs(root, -1);
	/*
	for (int i = 0; i < n; i++)
	{
		cout << dp[i][0] << " " << dp[i][1] << endl;
	}
	*/
	if (n == 2)
	{
		cout << "Second";
		exit(0);
	}
	if (dp[root][1])
	{
		cout << "Second";
	}
	else
	{
		cout << "First";
	}
}


 