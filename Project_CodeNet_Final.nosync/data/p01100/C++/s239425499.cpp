#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
#define inf 1e9

struct edge{
    ll to,cap,cost,rev;
    edge(){}
    edge(ll to,ll cap,ll rev):to(to),cap(cap),rev(rev){}
    edge(ll to,ll cap,ll cost,ll rev):to(to),cap(cap),cost(cost),rev(rev){}
};

typedef vector<vector<edge> > graph;
struct Dinic{
    ll n;
    graph g;
    vector<ll> level,iter;
    Dinic() {}
    Dinic(ll n): n(n){
	g.resize(n);
	level.resize(n);
	iter.resize(n);
    }
    void add_edge(ll from, ll to, ll cost){
	g[from].push_back(edge(to,cost,g[to].size()   ) );
	g[to].push_back(edge(from,0,g[from].size() -1 ) );
    }
    void bfs(ll s){
	fill(level.begin(),level.end(),-1);
	queue<ll> q;
	q.push(s);
	level[s] = 0;
	while(!q.empty()){
	    ll tmp = q.front();
	    q.pop();
	    for(ll i=0;i<g[tmp].size();i++){
		edge &e = g[tmp][i];
		if(e.cap > 0 && level[e.to] < 0){
		    level[e.to] = level[tmp] + 1;
		    q.push(e.to);
		}
	    }
	}
    }
    ll dfs(ll v,ll t,ll f){
	if( v == t ) return f;
	for(ll &i = iter[v]; i < g[v].size() ; i++){
	    edge &e = g[v][i];
	    if( e.cap > 0 && level[v] < level[e.to] ){
		ll d = dfs(e.to, t, min(f,e.cap) );
		if( d > 0 ){
		    e.cap -= d;
		    g[e.to][e.rev].cap += d;
		    return d;
		}
	    }
	}
	return 0;
    }
    ll max_flow(ll s,ll t){
	ll flow = 0, f;
	while(1){
	    bfs(s);
	    if(level[t] < 0) return flow;
	    fill(iter.begin(),iter.end() , 0);
	    for(f = dfs(s,t,inf); f > 0; f = dfs(s,t,inf) ) flow += f;
	}
    }
};

struct Dinic_lr{
    Dinic f;
    ll S,T,sum_lb;
    Dinic_lr(){}
    Dinic_lr(ll n): f(n+2),S(n),T(n+1),sum_lb(0){}
    void add_edge(ll u,ll v,ll lb,ll ub){
	if( u== v || ub == 0)return ;
	f.add_edge(u,v,ub-lb);
	f.add_edge(S,v,lb);
	f.add_edge(u,T,lb);
	sum_lb += lb;
    }
    ll max_flow(ll s,ll t){
	//この順番で流すことがいい，Sから流すことで流す流量を先に減らせる．
	//そのことで通れなくなるパスは，その頂点から直接Tに向かうことができる．
	// s->T , S->tはよくわからない	
       
        ll a = f.max_flow(S,T);
	ll b = f.max_flow(s,T);
        ll c = f.max_flow(S,t);
        ll d = f.max_flow(s,t);
      
	
	//a+c は　最小流量が流れるか? a+b は最小流量が戻るか?
	return ( a + c == sum_lb && a + b == sum_lb ) ? b+d: -1;
    }
};


int main(){
    ll n,m;
 while(1){
    cin>>n>>m;
   if(n==0)break;
    vector<ll> u(m),v(m);
    for(ll i=0;i<m;i++){
	cin>>u[i]>>v[i];
	u[i]--,v[i]--;
    }
    ll p = 0,q = n;
    ll l=0;
    for(ll r = 0; r <= n; r++){
     while( l <= r ){
      Dinic_lr f(n+m+2);
      ll S = n+m,T = n+m+1;
      for(ll i=0;i<m;i++){
       f.add_edge(S,i,1,1);
       f.add_edge(i,m+u[i],0,1);
       f.add_edge(i,m+v[i],0,1);
      }
      for(ll i=0;i<n;i++){
       f.add_edge(m+i,T,l,r);
      }
      ll flow = f.max_flow(S,T);
      if( flow !=  m ){
       break;
      }
      p = l;
      q = r;
      l++;

     }
    }
    cout<<p<<' '<<q<<endl;
 }

    //cout<<f.max_flow(0,v-1)<<endl;
    
    return 0;
}

