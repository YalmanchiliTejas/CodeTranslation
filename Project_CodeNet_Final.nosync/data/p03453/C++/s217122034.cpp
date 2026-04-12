#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
typedef pair<ll,int> P;
const int MAX_N=1e5;
const ll MOD=1e9+7,INF=1e18;
struct edge{
	int t;
	ll c;
	edge(int t=-1,ll c=0):t(t),c(c){}
};
int N,M;
vector<edge> G[MAX_N];
ll dist[2][MAX_N],com[2][MAX_N];
int S,T;
void dijkstra(int s){
	int f;
	if (s==S){
		f=0;
	}else{
		f=1;
	}
	fill(dist[f],dist[f]+N,INF);
	dist[f][s]=0;
	priority_queue<P,vector<P> ,greater<P> > pque;
	pque.push(P(0,s));
	while(!pque.empty()){
		P p=pque.top();
		pque.pop();
		int v=p.second;
		if (dist[f][v]<p.first) continue;
		for(auto e:G[v]){
			if (dist[f][e.t]>dist[f][v]+e.c){
				dist[f][e.t]=dist[f][v]+e.c;
				pque.push(P(dist[f][e.t],e.t));
			}
		}
	}
}
void calcom(int s){
	int f;
	if (s==S){
		f=0;
	}else{
		f=1;
	}
	vector<bool> used(N);
	com[f][s]=1;
	priority_queue<P,vector<P> ,greater<P> > pque;
	pque.push(P(0,s));
	while(!pque.empty()){
		P p=pque.top();
		pque.pop();
		int v=p.second;
		if (used[v]) continue;
		used[v]=true;
		for(auto e:G[v]){
			if (dist[f][e.t]==dist[f][v]+e.c){
				com[f][e.t]+=com[f][v];
				com[f][e.t]%=MOD;
				pque.push(P(dist[f][e.t],e.t));
			}
		}
	}
}

int main(){
	cin>>N>>M>>S>>T;
	S--;
	T--;
	REP(i,M){
		int u,v;
		ll d;
		cin>>u>>v>>d;
		u--;
		v--;
		G[u].push_back(edge(v,d));
		G[v].push_back(edge(u,d));
	}
	dijkstra(S);
	calcom(S);
	dijkstra(T);
	calcom(T);
	ll ans=0;
	REP(v,N){
		if (dist[0][v]*2==dist[0][T] && dist[1][v]*2==dist[0][T]){
			ans+=com[0][v]*com[1][v]%MOD*(com[0][T]-com[0][v]*com[1][v]%MOD+MOD)%MOD;
			ans%=MOD;
		}
		for(auto e:G[v]){
			ll d=dist[0][T],c=com[0][T];
			if (dist[0][v]+dist[1][e.t]+e.c==d && dist[0][v]*2<d && d<(dist[0][v]+e.c)*2){
				ans+=com[0][v]*com[1][e.t]%MOD*(c-com[0][v]*com[1][e.t]%MOD+MOD)%MOD;
				ans%=MOD;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}