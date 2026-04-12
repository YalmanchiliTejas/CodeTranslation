#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}




typedef int Weight;
const Weight INF=99999999;
struct Edge{
	int src,dst;
	Weight weight;
	int rev;
	Edge(int f, int t, Weight c,int rev=0):src(f),dst(t),weight(c),rev(rev){}
};
typedef vector< vector<Edge> > Graph;

void add_edge(Graph &G,int s,int t,Weight cap){
	G[s].push_back(Edge(s,t,cap,G[t].size()));
	G[t].push_back(Edge(t,s,0,G[s].size()-1));
}


void bfs(const Graph &G,vector<int> &level,int s){
	level[s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		REP(i,G[v].size()){
			const Edge &e=G[v][i];
			if(e.weight>0 && level[e.dst] < 0){
				level[e.dst] = level[v] +1;
				que.push(e.dst);
			}
		}
	}
}
Weight dfs(Graph &G,vector<int> &level,vector<int> &iter,int v,int t,Weight flow){
	if(v==t)return flow;
	for(int &i=iter[v];i<(int)G[v].size();i++){
		Edge &e=G[v][i];
		if(e.weight>0&&level[v]<level[e.dst]){
			Weight d=dfs(G,level,iter,e.dst,t,min(flow,e.weight));
			if(d>0){
				e.weight-=d;
				G[e.dst][e.rev].weight+=d;
				return d;
			}
		}
	}
return 0;
}

// Dinic
// O(EV^2)
Weight max_flow(Graph &G,int s,int t){
	Weight flow = 0;
	while(true){
		vector<int> level(G.size(),-1);
		vector<int> iter(G.size(),0);
		bfs(G,level,s);
		if(level[t]<0)break; // もう流せない
		Weight f=0;
		while((f=dfs(G,level,iter,s,t,INF))>0){
			flow+=f;
		}
	}
	return flow;
}



int H, W, C, M, NW, NC, NM, x, y;

int main(){
	ios::sync_with_stdio(false);
	while(cin >> H >> W >> C >> M >> NW >> NC >> NM, H >= 0){
		Graph g(H+2*W+2*C+M+7);
		const int t = g.size() - 1;
		const int s = g.size() - 2;
		const int nw = g.size() - 4;
		const int nc = g.size() - 6;
		const int nm = g.size() - 7;
		const int h = 0;
		const int w = H;
		const int c = w+2*W;
		const int m = c+2*C;
		REP(i, H) add_edge(g, s, h+i, 1);
		REP(i, H) add_edge(g, h+i, nw, 1);
		REP(i, W) add_edge(g, w+W+i, nc, 1);
		REP(i, W) add_edge(g, w+i, w+W+i, 1);
		REP(i, C) add_edge(g, nw+1, c+i, 1);
		REP(i, C) add_edge(g, c+i, c+C+i, 1);
		REP(i, C) add_edge(g, c+C+i, nm, 1);
		REP(i, M) add_edge(g, nc+1, m+i, 1);
		REP(i, M) add_edge(g, m+i, t, 1);
		add_edge(g, nw, nw+1, NW);
		add_edge(g, nc, nc+1, NC);
		add_edge(g, nm, t, NM);
		REP(i, W){
			cin >> x;
			REP(j, x){
				cin >> y;y --;
				add_edge(g, h+y, w+i, 1);
			}
		}
		REP(i, C){
			cin >> x;
			REP(j, x){
				cin >> y;y --;
				add_edge(g, w+W+y, c+i, 1);
			}
		}
		REP(i, M){
			cin >> x;
			REP(j, x){
				cin >> y;y --;
				add_edge(g, c+C+y, m+i, 1);
			}
		}
		int ans;
		cout << max_flow(g, s, t) << endl;
	}
	return 0;
}