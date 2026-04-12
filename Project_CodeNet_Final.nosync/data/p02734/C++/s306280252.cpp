#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int dp[3002][3002];
const int mod=998244353;
int32_t main()
{
	int n=in();int S=in();
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)a[i]=in();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=3000;j++)dp[i][j]=dp[i-1][j];
		
		dp[i][a[i]]=(dp[i][a[i]]+i)%mod;
		for(int j=0;j+a[i]<=S;j++)
		{dp[i][j+a[i]]+=dp[i-1][j];dp[i][j+a[i]]%=mod;}
		
		ans+=dp[i][S];ans%=mod;
		
	}
	
	cout<<ans;
	

}