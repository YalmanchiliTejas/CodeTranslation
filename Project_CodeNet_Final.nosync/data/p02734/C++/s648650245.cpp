#include <bits/stdc++.h>
using namespace std;

const int M=3005;
const int MO=998244353;

inline int add(int x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
	return x;
}

inline int mul(int x,int y)
{
	return 1LL*x*y%MO;
}

int a[M];
int dp[M];

int main()
{
	int n,s; scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<endl;
		dp[0]=i;
		if(a[i]<=s)
			ans=add(ans,mul(dp[s-a[i]],n-i+1));
		for(int j=s;j>=a[i];j--)
			dp[j]=add(dp[j],dp[j-a[i]]);
	}
	printf("%d\n",ans);
	return 0;
}