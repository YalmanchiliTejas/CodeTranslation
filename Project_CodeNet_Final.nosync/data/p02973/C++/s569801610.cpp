#include<bits/stdc++.h>

using namespace std;

const int N=100000+5;
const int inf=10000000;

int dis[N];
int f[N];
int dp[N];
int q[N];
int n;
int a[N];

int main()
{
	int i=1;
	cin>>n;
	int j;
	for(i=1;i<=n;++i)cin>>dis[i];
	int ans=0;
	reverse(dis+1,dis+1+n);
	memset(q,0x3f,sizeof(q));
	for(i=1;i<=n;++i)
	{
		dp[i]=upper_bound(q+1,q+n,dis[i])-q;
		q[dp[i]]=dis[i];
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
