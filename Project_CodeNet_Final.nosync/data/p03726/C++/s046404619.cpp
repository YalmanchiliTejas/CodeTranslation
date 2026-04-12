//Love and Freedom.
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#define inf 20021225
#define ll long long
#define N 100010
using namespace std;
int read()
{
	int f=1,s=0; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9')	s=s*10+ch-'0',ch=getchar();
	return f*s;
}
struct edge{int to,lt;}e[N<<1];
int in[N],cnt,leaf[N],del[N],d[N];
void add(int x,int y)
{
	e[++cnt].to=y; e[cnt].lt=in[x]; in[x]=cnt; d[x]++; if(d[x]>1)	leaf[x]=0;
	e[++cnt].to=x; e[cnt].lt=in[y]; in[y]=cnt; d[y]++; if(d[y]>1)	leaf[y]=0;
}
int win;
void dfs(int x,int fr)
{
	if(win)	return; int lf=0,all=0,de=0;
	for(int i=in[x];i;i=e[i].lt)
	{
		int y=e[i].to; if(y==fr)	continue;
		dfs(y,x); all++; lf+=leaf[y]; de+=del[y];
		if(win)	return;
	}
	if(lf>=2)	win=1;
	if(lf==1)	del[x]=1;
	else	leaf[x]=1;
}
int rt;
int main()
{
	int n=read();
	for(int i=1;i<n;i++)	add(read(),read());
	if(n==2)	return puts("Second"),0;
	for(int i=1;i<=n;i++)	rt=d[i]>=2?i:rt;
	dfs(rt,0); puts(win?"First":"Second");
	return 0;
}