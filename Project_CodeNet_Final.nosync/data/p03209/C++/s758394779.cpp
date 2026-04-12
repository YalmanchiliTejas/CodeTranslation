#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=55;
ll a[maxn],b[maxn];
ll dfs(int dep,ll x)
{
	if(x==a[dep])
		return b[dep];
	if(dep==0)
		return 1;
	if(x<=1)
		return 0;
	if(1+a[dep-1]>=x)
		return dfs(dep-1,x-1);
	if(2+a[dep-1]==x)
		return b[dep-1]+1;
	return b[dep-1]+1+dfs(dep-1,x-2-a[dep-1]);
}
int main()
{
	int n;ll x;
	cin>>n>>x;
	a[0]=b[0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=2*a[i-1]+3;
		b[i]=2*b[i-1]+1;
	}
	printf("%lld\n",b[n]-dfs(n,a[n]-x));
	return 0;
}
