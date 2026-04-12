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
long long int MOD = 1000000007;

pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r = 0) {
	int n = g.size();
	Edges T;
	Weight total = 0;
	
	vector<bool> visited(n);
	priority_queue<Edge> Q;
	Edge hoge={-1, r, 0};
	Q.push( hoge );
	while (!Q.empty()) {
		Edge e = Q.top(); Q.pop();
		if (visited[e.dst]) continue;
		T.push_back(e);
		total += e.weight;
		visited[e.dst] = true;
		FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
	}
	return pair<Weight, Edges>(total, T);
}
int N,M;
int main(){
	cin>>N;
	Graph G(N);
	vector<pair< pair<ll,ll>,int > > datax,datay;
	for(int i=0;i<N;i++){
		ll x,y;
		cin>>x>>y;
		datax.pb(mp(mp(x,y),i));
		datay.pb(mp(mp(y,x),i));
	}
	sort(datax.begin(),datax.end());
	sort(datay.begin(),datay.end());
	for(int i=0;i<N-1;i++){
		ll a=datax[i].first.first,c=datax[i+1].first.first;
		ll b=datax[i].first.second,d=datax[i+1].first.second;
		int num1=datax[i].second,num2=datax[i+1].second;
		Edge hen1={num1,num2,min(abs(a-c),abs(b-d))};
		Edge hen2={num2,num1,min(abs(a-c),abs(b-d))};
		G[num1].pb(hen1);
		G[num2].pb(hen2);
	}
	for(int i=0;i<N-1;i++){
		ll a=datay[i].first.first,c=datay[i+1].first.first;
		ll b=datay[i].first.second,d=datay[i+1].first.second;
		int num1=datay[i].second,num2=datay[i+1].second;
		Edge hen1={num1,num2,min(abs(a-c),abs(b-d))};
		Edge hen2={num2,num1,min(abs(a-c),abs(b-d))};
		G[num1].pb(hen1);
		G[num2].pb(hen2);
	}
	pair<Weight, Edges> ans=minimumSpanningTree(G,0);
	cout<<ans.first<<endl;
	
}