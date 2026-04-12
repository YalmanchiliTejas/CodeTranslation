/*input
10
1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1
*/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define input(str) freopen(str,"r",stdin);
#define output(str) freopen(str,"w",stdout);
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF  3e16+1
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld\n",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define modd 1000000007
#define len(x) x.size()
#define all(v) (v.begin(),v.end())
#define ll int
#define pi 3.1415926535897932384626
#define ld double
const int N =6e5+5;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
int powmod(int base,int exp,int mod)
{
	int res=1LL;
	while(exp>0)
	{
		if(exp&1LL)
			res=(res*base)%mod;
		exp/=2LL;
		base=(base*base)%mod;
	}
	return res%mod;
}
int dp[3005][3005];
signed main()
{
	int n;
	cin>>n;
	int a[n+1];
	Rep(i,n)
	{
		cin>>a[i];
		if((n&1))
		{
			dp[i][i]=a[i];
		}
		else
		{
			dp[i][i]=-a[i];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j+i<=n;j++)
		{
			if(n&1)
			{
				if(!(i&1))
				{
					dp[j][j+i]=max(dp[j+1][j+i]+a[j],dp[j][j+i-1]+a[j+i]);
				}
				else
				{
					dp[j][j+i]=min(dp[j+1][j+i]-a[j],dp[j][j+i-1]-a[j+i]);
				}
			}
			else
			{
				if(!(i&1))
				{
					dp[j][j+i]=min(dp[j+1][j+i]-a[j],dp[j][j+i-1]-a[j+i]);
				}
				else
				{
					dp[j][j+i]=max(dp[j+1][j+i]+a[j],dp[j][j+i-1]+a[j+i]);
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
}