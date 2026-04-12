#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k;
int L[100];
int D[16];
int G[100][100];
int dp[1<<16];
main()
{
	cin>>n>>m>>k;
	for(int i=0;i<1<<m;i++)dp[i]=1e9;
	for(int i=0;i<m;i++)
	{
		cin>>D[i];D[i]--;
		L[D[i]]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			int v;cin>>v;v--;G[i][j]=v;
		}
	}
	dp[(1<<m)-1]=0;
	queue<pair<int,int> >P;
	P.push(make_pair((1<<m)-1,0));
	while(!P.empty())
	{
		int i=P.front().first,c=P.front().second;
		P.pop();
		if(dp[i]<c)continue;
		for(int j=0;j<k;j++)
		{
			int next=0;
			for(int l=0;l<m;l++)
			{
				if(!(i&1<<l))continue;
				int u=G[D[l]][j];
				if(L[u]==0)continue;
				next|=1<<L[u]-1;
			}
			if(dp[next]>c+1)
			{
				dp[next]=c+1;
				P.push(make_pair(next,c+1));
			}
		}
	}
	cout<<dp[0]<<endl;
}

