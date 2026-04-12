#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<bitset>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long int ll;
typedef pair<ll,ll> P;
struct edge{ll to,cost;};
#define REP(i,n) for(int i=0;i<(n);i++)
const ll INF=100000000000000;

bool F[10][10][10];
P info[10];
vector<edge> G[10];
ll N,M;
ll ans=0;
ll d[10];

void Dijkstra(int s){
	std::priority_queue<P,vector<P>,std::greater<P>> que;
	std::fill(d,d+N,INF);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p =que.top();que.pop();
		int v=p.second;
		if(d[v]<p.first)continue;
		for(int i=0;i<(signed)G[v].size();i++){
			edge e =G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

int main(){
	cout<<boolalpha;
	cin>>N>>M;
	REP(i,M){
		int a,b;
		cin>>a>>b;
		info[i]=P(a,b);
	}
	REP(Bit,1<<M){//111
       if(__builtin_popcount(Bit)!=N-1)continue;
		REP(i,10){
			G[i].clear();
		}
		int cost=0;
		for(int i=M-1;0<=i;i--){
			if(Bit&(1<<i)){
				cost++;
				int a=info[i].first;
				int b=info[i].second;
				edge e;
				e.to=b-1,e.cost=1;
				G[a-1].push_back(e);
				e.to=a-1;
				G[b-1].push_back(e);
			}
		}
		Dijkstra(0);
		for(int i=1;i<N;i++){
			if(d[i]==N-1)ans++;
			ARDEB(i,d)END
		}
		DEB("restwe4twtw3t")END
		DEB(G[0].empty())END
	}
	cout<<ans<<endl;
	return 0;
}
