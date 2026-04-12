#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,K,h[1001010],m1,g[1001010],f[1001010];
int siz[1001010],ans;
struct edge{
	int next,to;
	edge(int next=0,int to=0):
	next(next),to(to){}
}q[2020200];
void Addedge(){
	int x,y; scanf("%d %d",&x,&y);
	q[++m1]=edge(h[x],y); h[x]=m1;
	q[++m1]=edge(h[y],x); h[y]=m1;
}
void Dfs1(int x,int fa){
	siz[x]=1;
	for (int i=h[x];i;i=q[i].next){
		int y=q[i].to;
		if (y==fa) continue;
		Dfs1(y,x); siz[x]+=siz[y];
	}
}
void Dfs2(int x,int fa){
	int Max1=-21001010,Max2=-21001010;
	for (int i=h[x];i;i=q[i].next){
		int y=q[i].to;
		if (y==fa) continue;
		Dfs2(y,x);
		if (siz[y]>=K) f[x]++;
		if (f[y]-g[y]>Max1) Max2=Max1,Max1=f[y]-g[y];
		else if (f[y]-g[y]>Max2) Max2=f[y]-g[y];
	}
	
	if (siz[x]>=K) g[x]=1;
	ans=max(ans,f[x]+Max1+(n-siz[x]>=K)); 
	ans=max(ans,f[x]+Max1+Max2+(n-siz[x]>=K));
	f[x]=max(f[x],f[x]+Max1);
}
int main(){
	scanf("%d %d",&n,&K);
	for (int i=1;i<n;i++) Addedge();
	Dfs1(1,0); Dfs2(1,0);
	cout<<ans<<endl;
}
