#include<bits/stdc++.h>
#define inf 1000000010
using namespace std;
struct cmp{bool operator()(int a,int b){return a<=b;}};
int main()
{
	int f[100010];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	scanf("%d",&f[i]);
	int dp[100010];
	for(int i=0;i<n;i++)
	dp[i]=inf;
	for(int i=n-1;i>=0;i--)
	{
		*lower_bound(dp,dp+n,f[i],cmp())=f[i];
	}
	cout<<lower_bound(dp,dp+n,inf)-dp;
}