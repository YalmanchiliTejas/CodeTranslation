#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF=1e15;
const int MOD = 1e9 + 7;

struct Edge{
    int from,to;
	ll cost;
    Edge(int from, int to, ll cost): from(from),to(to), cost(cost){}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &e, const Edge &f){
    return e.cost > f.cost;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n,m;cin>>n>>m;
	int s,t;cin>>s>>t; s--;t--;
	vector<Edge> es;
	Graph g(n);
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v; u--;v--;
		ll d;cin>>d;
		es.push_back(Edge(u,v,d));
		es.push_back(Edge(v,u,d));
		g[u].push_back(Edge(u,v,d));
		g[v].push_back(Edge(v,u,d));
	}
	vector<ll> dp1(n,0),dp2(n,0);// s,tからの最短路の個数
	dp1[s]=1; dp2[t]=1;
	vector<ll> dis1(n,INF),dis2(n,INF);
	dis1[s]=0; dis2[t]=0;
	priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0,s)); // P(dis, pos)
    while(!que.empty()){
        ll dist = que.top().first;
        int v = que.top().second;
        que.pop();
        if(dis1[v]<dist) continue;
        for(const auto &e: g[v]){
            if(dis1[e.to]<dis1[v]+e.cost) continue;
			else if(dis1[e.to]==dis1[v]+e.cost){
				dp1[e.to] += dp1[v];
				dp1[e.to] %=MOD;
				continue;
			}
            dis1[e.to] = dis1[v] + e.cost;
			dp1[e.to] = dp1[v];
            que.push(P(dis1[e.to], e.to));
        }
    }
	que.push(P(0,t)); // P(dis, pos)
    while(!que.empty()){
        ll dist = que.top().first;
        int v = que.top().second;
        que.pop();
        if(dis2[v]<dist) continue;
        for(const auto &e: g[v]){
            if(dis2[e.to]<dis2[v]+e.cost) continue;
			else if(dis2[e.to]==dis2[v]+e.cost){
				dp2[e.to] += dp2[v];
				dp2[e.to] %=MOD;
				continue;
			}
            dis2[e.to] = dis2[v] + e.cost;
			dp2[e.to] = dp2[v];
            que.push(P(dis2[e.to], e.to));
        }
    }
	ll res = dp1[t]*dp1[t]; res %= MOD;
	ll col=0;
	for(int i=0;i<n;i++){
		if(2*dis1[i]!=dis1[t]) continue;
		if(dis1[i]+dis2[i]!=dis1[t]) continue;
		ll tmp= dp1[i]*dp2[i]; tmp %=MOD;
		tmp *= tmp; tmp %= MOD;
		col += tmp; col %= MOD;
	}
	for(int i=0;i<2*m;i++){
		Edge e=es[i];
		int u=e.from, v=e.to;
		ll c=e.cost;
		if(2*dis1[u]>=dis1[t] || 2*dis1[v]<=dis1[t] || dis1[u]+c!=dis1[v]) continue;
		if(dis1[u]+dis2[u]!=dis1[t] || dis1[v]+dis2[v]!=dis1[t]) continue;
		ll tmp=dp1[u]*dp2[v]; tmp%=MOD;
		tmp *= tmp; tmp%=MOD;
		col += tmp; col %=MOD;
	}
	cout<< (res-col+MOD)%MOD<<endl;
}
