#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define INF 10000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct edge{
	int to,cap,rev;
	edge(){}
	edge(int tt,int cc,int rr){
		to=tt;
		cap=cc;
		rev=rr;
	}
};

vector<edge> G[1000];
int level[1000];
int iter[1000];

void add_edge(int from,int to,int cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
}

void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(que.size()){
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
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(e.cap,f));
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
	while(1){
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}

int h,w,c,m,nw,nc,nm;

int main(void){
	while(1){
		scanf("%d%d%d%d%d%d%d",&h,&w,&c,&m,&nw,&nc,&nm);
		if(h==-1)break;
		int party=h+w+c+m;
		int s=(party+3)*2,t=s+1;
		for(int i=0;i<=t;i++){
			G[i].clear();
		}
		add_edge(party*2,party*2+1,nw);
		add_edge(party*2+2,party*2+3,nc);
		add_edge(party*2+4,party*2+5,nm);
		for(int i=0;i<c;i++){
			add_edge(party*2+1,h+w+i,1);
		}
		for(int i=0;i<m;i++){
			add_edge(party*2+3,h+w+c+i,1);
		}
		add_edge(party*2+5,t,nm);
		for(int i=0;i<h;i++){
			add_edge(i+party,party*2,1);
		}
		for(int i=0;i<party;i++){
			add_edge(i,i+party,1);
		}
		for(int i=0;i<h;i++){
			add_edge(s,i,1);
		}
		for(int i=0;i<w;i++){
			int ni;
			scanf("%d",&ni);
			for(int j=0;j<ni;j++){
				int a;
				scanf("%d",&a);
				a--;
				add_edge(a+party,h+i,1);
			}
			add_edge(party+h+i,party*2+2,1);
		}
		for(int i=0;i<c;i++){
			int ni;
			scanf("%d",&ni);
			for(int j=0;j<ni;j++){
				int a;
				scanf("%d",&a);
				a--;
				add_edge(party+h+a,h+w+i,1);
			}
			add_edge(party+h+w+i,party*2+4,1);
		}
		for(int i=0;i<m;i++){
			int ni;
			scanf("%d",&ni);
			for(int j=0;j<ni;j++){
				int a;
				scanf("%d",&a);
				a--;
				add_edge(party+a+h+w,h+w+c+i,1);
			}
			add_edge(party+h+w+c+i,t,1);
		}
		printf("%d\n",max_flow(s,t));
	}
	return 0;
}