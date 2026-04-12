    #include <iostream>
    #include <string>
    #include <set>  
    #include <algorithm>
    #include <vector>
    #include <cmath>
    #include <queue>
    #include <deque>
    #include <cstring>
    #include <cstdio>
    #include <map>
    #include <numeric>
    #include <cassert>
    #include <iomanip>
    #include <sstream>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,N) FOR(i,0,N)
#define FORD(i,b,a) for(int i=(int)(b)-1;i>=a;--i)
typedef long long LL;
typedef pair<int,int> PII;
const int INF=1e9+7;
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
#define dprintf(...) printf(__VA_ARGS__)
const int maxn=1e5+10;
int N;
int cnt=0;
struct Town
{
	int x;
	int y;
	int id;
}t[maxn],tt[maxn];
int fa[maxn];
int geT(int x)
{
	return fa[x]==x?fa[x]:fa[x]=geT(fa[x]);
}
map<pair<int,int>,bool> mp;
bool less2(Town a,Town b)
{
	return a.x>b.x;
}
bool less3(Town a,Town b)
{
	return a.y>b.y;
}
struct edge
{
	int u,v,cst;
}es[2*maxn];
bool less4(edge a,edge b)
{
	return a.cst<b.cst;
}
int main()
{
	scanf("%d",&N);
	REP(i,N)
	{
		int xx,yy;
		scanf("%d %d",&xx,&yy);
		if(!mp[make_pair(xx,yy)])
		{
			mp[make_pair(xx,yy)]=1;
			t[cnt].x=xx,t[cnt].y=yy,t[cnt].id=cnt;
			tt[cnt].x=xx,tt[cnt].y=yy,tt[cnt].id=cnt;
			cnt++;
		}
	}
	sort(t,t+cnt,less2);
	sort(tt,tt+cnt,less3);
//	cout<<cnt<<endl;
	REP(i,cnt-1)
	{
		es[i*2].u=t[i].id,es[i*2].v=t[i+1].id,es[i*2].cst=abs(t[i].x-t[i+1].x);
		es[i*2+1].u=tt[i].id,es[i*2+1].v=tt[i+1].id,es[i*2+1].cst=abs(tt[i].y-tt[i+1].y);
	}
	sort(es,es+2*(cnt-1),less4);
//	REP(i,2*(cnt-1))
//	{
//		cout<<es[i].u<<" "<<es[i].v<<" "<<es[i].cst<<endl;
//	}
//	system("pause");
	REP(i,cnt)fa[i]=i;
	long long ans=0;
	REP(i,2*(cnt-1))
	{
		int fr=es[i].u,to=es[i].v,c=es[i].cst;
		int ru=geT(fr),rv=geT(to);
		if(ru==rv)continue;
		fa[ru]=rv;
	//	cout<<fr<<" "<<to<<endl;
	//	cout<<ans<<" "<<c<<endl;
	//	system("pause");
		ans+=c; 
	}
	printf("%lld\n",ans);
	return 0;
}