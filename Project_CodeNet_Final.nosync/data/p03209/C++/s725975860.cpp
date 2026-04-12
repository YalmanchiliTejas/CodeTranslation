#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 110
int n; ll x; 
ll len[N], tot[N]; 
ll res;

void DFS(ll l, ll r, int cur)
{
	//printf("%lld %lld %d\n", l, r, cur);
	if (cur < 0 || l > x) return;  
	if (r <= x) 
	{
		res += tot[cur]; 
		return;
	}
	ll mid = (l + r) >> 1;
	if (mid <= x) ++res;
	DFS(l + 1, mid - 1, cur - 1);
	DFS(mid + 1, r - 1, cur - 1);
}

int main()
{
	len[0] = 1;
	for (int i = 1; i <= 50; ++i)
		len[i] = 2 * len[i - 1] + 3;
	tot[0] = 1;
	for (int i = 1; i <= 50; ++i)
		tot[i] = 2 * tot[i - 1] + 1;
	while (scanf("%d%lld", &n, &x) != EOF)
	{
		res = 0;
		DFS(1, len[n], n); 
		printf("%lld\n", res); 
	}
	return 0;
}
