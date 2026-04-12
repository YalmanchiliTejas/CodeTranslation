#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;

#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)


typedef pair<int,int> P;
struct edge {int to,cap,cost,rev;};
const int MAX_V=80100;
int V;			//代入!!
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
int top[MAX_V];
int s,t,l,r;
void add_edge(int from, int to, int cap, int cost){
//	printf("%d->%d  cap=%d,cost=%d\n",from,to,cap,cost);
	edge e1={to,cap,cost,(int)G[to].size()},e2={from,0,-cost,(int)G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int min_cost_flow(int s, int t, int f){
	int res=0;
	fill(h,h+V,0);
	rep(i,V){
		int v=top[i];
		rep(j,G[v].size()){
			edge &e=G[v][j];
			if(e.cap==0) continue;
			int u=e.to;
			h[u]=min(h[u],h[v]+e.cost);
		}
	}
//	rep(i,V) printf("h[%d]=%d\n",i,h[i]);
	while(f>0){
		priority_queue< P,vector<P>,greater<P> > que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();
			que.pop();
			int v=p.second;
			if(dist[v]<p.first) continue;
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF) return -1;
		for(int v=0;v<V;v++) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}


void mainmain(){
	int H,W;
	cin>>H>>W;
	vvint vv;
	int off = H*W;
	V = H*W+off+5;
	initvv(vv,H,W);
	int source = H*W+off;
	int sink = H*W+off+1;
	if(H==W && H == 1){
		int t;
		cin>>t;
		cout<<t<<endl;
		return;
	}
	rep(i,H){
		rep(j,W){
			cin>>vv[i][j];
		}
	}
	int ans = vv[0][0] + vv[H-1][W-1];
	vv[0][0] = 0;
	vv[H-1][W-1] = 0;
	rep(i,H){
		rep(j,W){
			int s = i*W+j;
			if(i||j){
				add_edge(i*W+j, i*W+j+off, 1, 0);
				s += off;
			}
			if(i+1<H){
				add_edge(s, i*W+W+j, 1, -vv[i+1][j]), add_edge(s, i*W+W+j, 1, 0);
			}
			if(j+1<W){
				add_edge(s, i*W+j+1, 1, -vv[i][j+1]), add_edge(s, i*W+j+1, 1, 0);
			}
		}
	}
	add_edge(source, 0, 1, -vv[0][0]);
	add_edge(source, 0, 1, 0);
	add_edge(H*W-1, sink, 2, 0);
	cout << -min_cost_flow(source, sink, 2) + ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}