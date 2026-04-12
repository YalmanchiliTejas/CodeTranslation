#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define N 400011
#define MAX 1000000007
#define int long long
using namespace std;
struct point{
	int x,y,z;
}ee[N];
struct node{
	int no,data;
	bool operator<(const node &other)const{
		return data>other.data;
	}
}temp;
priority_queue<node> pq;
struct apple{
	int v,nxt,q;
}edge[N*4];
int indexx[N],tot,n,m,vist[N],dist[N],dis[2][N],sum[2][N],ans,que[N];
int S,T,Ans,d[N];
void addedge(int x,int y,int z){
	edge[++tot].v=y;
	edge[tot].q=z;
	edge[tot].nxt=indexx[x];
	indexx[x]=tot;
}
void dij(int st){
	memset(dist,0x3f,sizeof(dist));
	memset(vist,0,sizeof(vist));
	temp.no=st;
	temp.data=0;
	dist[st]=0;
	pq.push(temp);
	while(!pq.empty()){
		temp=pq.top();pq.pop();
		int x=temp.no;
		if(vist[x]) continue;
		vist[x]=1;
		int t=indexx[x],vv,qq;
		while(t){
			vv=edge[t].v;
			qq=edge[t].q;
			if(dist[vv]>dist[x]+qq){
				dist[vv]=dist[x]+qq;
				temp.no=vv,temp.data=dist[vv];
				pq.push(temp);
			}
			t=edge[t].nxt;
		}
	}
}
void bfs(int st,int k){
	int head=0,tail=0;
	que[++tail]=st;
	sum[k][st]=1; 
	while(head<tail){
		int x=que[++head];
		int t=indexx[x],vv;
		while(t){
			vv=edge[t].v;
			d[vv]--;
			sum[k][vv]=(sum[k][vv]+sum[k][x])%MAX;
			if(!d[vv]){
				que[++tail]=vv;
			}
			t=edge[t].nxt;
		}
	}
}
signed main(){
	int x,y,z;
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld",&S,&T);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		ee[i].x=x;
		ee[i].y=y;
		ee[i].z=z;
		addedge(x,y,z);
		addedge(y,x,z);
	}
	dij(S);Ans=dist[T];
	for(int i=1;i<=n;i++) dis[0][i]=dist[i];
	memset(indexx,0,sizeof(indexx));tot=0;
	for(int i=1;i<=m;i++){
		if(dist[ee[i].x]>dist[ee[i].y]) swap(ee[i].x,ee[i].y);
		if(dist[ee[i].x]+ee[i].z==dist[ee[i].y]){
			addedge(ee[i].x,ee[i].y,1);
			d[ee[i].y]++;
		}
	}
	bfs(S,0);
	memset(d,0,sizeof(d));
	memset(indexx,0,sizeof(indexx));tot=0;
	for(int i=1;i<=m;i++){
		addedge(ee[i].x,ee[i].y,ee[i].z);
		addedge(ee[i].y,ee[i].x,ee[i].z);
	}
	dij(T);
	for(int i=1;i<=n;i++) dis[1][i]=dist[i];
	memset(indexx,0,sizeof(indexx));tot=0;
	for(int i=1;i<=m;i++){
		if(dist[ee[i].x]>dist[ee[i].y]) swap(ee[i].x,ee[i].y);
		if(dist[ee[i].x]+ee[i].z==dist[ee[i].y]){
			addedge(ee[i].x,ee[i].y,1);
			d[ee[i].y]++;
		}
	}
	bfs(T,1);
	ans=sum[0][T]*sum[0][T]%MAX;
	for(int i=1;i<=m;i++){
		x=ee[i].x,y=ee[i].y,z=ee[i].z;
		if(dis[0][x]>dis[0][y]) swap(x,y);
		if(dis[0][x]+dis[1][y]+z==Ans){
			int t=sum[0][x]*sum[1][y]%MAX;
			if(abs(dis[0][x]-dis[1][y])<z){
				ans=(ans-t*t%MAX+MAX)%MAX;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[0][i]==dis[1][i] && dis[0][i]+dis[1][i]==Ans){
			int t=sum[0][i]*sum[1][i]%MAX;
			ans=(ans-t*t%MAX)%MAX;
		}
	}
	ans=(ans%MAX+MAX)%MAX;
	printf("%lld",ans);
	return 0;
} 