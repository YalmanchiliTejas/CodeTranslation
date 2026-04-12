#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define MRE assert(0);
const long long inf=1e17;
struct edge{int to,cap,rev;};
vector<edge>G[100006];
vector<int>G2[100006];
int dis[100006];
int iter[100006];
int a[100006],b[100006];
int clr[100006];

void dfs2(int now,int par){
	for(int e:G2[now]){
		if(e==par)continue;
		clr[e]=clr[now]+1;
		dfs2(e,now);
		}
	}

void add_edge(int from,int to,int cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
	}	
	
void bfs(int s){
	memset(dis,-1,sizeof(dis));
	queue<int>Q;
	dis[s]=0;
	Q.push(s);
	while(Q.size()){
		int v=Q.front();Q.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0&&dis[e.to]<0){
				dis[e.to]=dis[v]+1;
				Q.push(e.to);
				}
			}
		}
	}
	
int dfs(int v,int t,int f){
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0&&dis[v]<dis[e.to]){
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
	
int maxflow(int s,int t){
	int flow=0;
	while(1){
		bfs(s);
		if(dis[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,inf))>0){
			flow+=f;
			}
		}
	}	
			
signed main(){
	int n;cin>>n;
	rep(i,n-1){
		int A,B;cin>>A>>B;
		a[i]=A;b[i]=B;
		G2[A-1].push_back(B-1);
		G2[B-1].push_back(A-1);
		}
	dfs2(0,-1);
	rep(i,n-1){
		if(clr[a[i]-1]&1)add_edge(a[i],b[i],1);
		else add_edge(b[i],a[i],1);
		}	
	rep(i,n){
		if(clr[i]&1)add_edge(0,i+1,1);
		else add_edge(i+1,n+1,1);
		}	
		
	int res=maxflow(0,n+1);
//	cout<<res<<endl;
	if(res*2==n)puts("Second");
	else puts("First");	
	
	}
