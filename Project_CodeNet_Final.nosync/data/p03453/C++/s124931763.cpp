#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
long long mod=1e9+7,n,m,i,j,dis1[100005],dis2[100005],dp1[100005],dp2[100005],s,t,y,x,z,ans;
vector<pair<long long,long long> > e[100005];
int main()
{
	cin>>n>>m>>s>>t;
	while (m--)
	{
		cin>>y>>x>>z;
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,z));
	}
	{
		priority_queue<pair<long long,long long> > pq;
		pq.push(make_pair(-0,s));
		memset(dp1,0,sizeof(dp1));
		memset(dis1,22,sizeof(dis1)); 
		dis1[s]=0;
		dp1[s]=1;
		while (!pq.empty())
		{
			x=pq.top().second;pq.pop();
			for (i=0;i<e[x].size();i++)
			{
				if (dis1[e[x][i].first]>dis1[x]+e[x][i].second)
				{
					dis1[e[x][i].first]=dis1[x]+e[x][i].second;
					pq.push(make_pair(-dis1[e[x][i].first],e[x][i].first));
				}
			}
		}
	}
	{
		priority_queue<pair<long long,long long> > pq;
		pq.push(make_pair(-0,t));
		memset(dp2,0,sizeof(dp2));
		memset(dis2,22,sizeof(dis2)); 
		dis2[t]=0;
		dp2[t]=1;
		while (!pq.empty())
		{
			x=pq.top().second;pq.pop();
			for (i=0;i<e[x].size();i++)
			{
				if (dis2[e[x][i].first]>dis2[x]+e[x][i].second)
				{
					dis2[e[x][i].first]=dis2[x]+e[x][i].second;
					pq.push(make_pair(-dis2[e[x][i].first],e[x][i].first));
				}
			}
		}
	}
	{
		priority_queue<pair<long long,long long> > pq;
		memset(dp1,0,sizeof(dp1));
		dp1[s]=1;
		for (i=1;i<=n;i++) pq.push(make_pair(-dis1[i],i));
		while (!pq.empty())
		{
			x=pq.top().second;pq.pop();
			for (i=0;i<e[x].size();i++)
			{
				if (dis1[e[x][i].first]==dis1[x]+e[x][i].second)
				{
					dp1[e[x][i].first]+=dp1[x];
					dp1[e[x][i].first]%=mod;
				}
			}
		}
	}
	{
		priority_queue<pair<long long,long long> > pq;
		memset(dp2,0,sizeof(dp2));
		dp2[t]=1;
		for (i=1;i<=n;i++) pq.push(make_pair(-dis2[i],i));
		while (!pq.empty())
		{
			x=pq.top().second;pq.pop();
			for (i=0;i<e[x].size();i++)
			{
				if (dis2[e[x][i].first]==dis2[x]+e[x][i].second)
				{
					dp2[e[x][i].first]+=dp2[x];
					dp2[e[x][i].first]%=mod;
				}
			}
		}
	}
	ans=dp1[t]*dp1[t]%mod;
	for (i=1;i<=n;i++)
	{
		if (dis1[i]==dis2[i]&&dis1[i]+dis2[i]==dis1[t]) (ans-=dp1[i]*dp2[i]%mod*dp1[i]%mod*dp2[i]%mod)%=mod;
		for (j=0;j<e[i].size();j++)
		{
			if (dis1[i]+e[i][j].second+dis2[e[i][j].first]==dis1[t])
			{
				//cerr<<e[i][j].first<<endl;
				int x=e[i][j].first;
				if (dis1[i]*2<dis1[t]&&dis1[x]*2>dis1[t])
				{
					//cerr<<i<<' '<<x<<endl;
					(ans-=dp1[i]*dp2[e[i][j].first]%mod*dp1[i]%mod*dp2[e[i][j].first]%mod)%=mod;
				}
			}
		}
	}
	cout<<(ans%mod+mod)%mod;
	return 0;
}