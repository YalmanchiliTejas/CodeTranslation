#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,i,ok,d[100005],dp[100005],x,y,rt;
vector<int> s[100005];
void dfs(int p,int f)
{
	int i,v,sum=0;
	dp[p]=1;
	for(i=0;i<s[p].size();i++)
	{
		v=s[p][i];
		if(v==f)continue;
		dfs(v,p);
		if(dp[v]==1)sum++,dp[p]=0;
	}
	if(sum>1)
	{
		printf("First\n");
		exit(0);
	}
	if(p==rt&&dp[rt]==1)
	{
		printf("First\n");
		exit(0);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		s[x].push_back(y);
		s[y].push_back(x);
		d[x]++;d[y]++;
	}
	for(i=1;i<=n;i++)if(d[i]>1){dfs(rt=i,0);break;}
	printf("Second\n");
	return 0;
}