#include<queue>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
#define  For(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define rFor(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
using namespace std;
typedef long long LL;
const int N=100010;
const int M=500010;
template<typename T>inline T chkmax(T _A,T _B){return _A>_B?_A:_B;}
template<typename T>inline T chkmin(T _A,T _B){return _A<_B?_A:_B;}
template<typename T>void read(T&x)
{
    x=0;int _f(0);char ch=getchar();
    while(!isdigit(ch))_f|=(ch=='-'),ch=getchar();
    while( isdigit(ch))x=x*10+ch-'0',ch=getchar();
    x=_f?-x:x;
}
inline void file()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
struct node
{
	int x,y,id;
	node(){}
	node(int A,int B,int C):x(A),y(B),id(C){}
}a[N];
bool cmpx(node A,node B){return A.x<B.x;}
bool cmpy(node A,node B){return A.y<B.y;}
int n,cnt,fa[N];
struct edge
{
	int u,v,w;
	edge(){}
	edge(int A,int B,int C):u(A),v(B),w(C){}
}e[M];
bool operator<(edge A,edge B){return A.w<B.w;}
inline void add_edge(int u,int v,int w){e[++cnt]=edge(u,v,w);}
inline LL Get_dis(node A,node B){return min(abs(A.x-B.x),abs(A.y-B.y));}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void Kruskal()
{
	LL ans=0;
	sort(e+1,e+cnt+1);
	For(i,1,n)fa[i]=i;
	For(i,1,cnt)
	{
		int u=e[i].u,v=e[i].v;
		LL w=e[i].w;
		if((u=find(u))!=(v=find(v)))
			ans+=w,fa[u]=v;
	}
	printf("%lld\n",ans);
}
int main()
{
	int x,y;
	read(n);
	For(i,1,n)
	{
		read(x),read(y);
		a[i]=node(x,y,i);
	}
	sort(a+1,a+n+1,cmpx);
	For(i,2,n)add_edge(a[i].id,a[i-1].id,Get_dis(a[i],a[i-1]));
	sort(a+1,a+n+1,cmpy);
	For(i,2,n)add_edge(a[i].id,a[i-1].id,Get_dis(a[i],a[i-1]));
	Kruskal();
	return 0;
}
