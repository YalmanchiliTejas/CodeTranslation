#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <map>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;
typedef pair <P,int> P2;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=1;
		}
	}
	int find(int x)
	{
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y])
		{
			par[x]=y;
		}
		else
		{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
UF uf;
vector <PP> edge;
P2 p1[SIZE];
P2 p2[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		p1[i]=P2(P(a,b),i);
		p2[i]=P2(P(b,a),i);
	}
	sort(p1,p1+n);
	sort(p2,p2+n);
	for(int i=0;i+1<n;i++)
	{
		P p=p1[i].first,q=p1[i+1].first;
		int ct=min(abs(p.first-q.first),abs(p.second-q.second));
		edge.push_back(PP(ct,P(p1[i].second,p1[i+1].second)));
	}
	for(int i=0;i+1<n;i++)
	{
		P p=p2[i].first,q=p2[i+1].first;
		int ct=min(abs(p.first-q.first),abs(p.second-q.second));
		edge.push_back(PP(ct,P(p2[i].second,p2[i+1].second)));
	}
	sort(edge.begin(),edge.end());
	ll ret=0;
	uf.init(n+2);
	for(int i=0;i<edge.size();i++)
	{
		P p=edge[i].second;
		if(!uf.same(p.first,p.second))
		{
			uf.unite(p.first,p.second);
			ret+=edge[i].first;
		}
	}
	printf("%lld\n",ret);
	return 0;
}
