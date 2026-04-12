#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int N=200005;
const int P=1000000007;
const long long INFll=0x3f3f3f3f3f3f3f3fll;

struct edge{
	int v,len;
	edge *next;
}pool[5*N],*h[N];

int n,m,top=-1;
int S,T;
int _u[N],_v[N],_len[N];
int Inqwq[N],id[N],oscar;
long long dis[2][N];
long long cnt[2][N]; //0:S 1:T
long long ans;
queue <int> Q;

inline void addedge(int u,int v,int len){
	edge *tmp=&pool[++top];
	tmp->v=v;tmp->len=len;tmp->next=h[u];h[u]=tmp;
}

inline bool cmp(int x,int y){
	return dis[oscar][x]<dis[oscar][y];
}

#define upd(x,y) x+=(y),x%=P

#define sq(x) (((x)*(x))%P)

inline void spfa(int U,int type){
	oscar=type;
	for(int i=1;i<=n;i++) id[i]=i;
	for(int i=1;i<=n;i++) dis[type][i]=INFll,Inqwq[i]=false;
	dis[type][U]=0; Inqwq[U]=true;
	Q.push(U);
	while(Q.empty()==false){
		int u=Q.front(); Q.pop(); Inqwq[u]=false;
		for(edge *tmp=h[u];tmp!=NULL;tmp=tmp->next){
			int v=tmp->v;
			if(dis[type][v]>dis[type][u]+tmp->len){
				if(Inqwq[v]==false){
					Q.push(v);
					Inqwq[v]=true;
				}
				dis[type][v]=dis[type][u]+tmp->len;
			}
		}
	}
	cnt[type][U]=1;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++){
		int u=id[i];
		for(edge *tmp=h[u];tmp!=NULL;tmp=tmp->next){
			int v=tmp->v;
			if(dis[type][u]+tmp->len==dis[type][v]) upd(cnt[type][v],cnt[type][u]);
		}
	}
	//for(int i=1;i<=n;i++) printf("%lld ",dis[type][i]); printf("\n");
}

/*
void bfs(){
	cnt[0][S]=1;
	cnt[1][T]=1;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++){
		int u=id[i];
		for(edge *tmp=h[u];tmp!=NULL;tmp=tmp->next){
			int v=tmp->v;
			if(dis[u]+tmp->len==dis[v]) upd(cnt[0][v],cnt[0][u]);
		}
	}
	for(int i=n;i>=1;i--){
		int u=id[i];
		for(edge *tmp=h[u];tmp!=NULL;tmp=tmp->next){
			int v=tmp->v;
			if(dis[v]+tmp->len==dis[u])	upd(cnt[1][v],cnt[1][u]);
		}
	}
	ans=(cnt[0][T]*cnt[1][S])%P;
	for(int i=1;i<=n;i++) printf("%lld ",dis[i]); printf("\n");
	for(int i=1;i<=n;i++) printf("%lld ",cnt[0][i]); printf("\n");
	for(int i=1;i<=n;i++) printf("%lld ",cnt[1][i]); printf("\n");
}
*/

void init(){
	int x1,x2,x3;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&S,&T);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x1,&x2,&x3);
		addedge(x1,x2,x3);
		addedge(x2,x1,x3);
		_u[i]=x1,_v[i]=x2;
		_len[i]=x3;
	}
	//for(int i=1;i<=n;i++) id[i]=i;
	spfa(T,1);
	spfa(S,0);
	ans=(cnt[0][T]*cnt[1][S])%P;
	//printf("%lld\n",ans);
	for(int i=1;i<=m;i++){
		int u=_u[i],v=_v[i];
		if(dis[0][u]>dis[0][v]) swap(u,v);
		if(dis[0][u]+_len[i]+dis[1][v]!=dis[0][T]) continue;
		if(2*dis[0][u]<dis[0][T] && dis[0][T]<2*dis[0][v]){
			
		//	printf("%d %d\n",u,v);
			
			upd(ans,P-sq((cnt[0][u]*cnt[1][v])%P));
		}
	}	
	for(int i=1;i<=n;i++){
		int u=i;
		if(dis[0][u]==dis[1][u] && 2*dis[0][u]==dis[0][T]){
			
		//	printf("%d \n",i);
			
			upd(ans,P-sq((cnt[0][u]*cnt[1][u])%P));
		}
	}
	printf("%lld\n",ans);
}

int main(){
	init();
	return 0;
}