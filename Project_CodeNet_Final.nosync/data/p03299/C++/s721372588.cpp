#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const ll INF = 1e9;
inline ll read(){
	ll X = 0,w = 0 ;
	char ch = 0;
	while(!isdigit(ch)) {w |= ch == '-';ch = getchar();}
	while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();
	return w ? -X : X;
}


ll h[1005];
ll Has[1005];
ll tot;
ll dp[1005][1005];
ll n;
ll mod=1e9+7;
ll Pow(ll x,ll y)
{
	if(y<=0)
	{
		return 1;
	}
	ll res=1;
	while(y)
	{
		if(y&1)
		{
			res=res*x%mod;
		}
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}
int main()
{
	cin>>n;
	dp[0][0]=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>h[i];
		Has[++tot]=h[i];
	}
	sort(Has+1,Has+tot+1);
	tot=unique(Has+1,Has+tot+1)-Has-1;
	for(ll i=1;i<=n;i++)
	{
		h[i]=lower_bound(Has+1,Has+tot+1,h[i])-Has;
	}
	for(ll i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0]*2%mod;
		for(ll j=h[i]+1;j<=h[i-1];j++)
		{
			dp[i][0]=(dp[i][0]+dp[i-1][j]*2%mod)%mod;
		}
		ll tmpPow=Pow(2,Has[h[i]]-Has[h[i-1]]);
		for(ll j=1;j<=min(h[i-1],h[i]);j++)
		{
			dp[i][j]=dp[i-1][j]*tmpPow%mod;
		}
		for(ll j=h[i-1]+1;j<=h[i];j++)
		{
			dp[i][j]=(dp[i][j]+j==1?(dp[i-1][0]*(Pow(2,Has[j])-2)%mod*Pow(2,Has[h[i]]-Has[j])%mod):(dp[i-1][0]*2*(Pow(2,Has[j]-Has[j-1])-1)%mod*Pow(2,Has[h[i]]-Has[j])%mod))%mod;
		}
	}
	ll res=0;
	for(ll i=0;i<=tot;i++)
	{
		res=(res+dp[n][i])%mod;
	}
	cout<<res<<endl;
	return 0;
}