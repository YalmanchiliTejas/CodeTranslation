#include <bits/stdc++.h>
using namespace std;

vector<int> d[10];

struct mode{
	int n;
	bool has[10];
};

mode dfs[100000];

int main()
{
	int n,m,i,j,a,b,top,tmp,count,ans;
	bool hast[10];
	cin>>n>>m;
	for(i=0;i<m;i++) 
	{
		cin>>a>>b;
		if(b!=1) d[a].push_back(b);
		if(a!=1) d[b].push_back(a);
	}
	top=0,dfs[0].n=1,dfs[0].has[1]=1,ans=0;
	while(top>=0)
	{
		tmp = dfs[top].n,count=0;
		for(i=1;i<=n;i++) hast[i]=dfs[top].has[i],count+=hast[i];
		top--;
		if(count==n)
		{
			ans++;
			continue;
		}
		for(i=0;i<d[tmp].size();i++)
		{
			if(!(hast[d[tmp][i]]))
			{
				dfs[++top].n=d[tmp][i];
				for(j=1;j<=n;j++) dfs[top].has[j]=hast[j];
				dfs[top].has[d[tmp][i]] = 1;
			}
		}
	}
	cout<<ans;
}