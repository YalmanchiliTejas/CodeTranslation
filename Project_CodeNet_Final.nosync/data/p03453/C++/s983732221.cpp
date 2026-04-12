#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

typedef long long int lli;

const lli maxn = lli(2e5)+5, inf = lli(1e18)+5, MOD = lli(1e9)+7;

lli n, D[maxn][2], W[maxn][2];
vector<pair<lli, lli>> graph[maxn];

inline lli lliMOD(lli a, lli b)
{
	return ((a%b)+b)%b;
}

void dijkstra(lli node, lli t)
{
	for(lli i = 0;i < n;i++) D[i][t] = inf, W[i][t] = 0;
	D[node][t] = 0, W[node][t] = 1;
	set<pair<lli, lli>> Q;
	Q.insert({D[node][t], node});

	while(!Q.empty())
	{
		pair<lli, lli> top = *Q.begin();
		Q.erase(Q.begin());

		for(auto it: graph[top.second])
		{
			if(D[it.first][t] > D[top.second][t]+it.second)
			{
				if(D[it.first][t] != inf) Q.erase({D[it.first][t], it.first});
				D[it.first][t] = D[top.second][t]+it.second;
				W[it.first][t] = W[top.second][t]%MOD;
				Q.insert({D[it.first][t], it.first});
			}
			else if(D[it.first][t] == D[top.second][t]+it.second)
			{
				W[it.first][t] += W[top.second][t]%MOD;
				W[it.first][t] %= MOD;
			}
		}
	}
}

int main(void)
{
	lli m, s, t, u, v, d;
	scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
	s--, t--;

	for(lli i = 0;i < m;i++)
	{
		scanf("%lld%lld%lld", &u, &v, &d);
		u--, v--;
		graph[u].push_back({v, d}), graph[v].push_back({u, d});
	}

	dijkstra(s, 0), dijkstra(t, 1);
	lli dis = D[t][0], ans = 0;

	for(lli i = 0;i < n;i++) W[i][0] %= MOD, W[i][1] %= MOD;

	for(lli i = 0;i < n;i++)
	{
		//cout << i << " " << D[i][0] << ":" << W[i][0] << " " << D[i][1] << ":" << W[i][1] << "\n";
		if(D[i][0]+D[i][1] == dis && D[i][0] == dis/2ll && D[i][1] == dis/2ll)
		{
			lli v = ((W[i][0]%MOD)*(W[i][1]%MOD))%MOD;
			ans += (v*v)%MOD;
			ans %= MOD;
		}
		for(auto it: graph[i])
		{
			if(D[i][0]+it.second+D[it.first][1] == dis && D[i][0] < dis/2ll && D[it.first][1] < dis/2ll)
			{
				lli v = ((W[i][0]%MOD)*(W[it.first][1]%MOD))%MOD;
				ans += (v*v)%MOD;
				ans %= MOD;
			}
		}
	}

	printf("%lld\n", lliMOD(((W[t][0]%MOD)*(W[t][0]%MOD)%MOD)-ans%MOD, MOD)%MOD);
}