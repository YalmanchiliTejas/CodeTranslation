#include<bits/stdc++.h>
using namespace std;
#define il inline
#define gc getchar()
#define mp make_pair
#define int long long
#define P pair<int,int>
#define ri register int
#define rb register bool
#define rc register char
#define t(i) edge[i].to
#define w(i) edge[i].wei
#define rp(i,x,y) for(ri i=x;i<=y;++i)
#define my(i,x,y) for(ri i=x;i>=y;--i)
#define e(i,x) for(ri i=head[x];i;i=edge[i].nxt)

const int N=100000+10,M=200000+10,mod=1e9+7;
int n,m,head[N],ed_cnt,dis1[N],g1[N],dis2[N],g2[N],as,S,T;
bool vis[N];
struct ed{int to,nxt,wei;}edge[M<<1];
struct edg{int fr,to,wei;}e[M];

il int read()
{
	rc ch=gc;ri x=0;rb y=1;
	while(ch!='-' && (ch<'0' || ch>'9'))ch=gc;
	if(ch=='-')ch=gc,y=0;
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=gc;
	return y?x:-x;
}
il int abss(ri x){return x>0?x:-x;}
il void ad(ri x,ri y,ri z){edge[++ed_cnt]=(ed){x,head[y],z};head[y]=ed_cnt;}
il void dij1()
{
	priority_queue< P,vector<P>,greater<P> >Q;Q.push(mp(0,S));
	memset(dis1,63,sizeof(dis1));dis1[S]=0;g1[S]=1;memset(vis,0,sizeof(vis));
	while(!Q.empty())
	{
		ri nw=Q.top().second;Q.pop();if(vis[nw])continue;vis[nw]=1;
		e(i,nw)
		{
			if(dis1[nw]+w(i)==dis1[t(i)])(g1[t(i)]+=g1[nw])%=mod;
			if(dis1[nw]+w(i)<dis1[t(i)])dis1[t(i)]=dis1[nw]+w(i),g1[t(i)]=g1[nw],Q.push(mp(dis1[t(i)],t(i)));
		}
	}
}
il void dij2()
{
	priority_queue< P,vector<P>,greater<P> >Q;Q.push(mp(0,T));
	memset(dis2,63,sizeof(dis2));dis2[T]=0;g2[T]=1;memset(vis,0,sizeof(vis));
	while(!Q.empty())
	{
		ri nw=Q.top().second;Q.pop();if(vis[nw])continue;vis[nw]=1;
		e(i,nw)
		{
			if(dis2[nw]+w(i)==dis2[t(i)])(g2[t(i)]+=g2[nw])%=mod;
			if(dis2[nw]+w(i)<dis2[t(i)])dis2[t(i)]=dis2[nw]+w(i),g2[t(i)]=g2[nw],Q.push(mp(dis2[t(i)],t(i)));
		}
	}
}

signed main()
{
	//freopen("3883.in","r",stdin);freopen("3883.out","w",stdout);
	n=read();m=read();S=read();T=read();
	rp(i,1,m){ri x=read(),y=read(),z=read();ad(x,y,z);ad(y,x,z);e[i]=(edg){x,y,z};}
	dij1();dij2();as=1ll*g1[T]*g1[T]%mod;
	rp(i,1,n)
		if(dis1[i]+dis2[i]==dis1[T] && dis1[i]==dis2[i])as=(as-1ll*g1[i]*g1[i]%mod*g2[i]%mod*g2[i]%mod+mod)%mod;
	rp(i,1,m)
	{
		if(dis1[e[i].fr]+dis2[e[i].to]+e[i].wei==dis1[T] && abss(dis1[e[i].fr]-dis2[e[i].to])<e[i].wei)
			as=(as-1ll*g1[e[i].fr]*g1[e[i].fr]%mod*g2[e[i].to]%mod*g2[e[i].to]%mod+mod)%mod;
		swap(e[i].fr,e[i].to);
		if(dis1[e[i].fr]+dis2[e[i].to]+e[i].wei==dis1[T] && abss(dis1[e[i].fr]-dis2[e[i].to])<e[i].wei)
			as=(as-1ll*g1[e[i].fr]*g1[e[i].fr]%mod*g2[e[i].to]%mod*g2[e[i].to]%mod+mod)%mod;
	}
	printf("%lld\n",as);
	return 0;
}
