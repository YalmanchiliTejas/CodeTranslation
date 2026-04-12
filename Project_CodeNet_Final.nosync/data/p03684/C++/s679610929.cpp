#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
const int Maxn=1e5+5;
int px[Maxn],py[Maxn],par[Maxn];
pair <int,int> sx[Maxn],sy[Maxn];
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
bool union_(int u,int v)
{
	u=find(u);
	v=find(v);
	if (u==v) return false;
	par[u]=v;
	return true;
}
int dist(int x,int y)
{
	return min(abs(px[x]-px[y]),abs(py[x]-py[y]));
}
int n;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n;
	rep(i,n)
	{
		cin>>px[i]>>py[i];
		par[i]=i;
		sx[i]={px[i],i};
		sy[i]={py[i],i};
	}
	sort(sx,sx+n);
	sort(sy,sy+n);
	set <pair <int,pair <int,int> > > st;
	for (int j=0;j<n-1;++j)
	{
		st.insert({dist(sx[j].second,sx[j+1].second),{sx[j].second,sx[j+1].second}});
		st.insert({dist(sy[j].second,sy[j+1].second),{sy[j].second,sy[j+1].second}});
	}
	long long ans=0;
	while (!st.empty())
	{
		auto cur=*st.begin();
		st.erase(cur);
		int u=cur.second.first,v=cur.second.second;
		ans+=(long long)union_(u,v)*dist(u,v);
	}
	cout<<ans<<endl;
	return 0;
}