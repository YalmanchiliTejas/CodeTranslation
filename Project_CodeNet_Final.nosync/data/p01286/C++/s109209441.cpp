#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;

using edge=struct {int to,cap,rev;};
using G=vector<vector<edge>>;
const int inf=1<<29;

void add_edge(G &graph,int a,int b,int c){
	//cout << a << " " << b << " " << c << endl;
	graph[a].push_back({b,c,int(graph[b].size())});
	graph[b].push_back({a,0,int(graph[a].size()-1)});
}

int max_flow(G &graph,int s,int t){
	int n=graph.size(),flow=0;
	vector<int> used(n);

	auto dfs=[&](int v,int t,int f,const auto& self)->int{
		if(v==t) return f;
		used[v]=true;
		for(auto &e:graph[v]){
			if(used[e.to] || e.cap<=0) continue;
			int d=self(e.to,t,min(f,e.cap),self);
			if(d > 0){
				e.cap-=d;
				graph[e.to][e.rev].cap+=d;
				return d;
			}
		}
		return 0;
	};

	while(1){
		fill(begin(used),end(used),false);
		int f=dfs(s,t,inf,dfs);
		if(f==0) break;
		flow+=f;
	}
	return flow;
}

int main(void){
	int h,w,c,m,nw,nc,nm;
	while(cin >> h >> w >> c >> m >> nw >> nc >> nm){
		if(h==-1) break;

		const int ho=0,wo=h,co=h+2*(w+1),mo=h+2*(w+c+2);	
		const int s=h+2*(w+c+m+3);
		const int t=s+1;

		const int all=t+1;

		G graph(all);
		rep(i,h) add_edge(graph,s,ho+i,1);

		rep(i,w){
			int n,j;
			cin >> n;
			rep(loop,n){
				cin >> j;
				j--;
				add_edge(graph,ho+j,wo+2*i,1); 
			}
		}

		rep(i,h) add_edge(graph,ho+i,wo+2*w,inf);

		rep(i,w) add_edge(graph,wo+2*i,wo+2*i+1,1);
		add_edge(graph,wo+2*w,wo+2*w+1,nw);


		rep(i,c){
			int n,j;
			cin >> n;
			rep(loop,n){
				cin >> j;
				j--;
				add_edge(graph,wo+2*j+1,co+2*i,1); 
			}
		}

		rep(i,w) add_edge(graph,wo+2*i+1,co+2*c,inf);
		rep(i,c) add_edge(graph,wo+2*w+1,co+2*i,inf);

		rep(i,c) add_edge(graph,co+2*i,co+2*i+1,1);
		add_edge(graph,co+2*c,co+2*c+1,nc);


		rep(i,m){
			int n,j;
			cin >> n;
			rep(loop,n){
				cin >> j;
				j--;
				add_edge(graph,co+2*j+1,mo+2*i,1); 
			}
		}

		rep(i,c) add_edge(graph,co+2*i+1,mo+2*m,inf);
		rep(i,m) add_edge(graph,co+2*c+1,mo+2*i,inf);
		

		rep(i,m) add_edge(graph,mo+2*i,mo+2*i+1,1);
		add_edge(graph,mo+2*m,mo+2*m+1,nm);
		
		rep(i,m+1) add_edge(graph,mo+2*i+1,t,inf);

		cout << max_flow(graph,s,t) << endl;
	}
	return 0;
}