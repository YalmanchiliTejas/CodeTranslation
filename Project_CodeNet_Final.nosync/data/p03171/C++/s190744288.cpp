#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
typedef long long ll;
//ll par[2000010],sizem[2000010],sizel[2000010],size[2000010],a,b,q1,q2,q3,x,y;
ll a[100005],n;
ll dp[3001][3001][3];
ll solve(ll i,ll j,ll player=1)
{
	if(i>j)
		return 0;
	if(i>n)
		return 0;
	if(j<1)
		return 0;
	ll maxi = -1;
	ll max2 = -1;
	if(dp[i][j][player]!=-1)
		return dp[i][j][player];
	ll &ans = dp[i][j][player];
	if(player==1)
		ans=max(a[i]+solve(i+1,j,2),a[j]+solve(i,j-1,2));
	if(player==2)
		ans=min(-a[j]+solve(i,j-1,1),-a[i]+solve(i+1,j,1));
	return ans;
}

int main()
{
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(1,n,1)<<endl;
	return 0;
}