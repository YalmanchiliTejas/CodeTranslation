#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define ll long long
#define mod 1000000007
using namespace std;
ll de[100010];
ll check[100010];
ll cnt[100010];
ll indegree1[100100];
ll indegree[100010];
ll cnt1[100010];
queue<ll> qu1;
vector<vector<ll>> vt4;
vector<vector<pair<ll, ll>>> vt;
priority_queue<pair<ll, ll>> qu;
vector<pair<pair<ll, ll>, ll>> vt1;
vector<vector<ll>> vt3;
vector<pair<pair<ll, ll>, ll>> vt2;
void dfs(ll here)
{
	check[here] = 1;
	for (int i = 0; i < vt[here].size(); i++)
	{
		ll next = vt[here][i].first;
		ll ncst = vt[here][i].second;
		if (!check[next]&&de[here]-de[next]==ncst)
		{
			dfs(next);
		}
	}
}
int main() 
{
	memset(de, -1, sizeof(de));
	int n, m,st,en;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &st, &en);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int q, w, e;
		scanf("%d %d %d", &q, &w, &e);
		vt[q].push_back({ w,e });
		vt[w].push_back({ q,e });
		vt1.push_back({ {q,w} ,e });
	}
	qu.push({ 0,st });
	while (qu.size())
	{
		ll cst = -qu.top().first;
		ll curr = qu.top().second;
		qu.pop();
		if (de[curr] != -1)continue;
		de[curr] = cst;
		for (int i = 0; i < vt[curr].size(); i++) {
			ll next = vt[curr][i].first;
			ll ncst = vt[curr][i].second;
			if (de[next] == -1)
				qu.push({ -cst - ncst,next });
		}
	}
	dfs(en);
	for (int i = 0; i < vt1.size(); i++)
	{
		int q = vt1[i].first.first;
		int w = vt1[i].first.second;
		int e = vt1[i].second;
		if (check[q] && check[w] && abs(de[q] - de[w]) == e)
		{
			if (de[q] > de[w])swap(q, w);
			vt2.push_back({ {q,w},e });
		}
	}
	vt4.resize(n + 1);
	vt3.resize(n + 1);
	for (int i = 0; i < vt2.size(); i++)
	{
		int q = vt2[i].first.first;
		int w = vt2[i].first.second;
		int e = vt2[i].second;
		vt4[q].push_back(w);
		indegree[w]++;
		vt3[w].push_back(q);
		indegree1[q]++;
	}
	qu1.push(st);
	cnt[st] = 1;
	while (qu1.size())
	{
		int curr = qu1.front();
		qu1.pop();
		for (int i = 0; i < vt4[curr].size(); i++)
		{
			int next = vt4[curr][i];
			indegree[next]--;
			cnt[next] += cnt[curr];
			cnt[next] %= mod;
			if (!indegree[next])
				qu1.push(next);
		}
	}
	cnt1[en] = 1;
	qu1.push(en);
	while (qu1.size())
	{
		int curr = qu1.front();
		qu1.pop();
		for (int i = 0; i < vt3[curr].size(); i++)
		{
			int next = vt3[curr][i];
			indegree1[next]--;
			cnt1[next] += cnt1[curr];
			cnt1[next] %= mod;
			if (!indegree1[next])
				qu1.push(next);
		}
	}
	int update = 0;
	if (de[en] % 2)
		update = 1;
	ll ch = de[en] / 2;
	ll dap = cnt1[st] * cnt[en];
	if (!update) {
		for (int i = 1; i <= n; i++)
		{
			if (ch == de[i]) {
				ll s = cnt1[i] * cnt[i];
				s %= mod;
				s *= s;
				s %= mod;
				dap -= s;
				dap += mod;
				dap %= mod;
			}
		}
	}
	dap %= mod;
	for (int i = 0; i < vt2.size(); i++)
	{
		int q = vt2[i].first.first;
		int w = vt2[i].first.second;
		int e = vt2[i].second;
		if (update) {
			if (de[q] <= ch&&ch < de[w])
			{
				ll s = cnt1[w] * cnt[q];
				s %= mod;
				s *= s;
				s %= mod;
				dap -= s;
				dap += mod;
				dap %= mod;
			}
		}
		else
		{
			if (de[q] < ch&&ch < de[w])
			{
				ll s = cnt1[w] * cnt[q];
				s %= mod;
				s *= s;
				s %= mod;
				dap -= s;
				dap += mod;
				dap %= mod;
			}
		}
	}
	printf("%lld", dap);
}