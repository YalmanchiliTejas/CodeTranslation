#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

struct flowGraph{
	struct edge{ int to, cap, rev; };
	
	int n, *level, *iter;
	vector<vector<edge> > G;
	
	flowGraph(int sz) : n(sz){
		G.resize(n);
		iter = new int[n]; level = new int[n];
	}
	~flowGraph(){
		delete iter; delete level;
	}
	
	void add(int s, int t, int cap){
		G[s].pb((edge){t, cap, G[t].size()});
		G[t].pb((edge){s, 0, G[s].size() - 1});
	}
	void bfs(int s){
		rep(i, n) level[i] = -1;
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while(!q.empty()){	
			int v = q.front();
			q.pop();
			rep(i, G[v].size()){
				edge &e = G[v][i];
				if(e.cap > 0 && level[e.to] < 0){
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f){
		if(v == t) return f;
		for(int &i = iter[v]; i < (int)G[v].size(); i++){
			edge &e = G[v][i];
			if(e.cap > 0 && level[v] < level[e.to]){
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t){
		int flow = 0;
		while(1){
			bfs(s);
			if(level[t] < 0) return flow;
			rep(i, n) iter[i] = 0;
			int f;
			while((f = dfs(s, t, inf)) > 0) flow += f;
		}
	}
};
int h, w, c, m, nw, nc, nm;

int main(){
	while(cin >> h >> w >> c >> m >> nw >> nc >> nm, h >= 0){
		int p = (h + w + c + m) * 2, s = p + 6, t = p + 7;
		int W = 2 * h, C = 2 * (h + w), M = 2 * (h + w + c);
		
		flowGraph g(t + 1);
		rep(i, h) g.add(s, 2 * i, 1), g.add(2 * i, p, 1), g.add(2 * i, 2 * i + 1, 1);
		rep(i, w){
			int k, l;
			cin >> k;
			rep(j, k){
				cin >> l;
				g.add(2 * (l - 1) + 1, W + 2 * i, 1);
			}
			g.add(W + 2 * i, W + 2 * i + 1, 1);
			g.add(W + 2 * i + 1, p + 2, 1);
		}
		rep(i, c){
			int k, l;
			cin >> k;
			rep(j, k){
				cin >> l;
				g.add(2 * (l - 1) + 1 + W, C + 2 * i, 1);
			}
			g.add(C + 2 * i, C + 2 * i + 1, 1);
			g.add(C + 2 * i + 1, p + 4, 1);
			g.add(p + 1, C + 2 * i, 1);
		}
		rep(i, m){
			int k, l;
			cin >> k;
			rep(j, k){
				cin >> l;
				g.add(C + 2 * (l - 1) + 1, M + 2 * i, 1);
			}
			g.add(M + 2 * i, M + 2 * i + 1, 1);
			g.add(p + 3, M + 2 * i, 1);
			g.add(M + 2 * i + 1, t, 1);
		}
		g.add(p, p + 1, nw);
		g.add(p + 2, p + 3, nc);
		g.add(p + 4, t, nm);
		cout << g.max_flow(s, t) << endl;
	}
	return 0;
}