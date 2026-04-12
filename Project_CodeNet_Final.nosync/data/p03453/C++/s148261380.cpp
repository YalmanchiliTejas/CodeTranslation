#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#include <bitset>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f3f3f3f3fLL
#define SIZE 8080
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
ll MOD=1e9+7;
typedef ll Weight;
struct Edge {
	int src, dst;
	Weight weight;
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int N,M;
ll dp[114514]={0};
void shortestPath(const Graph &g, int s,
				  vector<Weight> &dist, vector<int> &prev) {
	int n = g.size();
	dist.assign(n, INF); dist[s] = 0;
	rep(i,n)dp[i]=0;
	prev.assign(n, -1);
	dp[s]=1;
	priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
	Edge hoge={-2, s, 0};
	for (Q.push(hoge); !Q.empty(); ) {
		Edge e = Q.top(); Q.pop();
		if (prev[e.dst] != -1) continue;
		prev[e.dst] = e.src;
		FOR(f,g[e.dst]){
			if (dist[f->dst] > e.weight+f->weight) {
			 dist[f->dst] = e.weight+f->weight;
				dp[f->dst] =dp[f->src];
				Edge fuga={f->src, f->dst, e.weight+f->weight};
				Q.push(fuga);
			}else if(dist[f->dst] == e.weight+f->weight){
				dp[f->dst]=(dp[f->dst]+dp[f->src])%MOD;
			}
		}
	}
}

int main(){
	cin>>N>>M;
	int S,T;
	cin>>S>>T;S--;T--;
	Graph Gph(N);
	vector<pair<pii,ll> > data;
	for(int i=0;i<M;i++){
		int u,v;
		Weight d;
		cin>>u>>v>>d;u--;v--;
		Edge hen={u,v,d};
		Gph[u].pb(hen);
		Edge gen={v,u,d};
		Gph[v].pb(gen);
		data.pb(mp(mp(u,v),d));
	}
	vector<Weight> ans,ans2;
	vi hoge;
	shortestPath(Gph,S,ans,hoge);
	ll kyori=ans[T];
	ll dp2[114514];
	for(int i=0;i<N;i++){
		dp2[i]=dp[i];
	}
	//for(int i=0;i<N;i++)cout<<dp[i]<<endl;
	shortestPath(Gph,T,ans2,hoge);
	ll Ans=0;
	for(int i=0;i<M;i++){
		pii za = data[i].first;
		int x = za.first,y = za.second;
		if(ans[x]>ans[y])swap(x,y);
		//cout<<ans[x] + ans2[y] + data[i].second<<endl;
		if((ll)(2*ans[x])<kyori && kyori<(ll)(2*(ans[x]+data[i].second)) && (ans[x] + ans2[y] + data[i].second) == kyori){
			Ans = (Ans+((dp2[x]*dp[y])%MOD) * ((dp2[x]*dp[y])%MOD)%MOD)%MOD;
			//cout<<kyori<<" "<<data[i].second<<endl;
		}
	}
	//cout<<Ans<<endl;
	for(int i=0;i<N;i++){
		if((ll)2*ans[i] == kyori){
			Ans = (Ans+((dp[i]*dp2[i])%MOD)*((dp[i]*dp2[i])%MOD)%MOD)%MOD;
		}
	}	
	//rep(i,N)cout<<dp2[i]<<" ";
	//cout<<endl;
	//cout<<kyori<<endl;
	Ans = ((dp[S]*dp[S])%MOD + MOD - Ans)%MOD;
	cout<<Ans<<endl;
}