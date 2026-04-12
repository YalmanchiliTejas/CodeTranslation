#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

const int INF=0x3f3f3f3f;
const int N=200005;

struct edge {int x,y,next;} e[N*2];

int f[N],g[N],ls[N],edCnt;

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void add_edge(int x,int y) {
	e[++edCnt]=(edge) {x,y,ls[x]}; ls[x]=edCnt;
	e[++edCnt]=(edge) {y,x,ls[y]}; ls[y]=edCnt;
}

void dfs(int x,int fa) {
	int rec=-INF,flag=0,wjp=0;
	for (int i=ls[x];i;i=e[i].next) {
		if (e[i].y==fa) continue;
		dfs(e[i].y,x); wjp=1;
		int mx=std:: max(g[e[i].y],f[e[i].y]);
		g[x]+=mx; f[x]+=mx;
		if (mx==g[e[i].y]) flag=1;
		rec=std:: max(rec,g[e[i].y]-f[e[i].y]);
	}
	if (wjp&&!flag||rec+1>0) f[x]+=rec+1;
}

int main(void) {
	int n=read();
	rep(i,2,n) add_edge(read(),read());
	dfs(1,0);
	if (std:: max(f[1],g[1])*2==n) puts("Second");
	else puts("First");
	return 0;
}
