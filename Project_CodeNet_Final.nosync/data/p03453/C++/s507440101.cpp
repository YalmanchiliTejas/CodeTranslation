#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
ll goingIn[100010], goingOut[100010];
bool done[100010];
vector<pair<int, ll> > inadj[100010], adj[100010], revadj[100010];
int n, m, s, t;
ll d[100010];
ll pathsAfter(ll a)
{
	if (done[a]) return goingOut[a];
	done[a] = true;
	if (a == t) return goingOut[a] = 1;
	ll ans = 0;
	for (auto b : adj[a]) 
	{
		ans += pathsAfter(b.first);
	}
	return goingOut[a] = ans%mod;
}
ll pathsBefore(ll a)
{
	if (done[a]) return goingIn[a];
	done[a] = true;
	if (a == s) return goingIn[a] = 1;
	ll ans = 0;
	for (auto b : revadj[a]) 
	{
		ans += pathsBefore(b.first);
	}
	return goingIn[a] = ans%mod;
}
ll ans;
void findAns(int a, ll d, ll dis, ll total) // dis so far, total dis, total paths
{
	if (done[a]) return;
	done[a] = true;
//	printf("at %d\n", a);
	if (!(dis % 2) && dis/2 == d)
	{
		// this point is half way

		ll am = (goingIn[a] * goingOut[a])%mod;
		am *= am;
		ans -= (am)%mod;
		return;
	}
	for (auto b: adj[a])
	{
		ll d1 = dis/2;
		ll d2 = d1 + dis % 2;
		if (d < d2 && d + b.second > d1)
		{
		//	printf("%d -> %d, %d\n", a, b.first, b.second);
			ll am = (goingIn[a] * goingOut[b.first])%mod;
			am *= am;
			ans -= (am)%mod;
		}
		else findAns(b.first, d + b.second, dis, total);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		int c;
		scanf("%d%d%d", &a, &b, &c);
		inadj[a].emplace_back(b, c);
		inadj[b].emplace_back(a, c);
	}
	fill_n(d, 100010, 999999999999999);
	d[s] = 0;
	priority_queue<pair<int, ll> > pq;
	pq.emplace(s, 0);
	while (!pq.empty())
	{
		int a;
		ll dis;
		a = pq.top().first;
		dis = -pq.top().second;
		pq.pop();
		if (d[a] != dis) continue;
		for (auto b : inadj[a])
		{
			if (d[b.first] > dis + b.second)
			{
				revadj[b.first].clear();
				d[b.first] = dis + b.second;
				pq.emplace(b.first, -d[b.first]);
			}
			if (d[b.first] == dis + b.second)
			{
				revadj[b.first].emplace_back(a, b.second);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto b : revadj[i])
		{
			adj[b.first].emplace_back(i, b.second);
		}
	}
	pathsAfter(s);
	fill_n(done, 100010, 0);
	pathsBefore(t);
	ans = goingOut[s] * goingOut[s];
	ans %= mod;
	fill_n(done, 100010, 0);
//	printf("%lld\n", ans);
	findAns(s, 0, d[t], goingOut[s]);
	while (ans < 0)
	{
		ans += mod;
	}
	ans %= mod;
	printf("%lld\n", ans);
}