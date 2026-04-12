#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,pair<int,int> > >G;
int parent[1<<17],rankt[1<<17];
pair<int,int>x[1<<17],y[1<<17];
int find(int a)
{
	return a!=parent[a]?parent[a]=find(parent[a]):a;
}
int unite(int a,int b)
{
	int pa=find(a),pb=find(b);
	if(rankt[pa]<rankt[pb])
	{
		parent[pb]=pa;
	}
	else
	{
		parent[pa]=pb;
		if(rankt[pa]==rankt[pb])rankt[pb]++;
	}
}
main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		cin>>x[i].first>>y[i].first;
		x[i].second=y[i].second=i;
	}
	sort(x,x+n);
	sort(y,y+n);
	for(int i=0;i<n-1;i++)
	{
	G.push_back(make_pair(abs(x[i+1].first-x[i].first),make_pair(x[i].second,x[i+1].second)));
	G.push_back(make_pair(abs(y[i+1].first-y[i].first),make_pair(y[i].second,y[i+1].second)));
	}
	sort(G.begin(),G.end());
	long ans=0;
	for(int i=0;i<G.size();i++)
	{
		int nx=G[i].second.first,ny=G[i].second.second,cost=G[i].first;
		int px=find(nx),py=find(ny);
		if(px==py)continue;
		else
		{
			ans+=cost;
			unite(px,py);
		}
	}
	cout<<ans<<endl;
}
