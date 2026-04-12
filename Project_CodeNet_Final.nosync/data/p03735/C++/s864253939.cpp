#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#define ll long long
using namespace std;
ll dp[200010];
ll dp1[200010];
vector<pair<ll, ll>> vt;
pair<ll, ll> a[200010];
ll visited[200010];
int main()
{
	ll n;
	scanf("%lld", &n);
	ll xx = 0;
	ll yy = 1234567890;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %lld", &a[i].first, &a[i].second);
		vt.push_back({ min(a[i].first,a[i].second ),-i});
		vt.push_back({ max(a[i].second,a[i].first) ,i});
		visited[i] = max(a[i].first, a[i].second);
	}
	sort(vt.begin(), vt.end());
	int ch = 0;
	int t = vt.size();
	ll fi,la;
	for (int i = 0; i < t; i++)
	{
		if (vt[i].second > 0)
			visited[vt[i].second] = i;
	}
	for (int i = 0;i<t; i++)
	{
		if (vt[i].second > 0)
		{
			fi=i;
			break;
		}
	}
	ch = 0;
	for (int i = t - 1; i >= 0; i--)
	{
		if (vt[i].second < 0) {
			la = i;
			break;
		}
	}
	ll dap = (vt[t - 1].first - vt[fi].first)*(vt[la].first - vt[0].first);
	la = max(la, visited[-vt[0].second]);
	for (int i = 1; i <= fi; i++)
	{
		if (la == t - 1)break;
		dap = min(dap, (vt[t - 1].first - vt[0].first)*(vt[la].first - vt[i].first));
		if (i == fi)continue;
		la = max(la, visited[-vt[i].second]);
	}
	printf("%lld", dap);
}