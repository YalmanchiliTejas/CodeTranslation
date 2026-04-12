#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], cache[N][4];
bool vis[N][4];

int dp(int idx, int have)
{
	if(idx > n)
	{
		if(have <= 1)
			return 0;
		return -1e18;
	}
	int &ans = cache[idx][have];
	if(vis[idx][have])
		return ans;
	vis[idx][have] = 1;
	if(!have)
		ans = a[idx] + dp(idx + 2, have);
	else
		ans = max(a[idx] + dp(idx + 2, have), dp(idx + 1, have - 1));
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans;
	if(n % 2)
		ans = max(dp(1, 2), dp(2, 1));
	else
		ans = max(dp(1, 1), dp(2, 0));
	cout << ans;
	return 0;
}