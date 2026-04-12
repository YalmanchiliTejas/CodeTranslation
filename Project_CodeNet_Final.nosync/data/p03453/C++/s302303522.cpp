#include<bits/stdc++.h>
#define MAX_N 100005
#define inf (1LL<<60)
#define LL long long
#define pb push_back
#define MOD 1000000007LL
using namespace std;
struct node{
	LL y,cost;
};
struct cmp{
	bool operator()(node x,node y){
		if(x.cost==y.cost)	return x.y<y.y;
		return x.cost>y.cost;
	}
};
LL n,m;
LL dst[2][MAX_N],t[2][MAX_N];
LL ans;
priority_queue<node,vector<node>,cmp> Q;
vector<node> net[MAX_N];
void dijkstra(LL s,LL z){
	LL sz,i;
	node p,q;
	for(i=1;i<=n;i++)	dst[z][i]=inf;
	dst[z][s]=0;
	t[z][s]=1;
	Q.push({s,0});
	while(!Q.empty()){
		p=Q.top();Q.pop();
		if(dst[z][p.y]!=p.cost)	continue;
		sz=net[p.y].size();
		while(sz--){
			q=net[p.y][sz];
			if(dst[z][q.y]==p.cost+q.cost){
				t[z][q.y]=(t[z][q.y]+t[z][p.y])%MOD;
			}
			if(dst[z][q.y]>p.cost+q.cost){
				dst[z][q.y]=p.cost+q.cost;
				t[z][q.y]=t[z][p.y];
				Q.push({q.y,dst[z][q.y]});
			}
		}
	}
}
int main(){
	LL s,e,i,x;
	node p;
	scanf("%lld %lld",&n,&m);
	scanf("%lld %lld",&s,&e);
	for(i=1;i<=m;i++){
		scanf("%lld %lld %lld",&x,&p.y,&p.cost);
		net[x].pb(p);
		swap(x,p.y);net[x].pb(p);
	}
	dijkstra(s,0);
	dijkstra(e,1);
	ans=(t[0][e]*t[0][e])%MOD;
	for(i=1;i<=n;i++){
		if(dst[0][i]==dst[1][i] && dst[0][i]+dst[1][i]==dst[0][e])	ans=(ans-(((t[0][i]*t[1][i])%MOD)*((t[0][i]*t[1][i])%MOD)%MOD)+MOD)%MOD;
	}
	LL sz;
	for(i=1;i<=n;i++){
		sz=net[i].size();
		while(sz--){
			p=net[i][sz];
			if(dst[0][i]+dst[1][p.y]+p.cost!=dst[0][e])	continue;
			if(dst[1][p.y]+p.cost>dst[0][i] && dst[0][i]+p.cost>dst[1][p.y])	ans=(ans-((((t[0][i]*t[1][p.y])%MOD)*((t[0][i]*t[1][p.y])%MOD))%MOD)+MOD)%MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}