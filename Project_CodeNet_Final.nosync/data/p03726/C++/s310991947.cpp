#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,ind[M],fs[M],nt[M],to[M],u,v,tmp,rt,vis[M];
void WIN(){puts("First");exit(0);}
void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
void DP(int x,int last){
	int cnt=0,all=(last==0?0:-1),ct=0;
	for(int i=fs[x];i!=-1;i=nt[i],all++){
		if(to[i]==last) continue;
		DP(to[i],x),cnt+=(vis[to[i]]==1),ct+=(vis[to[i]]==2);
	}
	if(ct>=2) WIN();
	if(ct) vis[x]=1;
	if(cnt==all) vis[x]=2;
}
int main(){
	n=read(),memset(fs,-1,sizeof(fs));
	for(int i=1;i<n;i++){
	    u=read(),v=read();
		link(u,v),link(v,u);
		ind[u]++,ind[v]++;
	}
	DP(1,0);
	//for(int i=1;i<=n;i++) printf("X: %d    vis: %d\n",i,vis[i]);
	if(vis[1]==2) WIN();
	puts("Second");
	return 0;
}