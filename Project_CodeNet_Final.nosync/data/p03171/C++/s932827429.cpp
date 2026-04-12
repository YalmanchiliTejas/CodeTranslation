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
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
ll dp[3005][3005];//[)
int n;
int a[3005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][i]=0;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=0;i<n;i++)
		{
			int j=i+k;
			if(j>n) break;
			if(k&1) dp[i][j]=-1LL*inf*inf;else dp[i][j]=1LL*inf*inf;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=0;i<n;i++)
		{
			int j=i+k;
			if(j>n) break;
			if(k&1)
			{
				if(i+1<=j) dp[i][j]=max(dp[i][j],dp[i+1][j]+a[i]);
				if(j-1>=i) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[j-1]);
			}
			else
			{
				if(i+1<=j) dp[i][j]=min(dp[i][j],dp[i+1][j]-a[i]);
				if(j-1>=i) dp[i][j]=min(dp[i][j],dp[i][j-1]-a[j-1]);
			}
		}
	}
	if(n&1) cout<<dp[0][n]<<endl;else cout<<-dp[0][n]<<endl;
	return 0;
}