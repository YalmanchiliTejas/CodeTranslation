#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>

using namespace std;

const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
long long d1[N];
long long d2[N];
long long dp1[N];
long long dp2[N];

vector<pair<long long, long long>> graph[N];
long long n, m;
long long s, t;
long long ans;

void solver(long long v, long long dp[N], long long d[N])
{
	set<pair<long long, long long>> s;
	d[v] = 0;
	dp[v] = 1;
	s.insert({d[v], v});
	while (s.size())
	{
		v = (*s.begin()).second;
		s.erase(s.begin());
		for (auto nei: graph[v])
		{
			long long u = nei.first;
			long long w = nei.second;
			if (d[u] == d[v] + w)
			{
				dp[u] += dp[v];
				dp[u] = dp[u] % mod;
			}
			if (d[u] > d[v] + w)
			{
				s.erase({d[u], u});
				d[u] = d[v] + w;
				dp[u] = dp[v];
				dp[u] = dp[u] % mod;
				s.insert({d[u], u});
			}
		}
	}
} 

int main() 
{
	cin >> n >> m >> s >> t;
	s--;
	t--;
	for (long long i = 0; i < m; i++)
	{
		long long u , v, w;
		cin >> u >> v >> w;
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}
	memset(d1, 127, sizeof d1);
	memset(d2, 127, sizeof d2);
	solver(s, dp1, d1);
	solver(t, dp2, d2);
	long long dist = dp1[t] % mod;
	ans = (dist * dist) % mod;
	for (long long i = 0; i < n; i++)
	{
		for (long long j = 0; j < graph[i].size(); j++)
		{
			long long u = graph[i][j].first;
			long long w = graph[i][j].second;
			if (d1[i] < d1[t] / 2 && d2[u] < d1[t] / 2 && d1[i] + d2[u] + w == d1[t])
			{
				ans -= (((dp1[i] * dp1[i]) % mod) * ((dp2[u] * dp2[u]) % mod)) % mod;
			}
		}
		if (d1[i] == d2[i] && d1[i] == d1[t] / 2)
		{
			ans -= (((dp1[i] * dp1[i]) % mod) * ((dp2[i] * dp2[i]) % mod)) % mod;
		}
	}
	cout << ((ans % mod) + mod) % mod << endl;

}

