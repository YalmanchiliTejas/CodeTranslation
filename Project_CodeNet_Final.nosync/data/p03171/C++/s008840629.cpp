#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define setbits __builtin_popcount 
#define big 1e9+7
using namespace std;
ll n,k,m,flag = 1,mod,cnt;
ll a[500005],dp[3005][3005],arr[2];
string s;
int main()
{
	IOS
	cin>>n;
	ll x = 0,y = n-1;
	if((n+1)%2)
		flag = -1;
	for(int i = 0; i < n; ++i)
		cin>>a[i],dp[0][i] = a[i]*(flag);
	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < n-i; ++j)
		{
			if((n+i+1)%2)
				dp[i][j] = min(dp[i-1][j+1]-a[j],dp[i-1][j]-a[j+i]);
			else dp[i][j] = max(dp[i-1][j+1]+a[j],dp[i-1][j]+a[i+j]);
			// cout<<dp[i][j]<<" "<<j<<" "<<i<<" "<<dp[i-1][j+1]<<" "<<dp[i-1][j]<<endl;
		}
	}
	cout<<dp[n-1][0]<<endl;
    return 0;
}