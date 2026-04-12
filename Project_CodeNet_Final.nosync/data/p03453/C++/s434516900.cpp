#include<cstdio>
#include<cstring>
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define MM 200000
#define N 131072
#define MOD 1000000007
struct edge{int nx,t,w;}e[MM*2+5];
int h[MN+5],en,fs[MN+5],ft[MN+5],r[MN+5],q[MN+5],qn;ll ds[MN+5],dt[MN+5];
struct node{ll x;int f;}t[N*2+5];
inline void ins(int x,int y,int w)
{
	e[++en]=(edge){h[x],y,w};h[x]=en;
	e[++en]=(edge){h[y],x,w};h[y]=en;
}
inline node min(const node&a,const node&b){return a.x<b.x?a:b;}
void change(int k,ll x){for(t[k+=N].x=x;k>>=1;)t[k]=min(t[k<<1],t[k<<1|1]);}
void dj(int s,ll*d,int*f)
{
	memset(d,40,sizeof(ll)*(MN+5));memset(t,40,sizeof(t));
	int i,j,x;
	for(i=1;i<=MN;++i)t[i+N].f=i;
	for(change(s,d[s]=0);t[1].x<t[0].x;)
	{
		x=t[1].f;change(x,t[0].x);
		for(i=h[x];i;i=e[i].nx)if(d[x]+e[i].w<d[e[i].t])
			change(e[i].t,d[e[i].t]=d[x]+e[i].w);
	}
	for(i=1;i<=MN;++i)for(j=h[i];j;j=e[j].nx)if(d[i]+e[j].w==d[e[j].t])++r[e[j].t];
	for(f[q[i=qn=0]=s]=1;i<=qn;++i)for(j=h[x=q[i]];j;j=e[j].nx)if(d[x]+e[j].w==d[e[j].t])
	{
		f[e[j].t]=(f[e[j].t]+f[x])%MOD;
		if(!--r[e[j].t])q[++qn]=e[j].t;
	}
}
int main()
{
	int n,m,s,t,i,j,x,y,ans;
	n=read();m=read();s=read();t=read();
	while(m--)x=read(),y=read(),ins(x,y,read());
	dj(s,ds,fs);dj(t,dt,ft);
	for(ans=1LL*fs[t]*ft[s]%MOD,i=1;i<=n;++i)
		if(ds[i]==dt[i])ans=(ans+MOD-1LL*fs[i]*fs[i]%MOD*ft[i]%MOD*ft[i]%MOD)%MOD;
		else if(ds[i]<dt[i])for(j=h[i];j;j=e[j].nx)if(ds[i]+e[j].w+dt[e[j].t]==ds[t]&&ds[e[j].t]>dt[e[j].t])
			ans=(ans+MOD-1LL*fs[i]*fs[i]%MOD*ft[e[j].t]%MOD*ft[e[j].t]%MOD)%MOD;
	printf("%d",ans);
}