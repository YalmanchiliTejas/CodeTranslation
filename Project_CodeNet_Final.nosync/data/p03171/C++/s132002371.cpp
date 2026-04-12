#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n);
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define F first
#define S second 
#define pb(n) push_back(n)
const int N=1e5+6;
const ll M=1e9+7;
ll dp[3001][3001],a[3001],pre[3001];
void rec(int i,int j)
{
	if(dp[i][j]!=-1)
		return ;
	if(i==j)
	{
		dp[i][j]=a[i];
		return ;
	}
	if(i>j)
	{
		dp[i][j]=dp[i][j]=0;
		return ;
	}
	rec(i+1,j);
	rec(i,j-1);

	ll val2;
	ll val1=a[i]+pre[j]-pre[i]-dp[i+1][j];
	if(i)
		val2=a[j]+pre[j-1]-pre[i-1]-dp[i][j-1];
	else
		val2=a[j]+pre[j-1]-dp[i][j-1];
	dp[i][j]=max(val1,val2);
}
int main()
{
	int n;
	scn(n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		lscn(a[i]);
		pre[i]=a[i];
		if(i)
			pre[i]+=pre[i-1];
	}
	rec(0,n-1);

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 		printf("%lld \t",dp[i][j]);
	// 	printf("\n");
	// }
	ll taro=dp[0][n-1];
	ll jiro=pre[n-1]-taro;
	lpri(taro-jiro);
}