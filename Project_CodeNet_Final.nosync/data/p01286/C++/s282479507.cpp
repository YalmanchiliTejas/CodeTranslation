#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
struct edge {int to,cap,rev;};
const int MAX_V=408,inf=1e8;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from, int to, int cap){
	edge e1={to,cap,G[to].size()},e2={from,0,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	while(true){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while( (f=dfs(s,t,inf))>0 ) flow+=f;
	}
}
int main(){
	while(true){
		int H,W,C,M,NW,NC,NM;
		scanf("%d%d%d%d%d%d%d",&H,&W,&C,&M,&NW,&NC,&NM);
		if(H<0) break;
		rep(i,MAX_V) G[i].clear();
		int al=H+W+C+M;
		int s=al*2,t=s+1,wi=t+1,wo=t+2,ci=t+3,co=t+4,mi=t+5,mo=t+6;
		rep(i,al) add_edge(i,i+al,1);
		rep(i,H) add_edge(s,i,1);
		rep(i,H) add_edge(i+al,wi,1);
		add_edge(wi,wo,NW);
		rep(i,W) add_edge(al+H+i,ci,1);
		rep(i,C) add_edge(wo,H+W+i,1);
		rep(i,C) add_edge(H+W+i+al,mi,1);
		add_edge(ci,co,NC);
		rep(i,M) add_edge(co,H+W+C+i,1);
		rep(i,M) add_edge(H+W+C+i+al,t,1);
		add_edge(mi,mo,NM);
		add_edge(mo,t,inf);
		rep(i,W){
			int ww;
			scanf("%d",&ww);
			rep(j,ww){
				int hh;
				scanf("%d",&hh);
				hh--;
				add_edge(hh+al,H+i,1);
			}
		}
		rep(i,C){
			int cc;
			scanf("%d",&cc);
			rep(j,cc){
				int ww;
				scanf("%d",&ww);
				ww--;
				add_edge(H+ww+al,H+W+i,1);
			}
		}
		rep(i,M){
			int mm;
			scanf("%d",&mm);
			rep(j,mm){
				int cc;
				scanf("%d",&cc);
				cc--;
				add_edge(H+W+cc+al,H+W+C+i,1);
			}
		}
		cout<<max_flow(s,t)<<endl;
	}
}