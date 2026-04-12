#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
template<typename TP>inline void read(TP &tar)
{
	TP ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){ret=ret*10+(ch-'0');ch=getchar();}
	tar=ret*f;
}
template<typename TP,typename... Args>inline void read(TP& t,Args&... args){read(t),read(args...);}
namespace RKK
{
const int N=100011,M=200011;
const int mo=1000000007;
void doadd(int &a,const int &b){if((a+=b)>=mo) a-=mo;}
int add(const int &a,const int &b){return a+b>=mo?a+b-mo:a+b;}
void domul(int &a,const int &b){a=(lint)a*b%mo;}
int mul(const int &a,const int &b){return (lint)a*b%mo;}
struct sumireko{int to,ne,w;}e[M<<1];int he[N],ecnt;
void addline(int f,int t,int w){e[++ecnt].to=t,e[ecnt].w=w;e[ecnt].ne=he[f],he[f]=ecnt;}
int n,m,S,T;
int ex[M],ey[M],ew[M];
lint dis1[N],dis2[N];
int f1[N],f2[N];
struct pat{int x;lint d;pat(int x=0,lint d=0):x(x),d(d){}bool operator<(const pat &p)const{return d>p.d;}};
void dijkstra(int s,lint dis[],int f[])
{
	memset(dis,0x3f,sizeof(lint[N]));
	priority_queue<pat> q;q.push(pat(s,dis[s]=0)),f[s]=1;
	pat pt;int x;
	while(!q.empty())
	{
		pt=q.top(),q.pop(),x=pt.x;if(pt.d!=dis[x]) continue;
		for(int i=he[x],t=e[i].to;i;i=e[i].ne,t=e[i].to)
			if(dis[t]==dis[x]+e[i].w) doadd(f[t],f[x]);
			else if(dis[t]>dis[x]+e[i].w) f[t]=f[x],dis[t]=dis[x]+e[i].w,q.push(pat(t,dis[t]));
	}
}
int ans;
int main()
{
	#ifdef RDEBUG
	freopen("sample.in","r",stdin);
	#endif
	read(n,m,S,T);for(int i=1;i<=m;i++) read(ex[i],ey[i],ew[i]),addline(ex[i],ey[i],ew[i]),addline(ey[i],ex[i],ew[i]);
	dijkstra(S,dis1,f1),dijkstra(T,dis2,f2);
	ans=mul(f1[T],f1[T]);
	// for(int i=1;i<=n;i++) cerr<<f1[i]<<" ";cerr<<endl;
	// for(int i=1;i<=n;i++) cerr<<f2[i]<<" ";cerr<<endl;
	for(int i=1;i<=n;i++)if(dis1[i]+dis2[i]==dis1[T]&&dis1[i]==dis2[i])
		doadd(ans,mo-mul(mul(f1[i],f1[i]),mul(f2[i],f2[i])));
	for(int i=1;i<=m;i++)
	{
		if(dis1[ex[i]]+ew[i]+dis2[ey[i]]==dis1[T]&&dis1[ex[i]]+ew[i]>dis2[ey[i]]&&dis2[ey[i]]+ew[i]>dis1[ex[i]])
			doadd(ans,mo-mul(mul(f1[ex[i]],f2[ey[i]]),mul(f1[ex[i]],f2[ey[i]])));
		swap(ex[i],ey[i]);
		if(dis1[ex[i]]+ew[i]+dis2[ey[i]]==dis1[T]&&dis1[ex[i]]+ew[i]>dis2[ey[i]]&&dis2[ey[i]]+ew[i]>dis1[ex[i]])
			doadd(ans,mo-mul(mul(f1[ex[i]],f2[ey[i]]),mul(f1[ex[i]],f2[ey[i]])));
	}
	printf("%d\n",ans);
	return 0;
}
}
int main(){return RKK::main();}