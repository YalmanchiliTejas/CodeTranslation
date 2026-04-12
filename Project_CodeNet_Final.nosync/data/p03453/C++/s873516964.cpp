#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define fi first
#define se second

typedef long long LL;
typedef std:: pair <LL,int> pair;
const LL INF=1e15;
const int MOD=1000000007;
const int N=200005;
const int E=500005;

struct edge {int x,y; LL w; int next;} e[E];

LL cnt[2][N],dis[2][N];
int ls[N],edCnt,n;

bool vis[N];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void add_edge(int x,int y,LL w) {
	e[++edCnt]=(edge) {x,y,w,ls[x]}; ls[x]=edCnt;
	e[++edCnt]=(edge) {y,x,w,ls[y]}; ls[y]=edCnt;
}

void dijk(int st,int ed,LL *dis,LL *cnt) {
	rep(i,0,n) dis[i]=INF; dis[st]=0;
	rep(i,0,n) cnt[i]=0; cnt[st]=1;
	rep(i,0,n) vis[i]=0;
	std:: priority_queue <pair> heap;
	for (heap.push(pair(0,st));!heap.empty();) {
		pair top=heap.top(); heap.pop();
		int x=top.se;
		if (vis[x]) continue; vis[x]=1;
		for (int i=ls[x];i;i=e[i].next) {
			if (dis[x]+e[i].w<dis[e[i].y]) {
				dis[e[i].y]=dis[x]+e[i].w;
				heap.push(pair(-dis[e[i].y],e[i].y));
				cnt[e[i].y]=cnt[x];
			} else if (dis[x]+e[i].w==dis[e[i].y]) {
				cnt[e[i].y]+=cnt[x]; cnt[e[i].y]%=MOD;
			}
		}
	}
}

int main(void) {
	n=read(); int m=read();
	int st=read(),ed=read();
	rep(i,1,m) {
		int x=read(),y=read(),w=read();
		add_edge(x,y,w);
	}
	dijk(st,ed,dis[0],cnt[0]);
	dijk(ed,st,dis[1],cnt[1]);
	LL len=dis[0][ed];
	LL ans=cnt[0][ed]*(cnt[0][ed]-1)%MOD;
	rep(i,1,n) if (dis[0][i]==dis[1][i]&&dis[0][i]*2==len) {
		LL tmp=cnt[0][i]*cnt[1][i]%MOD;
		ans=(ans+MOD-tmp*(tmp-1)%MOD)%MOD;
	}
	for (int i=1;i<edCnt;i+=2) {
		int x=e[i].x,y=e[i].y; LL w=e[i].w;
		if (dis[0][x]>dis[0][y]) std:: swap(x,y);
		if (dis[0][x]+w+dis[1][y]==len&&dis[0][x]*2<len&&dis[1][y]*2<len) {
			LL tmp=cnt[0][x]*cnt[1][y]%MOD;
			ans=(ans+MOD-tmp*(tmp-1)%MOD)%MOD;
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	printf("%lld\n", ans);
	return 0;
}