#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 3010
using namespace std;
/*
Before Submitting, check:(Delete them before submitting)
*int or long long
*the range of every array(will it get an RE and is it bg enough?)
*special cases(0,1...)
*/
ll n,s,dp[N][N],a[N],ans=0;
int main(){
	ll i,j;
	cin>>n>>s;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]<=s)
		{
			ans=(ans+dp[i-1][s-a[i]]*(n-i+1))%mod;
		}
		if(a[i]==s)
		{
			ans=(ans+(n-i+1)*i)%mod;
		}
		for(j=0;j<N;j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			if(j+a[i]<N)
			{
				dp[i][j+a[i]]=(dp[i][j+a[i]]+dp[i-1][j])%mod;
			}
		}
		dp[i][a[i]]=(dp[i][a[i]]+i)%mod;
	}
	cout<<ans<<endl;
	return 0;
}