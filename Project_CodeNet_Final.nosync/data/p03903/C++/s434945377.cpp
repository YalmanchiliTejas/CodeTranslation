#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

vector<int> par,rk;

void init(const int n){
	par.resize(n);
	rk.resize(n);
	for(int i=0;i<n;++i) par[i]=i;
	fill(rk.begin(),rk.end(),0);
}

int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return;
	}else if(rk[x]<rk[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rk[x]==rk[y]){
			++rk[x];
		}
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

struct edge{
	int from,to;
	ll cost;
};

bool cmp(edge e,edge f){
	return e.cost<f.cost;
}

#define MAX_Q 100000

vector<edge> es;

#define MAX_N 4000

vector<int> g[MAX_N];
ll d[MAX_N][MAX_N];

void dfs(int v0,int v){
	for(int j=0;j<g[v].size();++j){
		int e=g[v][j],w=es[e].from;
		if(v==w) w=es[e].to;
		if(d[v0][w]>=0) continue;
		d[v0][w]=max(d[v0][v],es[e].cost);
		dfs(v0,w);
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	while(m-->0){
		int a,b,c;
		cin>>a>>b>>c;
		es.pb((edge){--a,--b,c});
	}
	sort(es.begin(),es.end(),cmp);
	init(n);
	ll sc=0;
	for(int j=0,e=0;e<n-1;++j){
		int v=es[j].from,w=es[j].to;
		if(same(v,w)) continue;
		unite(v,w);
		sc+=es[j].cost;
		g[v].pb(j);
		g[w].pb(j);
		++e;
	}
	for(int v=0;v<n;++v){
		fill(d[v],d[v]+n,-1);
		d[v][v]=0;
		dfs(v,v);
	}
	int q;
	scanf("%d",&q);
	while(q-->0){
		int s,t;
		scanf("%d%d",&s,&t);
		printf("%lld\n",sc-d[--s][--t]);
	}
}