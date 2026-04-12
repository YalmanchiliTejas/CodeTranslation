#include<cstdio>
#include<algorithm>
#define N 100010

using namespace std;

typedef long long LL;
struct dot{int x,y,i;}d[N];
struct edge{int x,y,v;}e[N+N];
int f[N],n,cnt;
LL ans;

bool cmp(dot a,dot b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

bool cmp2(dot a,dot b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}

bool cmp3(edge a,edge b){return a.v<b.v;}

int find(int x){return x==f[x]?x:f[x]=find(f[x]);}

int main(){
	int i,t,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&d[i].x,&d[i].y);
	sort(d+1,d+n+1,cmp);

	t=n;
	for(i=2,n=1;i<=t;i++)
	if(d[i].x!=d[n].x || d[i].y!=d[n].y) d[++n]=d[i];
	
	for(i=2;i<=n;i++){
		e[++cnt].x=i; e[cnt].y=i-1; e[cnt].v=d[i].x-d[i-1].x;
	}
	for(i=1;i<=n;i++) d[i].i=i;
	//for(i=1;i<=cnt;i++) printf("%d %d %d\n",e[i].x,e[i].y,e[i].v);
	
	sort(d+1,d+n+1,cmp2);
	for(i=2;i<=n;i++){
		e[++cnt].x=d[i].i; e[cnt].y=d[i-1].i; e[cnt].v=d[i].y-d[i-1].y;
	}
	
	for(i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+cnt+1,cmp3);
	for(i=1;i<=cnt;i++){
		a=find(e[i].x); b=find(e[i].y);
		if(a==b) continue;
		f[a]=b; ans+=(LL)e[i].v;
	}
	printf("%lld\n",ans);
	return 0;
} 