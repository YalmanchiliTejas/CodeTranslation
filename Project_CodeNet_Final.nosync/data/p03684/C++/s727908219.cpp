#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>
#include <cstring>
#include <bitset>
#include <stack>
using namespace std;
#define MP make_pair
#define PB push_back

int n,ans;
struct node{
	int x,y,id;
	
	inline void scan(int i)
	{
		scanf("%d%d",&x,&y);
		id=i;
	}
	
}a[100005],b[100005];

int par[100005];

vector <pair<int,pair<int,int> > >edge;

inline int dist(int x,int y)
{
	int r1=abs(b[x].x-b[y].x);
	int r2=abs(b[x].y-b[y].y);
	return min(r1,r2);
}

inline bool cmp1(node p,node q)
{
	return p.x<q.x;
}

inline bool cmp2(node p,node q)
{
	return p.y<q.y;
}

inline int Find(int x)
{
	return (x==par[x]?x:par[x]=Find(par[x]));
}

inline void Union(int x,int y)
{
	par[Find(x)]=Find(y);
}

inline void kruskal()
{
	for (int i=1;i<=n;i++) par[i]=i;
	sort(edge.begin(),edge.end());
	for (int i=0;i<edge.size();i++)
	{
		int x=edge[i].second.first;
		int y=edge[i].second.second;
		if (Find(x)==Find(y)) continue;
		ans+=dist(x,y);
		Union(x,y);
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		a[i].scan(i);
		b[i]=a[i];
	}
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<n;i++)
		edge.PB(MP(dist(a[i].id,a[i+1].id),MP(a[i].id,a[i+1].id)));
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<n;i++)
		edge.PB(MP(dist(a[i].id,a[i+1].id),MP(a[i].id,a[i+1].id)));
	edge.resize(unique(edge.begin(),edge.end())-edge.begin());
	kruskal();	
	printf("%d",ans);
	return 0;
}