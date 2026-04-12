#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int,int> ii;

int n;
int mx_r, mn_r = 1e9, mx_b, mn_b = 1e9; 
ii a[200001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].first >> a[i].second;
		if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
		mn_r = min(mn_r, a[i].first);
		mx_r = max(mx_r, a[i].first);
		mn_b = min(mn_b, a[i].second);
		mx_b = max(mx_b, a[i].second);
	}	
	int res = (mx_r - mn_r) * (mx_b - mn_b);
	mx_r = mx_b;		
	multiset<int> c;
	for (int i=1;i<=n;i++)
		c.insert(a[i].first);
	res = min(res, (mx_r - mn_r) * ((*c.rbegin()) - (*c.begin())));
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		c.erase(c.find(a[i].first));
		c.insert(a[i].second);
		res = min(res, (mx_r - mn_r) * ((*c.rbegin()) - (*c.begin())));
	}
	cout << res;
}