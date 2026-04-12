#include<queue>
#include<cstdio>
#include<vector>

#define	pb			push_back
#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

typedef	vector<bool>	vb;
typedef	vector<int>		vi;
typedef	vector<vi>		vvi;

const int INF=1<<29;

int Edmonds_Karp(const vvi &adj,int src,int snk){
	int n=adj.size(),ans=0;
	vector<vi> flow(n,vi(n));

	while(1){
		bool ok=false;
		vi augpath(n);	augpath[src]=-1;
		vi maxflow(n);	maxflow[src]=INF;
		{
			vb visited(n);	visited[src]=true;
			queue<int> qu;	qu.push(src);
			while(!qu.empty()){
				int u=qu.front();	qu.pop();
				if(u==snk){ ok=true; break; }

				rep(v,n){
					int capa=adj[u][v];
					if(!visited[v] && capa-flow[u][v]>0){
						visited[v]=true;
						augpath[v]=u;
						maxflow[v]=min(maxflow[u],capa-flow[u][v]);
						qu.push(v);
					}
				}
			}
		}
		if(!ok)	break;

		for(int u=snk;~augpath[u];u=augpath[u]){
			flow[augpath[u]][u]+=maxflow[snk];
			flow[u][augpath[u]]-=maxflow[snk];
		}
		ans+=maxflow[snk];
	}

	return ans;
}

int main(){
	for(int h,w,c,m,nw,nc,nm;scanf("%d%d%d%d%d%d%d",&h,&w,&c,&m,&nw,&nc,&nm),h>=0;){
		int nn=1+h+2*(w+c+m)+1;
		int n=nn+5;
		int src=0,snk=nn-1;
		vvi adj(n,vi(n));
		for(int v=1;v<1+h;v++)									adj[src][v]=1;
		for(int u=1+h,v=u+w;u<1+h+w;u++,v++)					adj[u][v]=1;
		for(int u=1+h+2*w,v=u+c;u<1+h+2*w+c;u++,v++)			adj[u][v]=1;
		for(int u=1+h+2*w+2*c,v=u+m;u<1+h+2*w+2*c+m;u++,v++)	adj[u][v]=1;
		for(int u=nn-m-1;u<snk;u++)								adj[u][snk]=1;
		adj[nn+0][nn+1]=nw;
		adj[nn+2][nn+3]=nc;
		adj[nn+4][snk]=nm;
		for(int u=1;u<1+h;u++)							adj[u][nn+0]=1;
		for(int v=1+h+2*w;v<1+h+2*w+c;v++)				adj[nn+1][v]=1;
		for(int u=1+h+w;u<1+h+2*w;u++)					adj[u][nn+2]=1;
		for(int v=1+h+2*w+2*c;v<1+h+2*w+2*c+m;v++)		adj[nn+3][v]=1;
		for(int u=1+h+2*w+c;u<1+h+2*w+2*c;u++)			adj[u][nn+4]=1;
		rep(b,w){
			int num;	scanf("%d",&num);
			rep(i,num){
				int a;	scanf("%d",&a);
				int u=1+(a-1),v=1+h+b;
				adj[u][v]=1;
			}
		}
		rep(b,c){
			int num;	scanf("%d",&num);
			rep(i,num){
				int a;	scanf("%d",&a);
				int u=1+h+w+(a-1),v=1+h+2*w+b;
				adj[u][v]=1;
			}
		}
		rep(b,m){
			int num;	scanf("%d",&num);
			rep(i,num){
				int a;	scanf("%d",&a);
				int u=1+h+2*w+c+(a-1),v=1+h+2*w+2*c+b;
				adj[u][v]=1;
			}
		}

		printf("%d\n",Edmonds_Karp(adj,src,snk));
	}

	return 0;
}