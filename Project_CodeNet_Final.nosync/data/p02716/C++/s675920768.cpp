#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b%2==1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		if(n==1)
		cout<<0;
		else if(n%2==0)
		{
			ll s=0,g=0;
			FOR(i,0,n)
			{
				if(i%2==0)
				s+=a[i];
			}
			ll ma=s;
			for(int i=n-1;i>0;i-=2)
			{
				s-=a[i-1];
				g+=a[i];
				ma=max(ma,(s+g));
			}
			cout<<ma;
		}
		else
		{
			ll dp[n+1][3];
			dp[0][0]=a[0];
			dp[0][1]=(-1*INF);
			dp[0][2]=(-1*INF);
			dp[1][0]=(-1*INF);
			dp[1][1]=a[1];
			dp[1][2]=(-1*INF);
			dp[2][0]=a[0]+a[2];
			dp[2][1]=(-1*INF);
			dp[2][2]=a[2];
			FOR(i,3,n)
			{
				dp[i][0]=dp[i-2][0]+a[i];
				dp[i][1]=max(dp[i-3][0],dp[i-2][1])+a[i];
				dp[i][2]=max( (i>3 ? dp[i-4][0] : 1),max(dp[i-3][1],dp[i-2][2])) +a[i];
			}
			cout<<max(dp[n-1][2],max(dp[n-2][1],dp[n-3][0]));
//			FOR(i,0,n)
//			{
//				cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<'\n';
//			}
		}
		
	}
	return 0;
}