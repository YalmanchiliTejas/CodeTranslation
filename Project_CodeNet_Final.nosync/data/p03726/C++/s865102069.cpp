#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,dp[100005],x,y;
vector<int> bi[100005];
void dfs(int x,int fa)
{
	int i;
	dp[x]=0;
	for (vector<int>::iterator it=bi[x].begin();it!=bi[x].end();it++)
	{
		if (*it==fa) continue;
		dfs(*it,x);
		if (dp[*it]==0) dp[x]++;
		if (dp[*it]>1||dp[x]>1)
		{
			dp[x]=2;
			break;
		}
	}
}
int main()
{
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs(1,0);
	if (dp[1]==1) cout<<"Second"; else cout<<"First";
	return 0;
}