#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int h[105];
int res=1;
vector <pair<pair<int,int>,int> >vec;
int dp[105][105][2];

namespace combinatorics
{
	int mod=1e9+7;
	inline int add(int a,int b)
	{
		return (a+b)%mod;
	}
	inline int minus(int a,int b)
	{
		return (a-b+mod)%mod;
	}
	inline int mutiply(int a,int b)
	{
		return (1LL*a*b)%mod;
	}
	inline int fastpow(int basic,int x)
	{
		int res=1;
		while(x)
		{
			if(x&1)	res=mutiply(res,basic);
			basic=mutiply(basic,basic);
			x>>=1;
		}
		return res;
	}
	inline int inv(int x)
	{
		return fastpow(x,mod-2);
	}
};
using namespace combinatorics;

inline void solve(int l,int r)
{
//	cout<<l<<' '<<r<<endl;
//	Sleep(1000);
	if(l==r) return;
	int mi=inf,ma=inf;
	for(int i=l;i<r;i++)
	{
		mi=min(mi,h[i]);
	}
	vec.push_back({{l,r},mi-(l==0 && r==n)});
	for(int i=l;i<r;i++)
	{
		h[i]-=mi;
	}
	int last=l;
	for(int i=l;i<=r;i++)
	{
		if(h[i]==0) solve(last,i),last=i+1;
	}
}

inline int way(int l,int r)
{
	int res=0;
	for(auto x:vec)
	{
		if(l<=x.first.first && r>=x.first.second) res=(res+x.second)%(mod-1);
	}
	return fastpow(2,res);
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("1.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	solve(0,n);
//	for(auto x:vec)
//	{
//		printf("From %d to %d, having %d floors.\n",x.first.first+1,x.first.second,x.second);
//	}
	dp[0][1][0]=1;
	dp[0][1][1]=1;
	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<=i+1;j++)
		{
			for(int k=0;k<2;k++)
			{
				dp[i+1][j+1][k]=add(dp[i+1][j+1][k],dp[i][j][k]);
				dp[i+1][1][!k]=add(dp[i+1][1][!k],mutiply(dp[i][j][k],way(i-j+1,i+1)));
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		dp[n-1][i][0]=mutiply(dp[n-1][i][0],way(n-i,n));
		dp[n-1][i][1]=mutiply(dp[n-1][i][1],way(n-i,n));
		res=add(res,add(dp[n-1][i][0],dp[n-1][i][1]));
	}
	cout<<res<<endl;
	return 0;
}