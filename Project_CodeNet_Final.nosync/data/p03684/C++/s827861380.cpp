#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, pair<int,int> > iii;
int n,cnt=0,res=0,x,y,farm[300000];
vector< pair<int,int> > adjx,adjy;
priority_queue<iii,vector<iii>,greater<iii> > pq;
int Find(int n)
{
	if(farm[n]<0) return n;
	else return farm[n]=Find(farm[n]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x!=y)
	{
		farm[x]+=farm[y];
		farm[y]=x;
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		adjx.push_back({x,i});
		adjy.push_back({y,i});
	}
	sort(adjx.begin(),adjx.end());
	sort(adjy.begin(),adjy.end());
	for(int i=0;i<=n-2;i++)
	{
		pq.push({abs(adjx[i].first-adjx[i+1].first),{adjx[i].second,adjx[i+1].second}});
		pq.push({abs(adjy[i].first-adjy[i+1].first),{adjy[i].second,adjy[i+1].second}});
	}
	memset(farm,-1,sizeof(farm));
	while(!pq.empty())
	{
		if(cnt==n-1) break;
		int u=pq.top().second.first,v=pq.top().second.second,val=pq.top().first;
		pq.pop();
		if(Find(u)!=Find(v))
		{
			cnt++;
			Union(u,v);
			res=res+val;
		}
	}
	cout<<res;
}