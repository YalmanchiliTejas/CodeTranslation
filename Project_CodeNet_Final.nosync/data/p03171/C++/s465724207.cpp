#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3005;

int n;
int a[N], cache[N][N][2];

int dp(int i, int j, int player)
{
	if(j<i)
		return 0;
	int &ans=cache[i][j][player];
	if(ans!=-1)
		return ans;
	if(!player)
		ans=max(a[i]+dp(i+1, j, player^1), a[j]+dp(i, j-1, player^1));
	else
		ans=min(-a[i]+dp(i+1, j, player^1), -a[j]+dp(i, j-1, player^1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<dp(1, n, 0);
	return 0;
}