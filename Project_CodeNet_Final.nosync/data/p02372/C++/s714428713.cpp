#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF (1e9+1)
//#define INF (1LL<<59)

//verified AOJ GRL_1
#define MAX_V 10000
struct edge{int to,cost;};

void dijkstra(int s, vector<int> &d, vector<edge> G[MAX_V]){
	priority_queue< pii,vector<pii>,greater<pii> > que;
	rep( i,d.size() )d[i]=INF;
	d[s] = 0;
	que.push( pii(0,s) );
	
	while( que.size() ){
		pii p=que.top();
		que.pop();
		
		int v=p.second;
		if(d[v]<p.first)continue;
		
		rep(i,G[v].size()){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(pii(d[e.to],e.to));
			}
		}
	}
}

//??¨?????´??? verified AOJ GRL_5_A

pii dfs(int prev, int v, const vector<edge> graph[MAX_V]){   //searching farthest node
	pii r(0,v);
	
	rep(i,graph[v].size()){
		struct edge e = graph[v][i];
		if(e.to == prev) continue;
		pii tmp = dfs(v,e.to,graph);
		tmp.first += e.cost;
		if(r.first < tmp.first) r = tmp;
	}
	return r;
}


pii diameter( const vector<edge> graph[MAX_V] ) {
	pii r = dfs(-1, 0, graph);
	pii t = dfs(-1, r.second, graph);
	return pii(r.second,t.second);
}

int main(){
	int v;
	cin>>v;

	vector<edge> G[MAX_V];
	rep(i,v-1){
		int s,t,c;
		cin>>s>>t>>c;
		G[s].pb({t,c});
		G[t].pb({s,c});
	}
	pii res = diameter(G);
	
	vector<int> d1(MAX_V),d2(MAX_V);
	dijkstra(res.first ,d1,G);
	dijkstra(res.second,d2,G);
	
	
	rep(i,v){
		cout<<max(d1[i],d2[i])<<endl;
	}
}