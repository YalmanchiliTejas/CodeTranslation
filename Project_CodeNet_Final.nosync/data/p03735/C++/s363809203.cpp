#include <algorithm>
#include <cstdio>
typedef long long ll; 
int a[200005], b[200005], idx[200005]; 
inline bool comp(int x, int y)
{
	return a[x] < a[y]; 
}
int main()
{
	// freopen("ARC073-E.in", "r", stdin); 
	int n, mx = 0, mn = 1e9, mn_opp, mx_opp; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", a + i, b + i); 
		idx[i] = i; 
		if (a[i] > b[i])
			std::swap(a[i], b[i]); 
		if (a[i] < mn)
		{
			mn = a[i]; 
			mn_opp = b[i]; 
		}
		if (b[i] > mx)
		{
			mx = b[i]; 
			mx_opp = a[i]; 
		}
	}
	int cur_mx = mx_opp, cur_mn = mn_opp; 
	for (int i = 0; i < n; i++)
	{
		cur_mx = std::max(cur_mx, a[i]); 
		cur_mn = std::min(cur_mn, b[i]); 
	}
	ll ans = (ll)(mx - cur_mn) * (cur_mx - mn); 
	std::sort(idx, idx + n, comp); 
	int cur = 1e9;
	for (int i = 0; i < n; i++)
	{
		ans = std::min(ans, (ll)(mx - mn) * (cur_mx - std::min(a[idx[i]], cur))); 
		cur = std::min(cur, b[idx[i]]); 
		cur_mx = std::max(cur_mx, b[idx[i]]); 
	}
	printf("%lld\n", ans);
	return 0; 
}
