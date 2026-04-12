#include<cstdio>
#include<algorithm>
#include<cstring>
#define MN 100005
using namespace std;
int n,num,rd[MN],head[MN],bx[MN],pd[MN];bool ac;
struct edge{int to,next;}g[MN<<1];
void ins(int u,int v){g[++num].next=head[u];head[u]=num;g[num].to=v;}
void dfs(int u,int ff){
	bx[u]=0,pd[u]=1;
	for(int i=head[u];i;i=g[i].next)if(g[i].to!=ff)dfs(g[i].to,u),bx[u]|=pd[g[i].to],pd[u]&=bx[g[i].to];
}
void dfs2(int u,int ff,int fx,int fy){
	int sufx[rd[u]+2],sufy[rd[u]+2],prex[rd[u]+2],prey[rd[u]+2],now[rd[u]+2],tt=0;if(pd[u]&fx)ac=1;
	for(int i=head[u];i;i=g[i].next)if(g[i].to!=ff)now[++tt]=g[i].to;sufx[tt+1]=prex[0]=1,sufy[tt+1]=prey[0]=0;
	for(int i=1;i<=tt;i++)prex[i]=prex[i-1]&bx[now[i]],prey[i]=prey[i-1]|pd[now[i]];
	for(int i=tt;i>=1;i--)sufx[i]=sufx[i+1]&bx[now[i]],sufy[i]=sufy[i+1]|pd[now[i]];
	for(int i=1;i<=tt;i++)dfs2(now[i],u,fy|prey[i-1]|sufy[i+1],fx&prex[i-1]&sufx[i+1]);
}
int main(){
	scanf("%d",&n);int x,y;
	for(int i=1;i<n;i++)scanf("%d%d",&x,&y),ins(x,y),ins(y,x),rd[x]++,rd[y]++;dfs(1,1);dfs2(1,1,1,0);printf("%s\n",ac?"First":"Second");
}