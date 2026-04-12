#include<bits/stdc++.h>
#define pb push_back
#define rep(a,b,c) for(int a=(int)b;a<(int)c;a++)
#define repe(a,b,c) for(int a=(int)b;a<=(int)c;a++)
#define repk(a,b,c,k) for(int a=(int)b;a<(int)c;a+=(int)k)
#define comeback std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define int long long int
#define pii pair<int,int>
#define ful(a) a.begin(),a.end()
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
using namespace std;
int em(int x,int n)
{
    if(n==0)
    return 1;
    else if(n%2==0)
    return em((x%mod*x%mod)%mod,n/2);
    else
    return (x%mod*em((x%mod*x%mod)%mod,(n-1)/2))%mod;
}
int dp[3001][3001];
//int a[3001];
/*int fun(int lo,int hi){
	if(lo==hi)
		return a[lo];
	if(dp[lo][hi]!=-1)
		return dp[lo][hi];
	int ans=0;
	ans=max(a[lo]-fun(lo+1,hi),a[hi]-fun(lo,hi-1));
	return dp[lo][hi]=ans;
}*/
signed main()
{
	comeback
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif*/
		int n,m,i,j,k,l;
		cin>>n;
		int a[n+1];
		repe(i,1,n)
		cin>>a[i];
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			dp[i][i]=a[i];
		//cout<<fun(1,n);
		for(i=n;i>=1;i--){
			for(j=i+1;j<=n;j++)
				dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
		cout<<dp[1][n];
}