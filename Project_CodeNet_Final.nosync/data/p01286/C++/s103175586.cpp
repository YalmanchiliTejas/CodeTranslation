#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int D_MAX_V=2010;
const int D_v_size=2010;
struct D_wolf{
	int t,c,r;
	D_wolf(){t=c=r=0;}
	D_wolf(int t1,int c1,int r1){
		t=t1;c=c1;r=r1;
	}
};
vector<D_wolf>D_G[D_MAX_V];
int D_level[D_MAX_V];
int D_iter[D_MAX_V];

void add_edge(int from,int to,int cap){
	D_G[from].push_back(D_wolf(to,cap,D_G[to].size()));
	D_G[to].push_back(D_wolf(from,0,D_G[from].size()-1));
}
void D_bfs(int s){
	for(int i=0;i<D_v_size;i++)D_level[i]=-1;
	queue<int> Q;
	D_level[s]=0;
	Q.push(s);
	while(Q.size()){
		int v=Q.front();
		Q.pop();
		for(int i=0;i<D_G[v].size();i++){
			if(D_G[v][i].c>0&&D_level[D_G[v][i].t]<0){
				D_level[D_G[v][i].t]=D_level[v]+1;
				Q.push(D_G[v][i].t);
			}
		}
	}
}
int D_dfs(int v,int t,int f){
	if(v==t)return f;
	for(;D_iter[v]<D_G[v].size();D_iter[v]++){
		int i=D_iter[v];
		if(D_G[v][i].c>0&&D_level[v]<D_level[D_G[v][i].t]){
			int d=D_dfs(D_G[v][i].t,t,min(f,D_G[v][i].c));
			if(d>0){
				D_G[v][i].c-=d;
				D_G[D_G[v][i].t][D_G[v][i].r].c+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		D_bfs(s);
		if(D_level[t]<0)return flow;
		for(int i=0;i<D_v_size;i++)D_iter[i]=0;
		int f;
		while((f=D_dfs(s,t,99999999))>0){flow+=f;}
	}
	return 0;
}
int main(){
	int a,b,c,d,e,f,g;
	while(scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g),~a){
		for(int i=0;i<D_MAX_V;i++){
			D_level[i]=D_iter[i]=0;D_G[i].clear();
		}
		int s=2000;
		int t=2001;
		for(int i=0;i<a;i++)add_edge(s,i,1);
		for(int i=0;i<b;i++){
			int p;scanf("%d",&p);
			for(int j=0;j<p;j++){
				int q;scanf("%d",&q);
				q--;
				add_edge(q,a+i,1);
			}
			add_edge(a+i,a+b+i,1);
		}
		for(int i=0;i<a;i++)add_edge(i,a+b*2,1);
		add_edge(a+b*2,a+b*2+1,e);
		for(int i=0;i<c;i++){
			int p;scanf("%d",&p);
			for(int j=0;j<p;j++){
				int q;scanf("%d",&q);
				q--;
				add_edge(a+b+q,a+b*2+2+i,1);
			}
			add_edge(a+b*2+1,a+b*2+2+i,1);
			add_edge(a+b*2+2+i,a+b*2+2+c+i,1);
		}
		for(int i=0;i<b;i++)add_edge(a+b+i,a+b*2+2+c*2,1);
		add_edge(a+b*2+2+c*2,a+b*2+2+c*2+1,f);
		for(int i=0;i<d;i++){
			int p;scanf("%d",&p);
			for(int j=0;j<p;j++){
				int q;scanf("%d",&q);q--;
				add_edge(a+b*2+2+c+q,a+b*2+4+c*2+i,1);
			}
			add_edge(a+b*2+4+c*2+i,t,1);
			add_edge(a+b*2+c*2+3,a+b*2+4+c*2+i,1);
		}
		for(int i=0;i<c;i++)add_edge(a+b*2+2+c+i,a+b*2+4+c*2,1);
		add_edge(a+b*2+4+c*2,t,g);
		printf("%d\n",max_flow(s,t));
	}
}