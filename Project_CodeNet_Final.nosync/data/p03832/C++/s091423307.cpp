#include<bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long inv[1005],dp[1005];
long long pw(long long x,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1)res=res*x%md;
		x=x*x%md;
		b>>=1;
	}
	return res;
}
int main()
{
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	dp[n]=1;
	for(int i=1;i<=n;i++)dp[n]=dp[n]*i%md;
	inv[n]=pw(dp[n],md-2);
	for(int i=n;i>0;i--)inv[i-1]=inv[i]*i%md;
	for(int i=a;i<=b;i++)for(int j=0;j<=n;j++)for(int k=c;k<=d;k++)if(j+i*k<=n)dp[j]=(dp[j]+dp[j+i*k]*pw(inv[i],k)%md*inv[k]%md)%md;
	cout<<dp[0]<<endl;
	return 0;
}