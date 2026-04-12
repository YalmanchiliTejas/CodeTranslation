#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,f[MN+5],o;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x,int fa)
{
	f[x]=1;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
	{
		dfs(e[i].t,x);
		if(f[e[i].t])f[x]?f[x]=0:o=1;
	}
}
int main()
{
	int n=read(),i;
	for(i=1;i<n;++i)ins(read(),read());
	dfs(1,0);
	puts(f[1]||o?"First":"Second");
}