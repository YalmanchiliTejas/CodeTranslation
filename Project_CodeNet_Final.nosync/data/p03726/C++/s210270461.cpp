#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch=getchar();int x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
void write(int aa)
{
	if(aa<0) putchar('-'),aa=-aa;
	if(aa>9) write(aa/10);
	putchar('0'+aa%10);
	return;
}
int n;
int vis[100005];
int tot,head[100005],nx[200005],to[200005];
void jia(int aa,int bb)
{
	tot++;
	nx[tot]=head[aa];
	to[tot]=bb;
	head[aa]=tot;
	return;
}
void dfs(int rt,int fa)
{
	for(int i=head[rt];i;i=nx[i])
	{
		int yy=to[i];
		if(yy==fa) continue;
		dfs(yy,rt);
		if(!vis[yy]&&!vis[rt]) vis[yy]=1,vis[rt]=1;
	}
	return;
}
int main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int x=read(),y=read();
		jia(x,y);jia(y,x);
	}
	dfs(1,1);
	for(int i=1;i<=n;++i) if(!vis[i]) {puts("First");return 0;}
	puts("Second");
	return 0;
}