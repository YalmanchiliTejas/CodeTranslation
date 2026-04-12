#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << " = "<< x << "\n"; 
int a[3005];
int dp[3005][3005];
int n, s;
int solve(int idx, int sum)
{
	if(sum == 0) return n - idx + 1;
	if(sum < 0) return 0;
	if(idx >= n) return 0;

	int &res = dp[idx][sum];
	if(res != -1) return res;
	res = solve(idx+1, sum) + solve(idx+1, sum - a[idx]);
	res %= 998244353;
	return res;
}
signed main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	cin >> n >> s;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++)
		ans += solve(i, s) ;
	cout << ans % 998244353 << "\n";
	
} 
