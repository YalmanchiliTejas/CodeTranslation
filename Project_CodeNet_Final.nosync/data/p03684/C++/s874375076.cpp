#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;
#define mp(a,b) make_pair((a),(b))
bool vis[100005];
int n,dis,t,ans,g[100005];
pair<int,int> x[100005],y[100005];
pair<int,pair<int,int> > tmp;
priority_queue<pair<int,pair<int,int> > > q;
int Abs(int ooo){return ooo>=0?ooo:-ooo;}
int FIND(int ooo)
{
	if(g[ooo]==ooo)return ooo;
	else return g[ooo]=FIND(g[ooo]);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x[i].first,&y[i].first);
		x[i].second=i;
		y[i].second=i;
		g[i]=i;
	}
	sort(x,x+n);
	sort(y,y+n);
	for(int i=1;i<n;i++)
	{
		dis=x[i].first-x[i-1].first;
		q.push( mp( -dis , mp( x[i-1].second , x[i].second ) ) );
		dis=y[i].first-y[i-1].first;
		q.push( mp( -dis , mp( y[i-1].second , y[i].second ) ) );
	}
	while(!q.empty())
	{
		tmp=q.top();
		q.pop();
		if(FIND(tmp.second.first)==FIND(tmp.second.second))continue;
		ans+=-tmp.first;
		g[FIND(tmp.second.first)]=FIND(tmp.second.second);
		t++;
		if(t==n-1)break;
	}
	printf("%d",ans);
	return 0;
}