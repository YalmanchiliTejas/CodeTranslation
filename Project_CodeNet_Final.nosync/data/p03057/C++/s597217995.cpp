#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define N 200100
#define M 1000000007
using namespace std;

ll n,m,mx,ans,dp[N],qz[N];
char str[N];

inline void Add(ll &u,ll v){u=(u+v)%M;}
int main()
{
	ll i,j,t;
	cin>>n>>m;
	scanf("%s",str+1);
	for(i=1;i<=m;i++) if(str[i]!=str[1]) break;
	mx=i-1;
	if(mx==m)
	{
		dp[0]=qz[0]=ans=1;
		for(i=0;i<=n;i++)
		{
			if(i>=2) dp[i]=qz[i-2];
			qz[i]=(qz[i-1]+dp[i])%M;
			if(n-i>=2) Add(ans,dp[i]*(n-i)%M);
		}
		cout<<ans;
		return 0;
	}
	if(n&1)
	{
		puts("0");
		return 0;
	}
	if(mx%2==0) mx++;
	for(t=0;i<=m;i++)
	{
		if(str[i]==str[1]) t++;
		else
		{
			if(t&1) mx=min(mx,t);
			t=0;
		}
	}
	n/=2,mx=(mx+1)/2;
	dp[0]=qz[0]=1;
	for(i=0;i<=n;i++)
	{
		if(i)
		{
			dp[i]=(M+qz[i-1]-(i-mx-1>=0?qz[i-mx-1]:0))%M;
			qz[i]=(qz[i-1]+dp[i])%M;
		}
		if(n-i<=mx) Add(ans,(n-i)*dp[i]*2%M);
	}
	cout<<ans;
}