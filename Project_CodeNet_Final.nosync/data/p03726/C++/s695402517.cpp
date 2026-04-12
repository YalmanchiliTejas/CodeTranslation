#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,head[MN+5],cnt=0,b[MN+5],ans=1;
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa) dfs(e[i].to,x);
	if(!b[x])
	{
		if(fa&&!b[fa]) b[fa]=b[x]=1;
		else ans=0;	
	}
}
int main()
{
	n=read();
	for(int i=1;i<n;++i) ins(read(),read());
	dfs(1,0);
	puts(ans?"Second":"First"); 
	return 0;
}

