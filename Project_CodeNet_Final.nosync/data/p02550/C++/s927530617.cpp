#include <bits/stdc++.h>
using namespace std;
#define make_pair(a, b) mp(a, b)
typedef pair<int, int> pii; 
typedef long long ll;
const int maxn = 2e5 + 10;
ll n, x, m, ans, cycle;
int cnt;
ll a[maxn];
int vis[maxn];
int main()
{
	scanf("%lld%lld%lld", &n, &x, &m);
	ll cur = x; 
	while(!vis[cur])
	{
		vis[cur] = ++cnt;
		a[cnt] = cur;
		cur = cur * cur % m;
	}
	if(n < vis[cur])
	{
		for(int i = 1; i <= n; ++i) ans += a[i];
		printf("%lld\n", ans);
		return 0;
	}
	for(int i = 1; i < vis[cur]; ++i) ans += a[i];
	n -= vis[cur] - 1;
	for(int i = vis[cur]; i <= cnt; ++i) cycle += a[i];
	ans += cycle * (n / (cnt - vis[cur] + 1));
	n %= (cnt - vis[cur] + 1);
	for(int i = vis[cur], j = 1; j <= n; ++i, ++j) ans += a[i];
	printf("%lld\n", ans);
	return 0;
}