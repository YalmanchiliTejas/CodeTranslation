#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,a[N],pre[N],suf[N],dp[N],ans=-LINF;
void run1()
{
	ll i;
	for(i=0;i<n;i+=2)
	{
		ans=max(ans,pre[i]+suf[i+3]);
	}
	ans=max(ans,pre[n-2]);
	ans=max(ans,suf[1]);
	cout<<ans<<endl;
	return;
}
int main(){
	ll i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(pre,-127,sizeof(pre));
	memset(suf,-127,sizeof(suf));
	memset(dp,-127,sizeof(dp));
	pre[0]=a[0];
	pre[1]=a[1];
	for(i=2;i<n;i++)
	{
		pre[i]=pre[i-2]+a[i];
	}
	suf[n-1]=a[n-1];
	suf[n-2]=a[n-2];
	for(i=n-3;i>=0;i--)
	{
		suf[i]=a[i]+suf[i+2];
	}
	if(n%2==0)
	{
		run1();
		return 0;
	}
	for(i=n-2;i>=0;i-=2)
	{
		if(dp[i+2]>-LINF||suf[i+3]>-LINF)
		{
			dp[i]=max(dp[i+2],suf[i+3])+a[i];
		}
	}
	for(i=0;i<n;i+=2)
	{
		ans=max(ans,pre[i]+suf[i+4]);
		if(dp[i+3]>-LINF)
		{
			ans=max(ans,pre[i]+dp[i+3]);
		}
		ans=max(ans,pre[i]+suf[i+3]);
	}
	ans=max(ans,pre[n-3]);
	ans=max(ans,suf[2]);
	ans=max(ans,suf[1]);
	cout<<ans<<endl;
	return 0;
}