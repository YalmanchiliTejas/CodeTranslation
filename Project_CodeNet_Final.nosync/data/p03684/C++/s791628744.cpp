//三角形两边之和大于第三边 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<set>

using namespace std;

const int maxn=200010;

struct node 
{
	int x,y;
};

int n;
node town[maxn];

pair<int,int> xx[maxn],yy[maxn];

int dist(int x,int y)
{
	return min(abs(town[x].x-town[y].x),abs(town[x].y-town[y].y));
}

///union find set
int par[maxn];
void reset()
{
	for(int i=0; i<maxn; i++)
	{
		par[i]=i;
	}
}
int find(int x)
{
	if(par[x]!=x)
	{
		return par[x]=find(par[x]);
	}
	return x;
}
bool unite(int x,int y)
{
	int fax=find(x),fay=find(y);
	if(fax==fay)return 1;
	if(fax==y)return 0;
	par[fax]=fay;
	return 1;
}
bool same(int x,int y)
{
	if(find(x)==find(y))return 1;
	return 0;
}
///////////////////


int main()
{
	ios::sync_with_stdio(0);
	reset();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>town[i].x>>town[i].y;
		xx[i]=make_pair(town[i].x,i);
		yy[i]=make_pair(town[i].y,i);
	}
	
	sort(xx+1,xx+n+1);
	sort(yy+1,yy+n+1);
	
	set<pair<int,pair<int,int> > > edge;
	
	for(int i=1;i<n;i++)//n+1
	{
		edge.insert(make_pair(dist(xx[i].second,xx[i+1].second),make_pair(xx[i].second,xx[i+1].second)));
		edge.insert(make_pair(dist(yy[i].second,yy[i+1].second),make_pair(yy[i].second,yy[i+1].second)));
	}
	
	int used=0;
	long long value=0;
	for(set<pair<int,pair<int,int> > >::iterator it=edge.begin();it!=edge.end();it++)//kruskal
	{
		if(used==n-1)break;
		if(find(it->second.first)!=find(it->second.second))
		{
			unite((*it).second.first,(*it).second.second);
			used++;
			value+=(*it).first;
		}
	}
	cout<<value<<'\n';
	return 0;
}

/*
3 1 5 3 9 7 8

6 8 3 4 9 12 19 18 1 13 5 7 6
*/