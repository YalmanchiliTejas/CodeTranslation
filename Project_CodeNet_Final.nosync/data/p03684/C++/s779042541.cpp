#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
const int maxn=100000+5;
typedef long long ll;
struct point{int x,y,id;};
point p[maxn];
int n;
struct edge{int from,to,cost;};
vector<edge> pool;
int myabs(int x){return x<0?-x:x;}
bool cmppp(edge a,edge b){
	return a.cost<b.cost;
}
bool cmp1(point a,point b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmp2(point a,point b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
struct ge{int to,cost;};
struct cmpp{
	bool operator()(edge a,edge b){
		return a.cost>b.cost;
	}
};
vector<ge> g[maxn];
int f[maxn],rnk[maxn];
int getf(int x){
	return f[x]==x?f[x]:f[x]=getf(f[x]);
}
void merge(int u,int v)
{
	int fu=getf(u),fv=getf(v);
	if(fu==fv) return;
	else{
		if(rnk[fu]>rnk[fv]){
			rnk[fu]+=rnk[fv];rnk[fv]=0;
			f[fv]=fu;
		}else{
			rnk[fv]+=rnk[fu];rnk[fu]=0;
			f[fu]=fv;
		}
	}
}
vector<edge> egs;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {p[i].id=i;scanf("%d%d",&p[i].x,&p[i].y);}
	sort(p+1,p+1+n,cmp1);
	for(int i=1;i<n;i++){
		egs.push_back((edge){p[i].id,p[i+1].id,min(myabs(p[i].x-p[i+1].x),myabs(p[i].y-p[i+1].y))});
	}
	sort(p+1,p+1+n,cmp2);
	for(int i=1;i<n;i++){
		egs.push_back((edge){p[i].id,p[i+1].id,min(myabs(p[i].x-p[i+1].x),myabs(p[i].y-p[i+1].y))});
	}
	bool has=true;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++) rnk[i]=1;
	ll ans=0;
	sort(egs.begin(),egs.end(),cmppp);
	int lev=n-1;
	for(int i=0;i<egs.size();i++)
	{
		edge now=egs[i];
		if(getf(now.from)!=getf(now.to))
		{lev--;merge(now.from,now.to);ans+=now.cost;}
		if(lev==0) break;
	}
	printf("%lld\n",ans);
	return 0;
}
