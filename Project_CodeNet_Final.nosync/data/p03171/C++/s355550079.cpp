#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
long long n,a[3030],dp[3030][3030];
long long dfs(long long x,long long y)
{
	if(x==y)
	{
		dp[x][y]=a[x];
		return dp[x][y];
	}
	if(dp[x][y]!=1e15)
	{
		return dp[x][y];
	}
	dp[x][y]=max(a[x]-dfs(x+1,y),a[y]-dfs(x,y-1));
	return dp[x][y];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<3010;i++)
	{
		for(int j=0;j<3010;j++)
		{
			dp[i][j]=1e15;
		}
	}
	cout<<dfs(0,n-1)<<endl;
	return 0;
}