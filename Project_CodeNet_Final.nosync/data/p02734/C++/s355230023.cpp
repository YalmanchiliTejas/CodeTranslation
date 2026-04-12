#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3005;
const int MOD = 998244353;
 
int n, s;
int a[N], cache[N][N];
 
int dp(int idx, int s)
{
	if(s == 0)
		return (n - idx + 2);
	if(s < 0)
		return 0;
	if(idx > n)
		return 0;
	int &ans = cache[idx][s];
	if(ans != -1)
		return ans;
	ans = dp(idx + 1, s) + dp(idx + 1, s - a[idx]);
	ans %= MOD;
	return ans;
}
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += dp(i, s);
	ans %= MOD;
	cout << ans;
	return 0;
}