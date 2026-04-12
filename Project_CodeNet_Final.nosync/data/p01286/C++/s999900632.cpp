#include <stdio.h>
#include <math.h>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) cerr << #x << "=" << static_cast<bitset<16> >(x) << endl;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))

const int INF = 100000000;
typedef double D;
const double EPS = 1e-8;
const double PI = 3.14159;
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
using namespace std;
typedef pair<int, int> P;

/** Problem2168 : Luigi's Tavern **/
const int MAX_V = 1000;

class MaxFlow {
public:
	struct edge { int to, cap, rev, cost;};
	vector<edge> G[MAX_V];
	bool used[MAX_V];
	int V;
	
	MaxFlow() {V=MAX_V;}
	MaxFlow(int v) {
		V = v;
	}
	
	void add_edge(int from, int to, int cap) {
		G[from].push_back((edge){to, cap, (int)G[to].size(), 0});
		G[to].push_back((edge){from, 0, (int)G[from].size()-1, 0});
	}
	
	// 最大流
	int dfs(int v, int t, int f) {
		if (v==t) return f;
		used[v] = true;
		for (int i=0; i<G[v].size(); i++) {
			edge &e = G[v][i];
			if (!used[e.to] && e.cap>0) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d>0) {
					e.cap-=d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	
	int max_flow(int s, int t) {
		int flow = 0;
		for (;;) {
			memset(used, 0, sizeof(used));
			int f = dfs(s, t, INF);
			if (f==0) return flow;
			flow += f;
		}
	}
};

int main()
{
	int H, W, C, M, Nw, Nc, Nm;
	while (cin>>H>>W>>C>>M>>Nw>>Nc>>Nm) {
		if (H<0&&W<0&&C<0&&M<0&&Nw<0&&Nc<0&&Nm<0) break;
		
		int s=H+2*W+2*C+2*M, t=s+1, nw=t+1, nc=nw+2, nm=nc+2;
		
		MaxFlow F(H+2*W+2*C+2*M+8);
		
		rep(i, H) {
			// s->H
			F.add_edge(s, i, 1);

			// H -> Nw
			F.add_edge(i, nw, 1);
			
		}
		
		rep(i, W) {
			int a; cin>>a;
			rep(j, a) {
				int b; cin>>b; b--;
				// 親しいH, W
				F.add_edge(b, H+i, 1);
			}
			// W同士
			F.add_edge(H+i, H+W+i, 1);
			// W->Nc
			F.add_edge(H+W+i, nc, 1);

		}
		rep(i, C) {
			int a; cin>>a;
			rep(j, a) {
				int b; cin>>b; b--;
				// 親しいW, C
				F.add_edge(H+W+b, H+2*W+i, 1);
			}
			
			// C同士
			F.add_edge(H+2*W+i, H+2*W+C+i, 1);
			
			// Nw+1 -> C
			F.add_edge(nw+1, H+2*W+i, 1);
			// C -> Nm
			F.add_edge(H+2*W+C+i, nm, 1);
		}
		
		rep(i, M) {
			int a; cin>>a;
			rep(j, a) {
				int b; cin>>b; b--;
				// 親しいC, M
				F.add_edge(H+2*W+C+b, H+2*W+2*C+i, 1);
			}
			// M同士
			F.add_edge(H+2*W+2*C+i, H+2*W+2*C+M+i, 1);
			// Nc+1->M
			F.add_edge(nc+1, H+2*W+2*C+i, 1);
		}
				
		rep(i, M) {
			F.add_edge(H+2*W+2*C+M+i, t, 1);
		}
		
		F.add_edge(nw, nw+1, Nw);
		F.add_edge(nc, nc+1, Nc);
		F.add_edge(nm, nm+1, Nm);
		F.add_edge(nm+1, t, Nm);
		
		cout << F.max_flow(s, t) << endl;
	}
}