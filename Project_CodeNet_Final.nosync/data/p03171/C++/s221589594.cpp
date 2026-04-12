#include<cstdio>
#include<cstring>
const int N=3000+10;
int n;
long long f[N][N],a[N];
long long ma(long long a,long long b){return a>b?a:b;}
long long mi(long long a,long long b){return a<b?a:b;}
long long dp(int l,int r,bool ok)
{
	if(~f[l][r])return f[l][r];
	if(l==r)return f[l][r]=ok?a[l]:-a[l];
	if(ok)f[l][r]=ma(dp(l+1,r,!ok)+a[l],dp(l,r-1,!ok)+a[r]);
	else f[l][r]=mi(dp(l+1,r,!ok)-a[l],dp(l,r-1,!ok)-a[r]);
	return f[l][r];
}
int main()
{
	scanf("%d",&n);
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dp(1,n,1);
	printf("%lld",dp(1,n,1));
	return 0;
}
