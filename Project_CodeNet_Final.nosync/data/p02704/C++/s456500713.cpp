#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n;
ull col[510],row[510],ans[510][510];
bool cc[510],rr[510];
namespace MaxFlow{
	const int N=1010,M=2000000;
	int head[N],cur[N],dep[N],cnt,S,T,res,deg[N],sum,s,t;
	struct node{
		int to,next,val;
	}edge[M];
	void ae(int u,int v,int l,int r){
//		printf("%d %d %d %d\n",u,v,l,r);
		deg[v]+=l,deg[u]-=l;
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=r-l,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	inline bool bfs(){
		memset(dep,0,sizeof(dep)),q.push(S),dep[S]=1;
		while(!q.empty()){
			register int x=q.front();q.pop();
			for(register int i=cur[x]=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
		}
		return dep[T]>0;
	}
	bool reach;
	inline int dfs(int x,int flow){
		if(x==T){
			res+=flow;
			reach=true;
			return flow;
		}
		int used=0;
		for(register int &i=cur[x];i!=-1;i=edge[i].next){
			if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
			register int ff=dfs(edge[i].to,min(edge[i].val,flow-used));
			if(ff){
				edge[i].val-=ff;
				edge[i^1].val+=ff;
				used+=ff;
				if(used==flow)break;
			}
		}
		return used;
	}
	inline void Dinic(){
		while(bfs()){
			reach=true;
			while(reach)reach=false,dfs(S,0x3f3f3f3f);
		}
	}
}
using namespace MaxFlow;
void func(int ip){
	memset(head,-1,sizeof(head)),cnt=res=sum=0,memset(deg,0,sizeof(deg));
	for(int i=1;i<=n;i++){
		if(!cc[i]){
			if(col[i]&(1ull<<ip))ae(s,i,n,n);
			else ae(s,i,0,n-1);
		}else{
			if(col[i]&(1ull<<ip))ae(s,i,1,n);
			else ae(s,i,0,0);
		}
	}
	for(int i=1;i<=n;i++){
		if(!rr[i]){
			if(row[i]&(1ull<<ip))ae(i+n,t,n,n);
			else ae(i+n,t,0,n-1);
		}else{
			if(row[i]&(1ull<<ip))ae(i+n,t,1,n);
			else ae(i+n,t,0,0);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ae(i,j+n,0,1);
	ae(t,s,0,0x3f3f3f3f);
//	for(int i=1;i<=t;i++)printf("%d ",deg[i]);puts("");
	for(int i=1;i<=t;i++){
		if(deg[i]>0)ae(S,i,0,deg[i]),sum+=deg[i];
		if(deg[i]<0)ae(i,T,0,-deg[i]);
	}
	Dinic();
	if(sum!=res){puts("-1");exit(0);}
	for(int i=1;i<=n;i++)for(int j=head[i];j!=-1;j=edge[j].next){
		if(!(edge[j].to>n&&edge[j].to<=2*n))continue;
		if(!edge[j].val)ans[i][edge[j].to-n]|=1ull<<ip;
	}
}
int main(){
	scanf("%d",&n),s=2*n+1,t=2*n+2,S=2*n+3,T=2*n+4;
	for(int i=1;i<=n;i++)scanf("%d",&cc[i]);
	for(int i=1;i<=n;i++)scanf("%d",&rr[i]);
	for(int i=1;i<=n;i++)scanf("%llu",&col[i]);
	for(int i=1;i<=n;i++)scanf("%llu",&row[i]);
	for(int i=0;i<64;i++)func(i);
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%llu ",ans[i][j]);puts("");}
	return 0;
}
/*
3
1 1 0
0 0 1
23 3 1
0 0 23 
*/ 