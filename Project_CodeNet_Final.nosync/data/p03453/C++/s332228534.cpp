#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000LL
typedef pair<ll, ll>pii;
vector<pii>pat[100000];
ll d1[100000], d2[100000];
bool flag[100000];
ll mod = 1000000007;
ll dp1[100000], dp2[100000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	int st, go;
	scanf("%d%d", &st, &go);
	st--, go--;
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		pat[za].push_back(make_pair(zb, zc));
		pat[zb].push_back(make_pair(za, zc));
	}
	fill(d1, d1 + num, INF), fill(d2, d2 + num, INF);
	priority_queue<pii>que;
	que.push(make_pair(0, st));
	fill(flag, flag + num, false);
	for (;;)
	{
		if (que.empty())break;
		pii z = que.top();
		que.pop();
		ll d = -z.first, v = z.second;
		if (flag[v])continue;
		flag[v] = true;
		d1[v] = d;
		for (int i = 0; i < pat[v].size(); i++)que.push(make_pair(-d - pat[v][i].second, pat[v][i].first));
	}
	que.push(make_pair(0, go));
	fill(flag, flag + num, false);
	for (;;)
	{
		if (que.empty())break;
		pii z = que.top();
		que.pop();
		ll d = -z.first, v = z.second;
		if (flag[v])continue;
		flag[v] = true;
		d2[v] = d;
		for (int i = 0; i < pat[v].size(); i++)que.push(make_pair(-d - pat[v][i].second, pat[v][i].first));
	}
	ll len = d1[go];
	dp1[st] = dp2[go] = 1;
	que.push(make_pair(0, st));
	fill(flag, flag + num, false);
	for (;;)
	{
		if (que.empty())break;
		pii z = que.top();
		que.pop();
		ll v = z.second;
		if (flag[v])continue;
		flag[v] = true;
		for (int i = 0; i < pat[v].size(); i++)
		{
			if (d1[v] + d2[pat[v][i].first] + pat[v][i].second == len)
			{
				dp1[pat[v][i].first] = (dp1[pat[v][i].first] + dp1[v]) % mod;
				que.push(make_pair(-d1[pat[v][i].first], pat[v][i].first));
			}
		}
	}
	que.push(make_pair(0, go));
	fill(flag, flag + num, false);
	for (;;)
	{
		if (que.empty())break;
		pii z = que.top();
		que.pop();
		ll v = z.second;
		if (flag[v])continue;
		flag[v] = true;
		for (int i = 0; i < pat[v].size(); i++)
		{
			if (d2[v] + d1[pat[v][i].first] + pat[v][i].second == len)
			{
				dp2[pat[v][i].first] = (dp2[pat[v][i].first] + dp2[v]) % mod;
				que.push(make_pair(-d2[pat[v][i].first], pat[v][i].first));
			}
		}
	}
	ll ans = dp1[go] * dp1[go] % mod;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < pat[i].size(); j++)
		{
			ll s = i, t = pat[i][j].first;
			ll d = pat[i][j].second;
			if (d1[s] + d + d2[t] == len)
			{
				if (d1[s] + d1[s] < len&&d2[t] + d2[t] < len)
				{
					ll z = dp1[s] * dp2[t] % mod;
					ans = (ans + mod - z * z % mod) % mod;
				}
			}
		}
		if (d1[i] == d2[i] && d1[i] + d2[i] == len)
		{
			ll z = dp1[i] * dp2[i] % mod;
			ans = (ans + mod - z * z % mod) % mod;
		}
	}
	printf("%lld\n", ans);
}