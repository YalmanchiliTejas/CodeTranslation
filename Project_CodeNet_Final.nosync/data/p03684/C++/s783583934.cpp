#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int px[100005],py[100005],par[100005];
pair<int,int> sx[100005],sy[100005];
int find(int x)
{
	return x==par[x]?x:par[x]=find(par[x]);
}
int unite(int u,int v)
{
	u=find(u);
	v=find(v);
	if(u==v)
	    return 0;
	par[u]=v;
    return 1;
}
int dist(int x,int y)
{
	return min(abs(px[x]-px[y]),abs(py[x]-py[y]));
}
int main()
{
	int n;
	cin>>n;
	for(int j=0;j<n;j++)
	{
		cin>>px[j]>>py[j];
		par[j]=j;
		sx[j]=make_pair(px[j],j);
		sy[j]=make_pair(py[j],j);
	}
	sort(sx,sx+n);
	sort(sy,sy+n);
	set<pair<int,pair<int,int> > > st;
	for(int j=0;j<n-1;j++)
	{
		st.insert(make_pair(dist(sx[j].second,sx[j+1].second),make_pair(sx[j].second,
		sx[j+1].second)));
		st.insert(make_pair(dist(sy[j].second,sy[j+1].second),make_pair(sy[j].second,
		sy[j+1].second)));
	}
	long long res=0;
	while(st.size())
	{
		pair<int,pair<int,int> > cur=*st.begin();
		st.erase(st.begin());
		int u=cur.second.first,v=cur.second.second;
		res+=unite(u,v)*dist(u,v);
	}
	cout<<res;
	return 0;
} 