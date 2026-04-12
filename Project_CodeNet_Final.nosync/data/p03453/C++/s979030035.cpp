#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
#define pa pair<ll,int>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
priority_queue<pa,vector<pa>,greater<pa> >q;
int n,m,S,T,head[MN+5],f[MN+5],F[MN+5],cnt,in[MN+5],Q[MN+5],top,ans;
ll d[MN+5],D[MN+5];
struct edge{int to,next,w;}e[MN*4+5];
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;	
}
void Dij(int from,ll*d)
{
	memset(d,40,sizeof(D));q.push(make_pair(d[from]=0,from));	
	while(!q.empty())
	{
		while(!q.empty()&&d[q.top().second]!=q.top().first) q.pop();
		if(q.empty()) break;
		int x=q.top().second;q.pop();
		for(int i=head[x];i;i=e[i].next)
			if(d[x]+e[i].w<d[e[i].to]) q.push(make_pair(d[e[i].to]=d[x]+e[i].w,e[i].to));	
	}
}
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int main()
{
	n=read();m=read();S=read();T=read();
	for(int i=1,j,k;i<=m;++i) j=read(),k=read(),ins(j,k,read());
	Dij(S,d);Dij(T,D);
	for(int i=1;i<=n;++i) for(int j=head[i];j;j=e[j].next) if(d[i]+e[j].w==d[e[j].to]) ++in[e[j].to];
	Q[top=1]=S;f[S]=1;
	for(int i=1;i<=top;++i)
		for(int j=head[Q[i]];j;j=e[j].next)
			if(d[Q[i]]+e[j].w==d[e[j].to]&&(R(f[e[j].to],f[Q[i]]),!--in[e[j].to]))
				Q[++top]=e[j].to;
	for(int i=1;i<=n;++i) for(int j=head[i];j;j=e[j].next) if(D[i]+e[j].w==D[e[j].to]) ++in[e[j].to];
	Q[top=1]=T;F[T]=1;
	for(int i=1;i<=top;++i)
		for(int j=head[Q[i]];j;j=e[j].next)
			if(D[Q[i]]+e[j].w==D[e[j].to]&&(R(F[e[j].to],F[Q[i]]),!--in[e[j].to]))
				Q[++top]=e[j].to;
	ans=1LL*f[T]*f[T]%mod;
	for(int i=1;i<=n;++i) if(d[i]+D[i]==d[T])
	{
		if(d[i]*2==d[T]) ans=(ans-1LL*f[i]*F[i]%mod*f[i]%mod*F[i]%mod+mod)%mod;
		for(int j=head[i];j;j=e[j].next) if(d[i]+e[j].w==d[e[j].to]&&d[e[j].to]+D[e[j].to]==d[T])
		{
			ll l=d[i],r=d[e[j].to];
			if(l*2<d[T]&&r*2>d[T]) ans=(ans-1LL*f[i]*F[e[j].to]%mod*f[i]%mod*F[e[j].to]%mod+mod)%mod;
		}	
	}
	cout<<ans;
	return 0;
}