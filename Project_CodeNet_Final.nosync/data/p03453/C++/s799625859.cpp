#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <cmath>

using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);++(i))

int n;
int m;

int s;
int t;

struct edge
{
	int to;
	i64 cost;
};

vector<edge> edges[100010];

int main()
{
	cin >> n >> m;
	cin >> s >> t;
	for(int i = 0;i < m;i++)
	{
		int u,v;
		i64 d;
		cin >> u >> v >> d;
		edges[u].push_back({v,d});
		edges[v].push_back({u,d});
	}

	vector<i64> dist(n + 1,1e18);

	{
		priority_queue<P,vector<P>,greater<P>> que;
		dist[s] = 0;
		que.push({dist[s],s});

		while(!que.empty())
		{
			int v = que.top().second;
			i64 d = que.top().first;
			que.pop();

			if(dist[v] < d) continue;

			for(auto& e : edges[v])
			{
				if(dist[e.to] > d + e.cost)
				{
					dist[e.to] = d + e.cost;
					que.push({dist[e.to],e.to});
				}
			}
		}
	}

	vector<i64> dp_t(n + 1,0);
	vector<i64> dp_s(n + 1,0);
	dp_t[s] = 1;
	dp_s[t] = 1;


	vector<P> vec;
	for(int i = 1;i <= n;i++) vec.push_back({dist[i],i});
	sort(vec.begin(),vec.end());
	i64 MOD = 1e9 + 7;

	// --> t
	for(int i = 0;i < n;i++)
	{
		for(auto & e : edges[vec[i].second])
		{
			if(dist[e.to] == dist[vec[i].second] + e.cost)
				(dp_t[e.to] += dp_t[vec[i].second]) %= MOD;
		}
	}
	for(int i = n - 1;i >= 0;i--)
	{
		for(auto & e : edges[vec[i].second])
		{
			if(dist[vec[i].second] == dist[e.to] + e.cost)
				(dp_s[e.to] += dp_s[vec[i].second]) %= MOD;
		}
	}

	i64 result = dp_t[t] * dp_t[t];
	result %= MOD;

	auto mod = [MOD](i64 num){
		return num % MOD;
	};

	for(int i = 1;i <= n;i++)
	{
		if(dist[i] * 2 == dist[t])
		{
			 (result += MOD - mod(mod(dp_t[i] * dp_t[i]) * mod(dp_s[i] * dp_s[i]))) %= MOD;
		}
	}

	for(int i = 1;i <= n;i++)
	{
		for(auto & e : edges[i])
		{
			int u = i;
			int v = e.to;
			if(dist[u] > dist[v]) continue;
			if(2 * dist[u] < dist[t] && 2 * dist[v] > dist[t] && dist[u] + e.cost == dist[v])
			{
				(result += MOD - mod(mod(dp_t[u] * dp_t[u]) * mod(dp_s[v] * dp_s[v]))) %= MOD;
			}

		}
	}

	cout << result << endl;



}


