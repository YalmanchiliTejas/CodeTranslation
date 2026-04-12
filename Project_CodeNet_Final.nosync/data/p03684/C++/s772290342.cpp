#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long ans;
int par[100010];
vector<pair<int ,int> >vx,vy;
vector<pair<int ,pair<int ,int> > >edges;
int root(int x)
{
	if(par[x]==x)return x;
	return par[x]=root(par[x]);
}
void un(pair<int ,pair<int ,int> >t)
{
	int x=t.second.first,y=t.second.second;
	int w=t.first;
	x=root(x);y=root(y);
	if(x!=y)
	{
		par[x]=y;
		ans+=w;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		int x,y;
		scanf("%d%d",&x,&y);
		vx.push_back(make_pair(x,i));
		vy.push_back(make_pair(y,i));
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	for(int i=0;i+1<vx.size();i++)
	{
		edges.push_back(make_pair(vx[i+1].first-vx[i].first,make_pair(vx[i].second,vx[i+1].second)));
	}
	for(int i=0;i+1<vy.size();i++)
	{
		edges.push_back(make_pair(vy[i+1].first-vy[i].first,make_pair(vy[i].second,vy[i+1].second)));
	}
	sort(edges.begin(),edges.end());
	for(int i=0;i<edges.size();i++)
	{
		un(edges[i]);
	}
	printf("%d",ans);
	return 0;
}