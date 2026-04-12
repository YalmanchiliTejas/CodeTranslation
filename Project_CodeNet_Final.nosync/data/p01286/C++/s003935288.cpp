// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

//
const int MN = 100010;
struct dinic{
	struct edge{
		int to;ll cap;int rev;
		edge(int to,ll cap,int rev): to(to),cap(cap),rev(rev){}
	};

	vector<edge> G[MN];
	ll level[MN];
	int iter[MN];
	
	void init(int N){
		rep(i,N)G[i].clear();
	}
	
	void add_edge(int from,int to,ll cap){
		G[from].pb(edge(to,cap,sz(G[to])));
		G[to].pb(edge(from,0,sz(G[from])-1));
	}
	
	void bfs(int s){
		memset(level,-1,sizeof(level));
		queue<int> que;
		level[s]=0;
		que.push(s);
		while(!que.empty()){
			int v=que.front(); que.pop();
			rep(i,sz(G[v])){
				edge &e = G[v][i];
				if(e.cap>0 && level[e.to]<0){
					level[e.to] = level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	
	ll dfs(int v,int t,ll f){
		if(v==t)return f;
		for(int &i=iter[v]; i<sz(G[v]); i++){
			edge &e = G[v][i];
			if(e.cap>0 && level[v] < level[e.to]){
				ll d=dfs(e.to,t,min(f,e.cap));
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
		ll flow=0;
		for(;;){
			bfs(s);
			if(level[t]<0)return flow;
			memset(iter,0,sizeof(iter));
			int f;
			while((f=dfs(s,t,INF*INF))>0){
				flow+=f;
			}
		}
	}
};
//

int H,W,C,M,NW,NC,NM;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	dinic D;
	while(cin>>H>>W>>C>>M>>NW>>NC>>NM && H>=0){
		D.init(H + 2*(W+C) + M + 7);
		int s = H + 2*(W+C) + M;
		int t = s + 6;

		rep(i,H){
			D.add_edge(s,i,1);
		}

		int n,x;
		rep(i,W){
			cin>>n;
			rep(j,n){
				cin>>x;x--;
				D.add_edge(x,H+i,1); 
			}
		}
		rep(i,H){
			D.add_edge(i,s+1,1);
		}

		rep(i,W){
			D.add_edge(H+i,H+W+i,1);
		}
		D.add_edge(s+1,s+2,NW);

		rep(i,C){
			cin>>n;
			rep(j,n){
				cin>>x;x--;
				D.add_edge(H+W+x,H+2*W+i,1);
			}
		}
		rep(i,W){
			D.add_edge(H+W+i,s+3,1);
		}
		rep(i,C){
			D.add_edge(s+2,H+2*W+i,1);
		}

		rep(i,C){
			D.add_edge(H+2*W+i,H+2*W+C+i,1);
		}
		D.add_edge(s+3,s+4,NC);

		rep(i,M){
			cin>>n;
			rep(j,n){
				cin>>x;x--;
				D.add_edge(H+2*W+C+x,H+2*W+2*C+i,1);
			}
		}
		rep(i,C){
			D.add_edge(H+2*W+C+i,s+5,1);
		}
		rep(i,M){
			D.add_edge(s+4,H+2*W+2*C+i,1);
		}

		rep(i,M){
			D.add_edge(H+2*W+2*C+i,t,1);
		}
		D.add_edge(s+5,t,NM);

		cout<<D.max_flow(s,t)<<endl;
	}
}