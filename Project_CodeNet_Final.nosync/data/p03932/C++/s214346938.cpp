#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()
#define INF 1<<28

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

// 辺を表す構造体（行き先、容量、コスト、逆辺）
struct edge{ int to, cap, cost, rev; };

const int MAX_V = 2*200*200+2;

int V; 				// 頂点数
vector<edge> G[MAX_V];		// グラフの隣接リスト表現
int dist[MAX_V];			// 最短距離
int prevv[MAX_V], preve[MAX_V]; 	// 直前の頂点と辺

// from から to へ向かう容量 cap の辺をグラフに追加する
void add_edge(int from, int to, int cap, int cost){
	G[from].push_back((edge){to, cap, cost, G[to].size()});
	G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
}

// s から t への流量 f の最小費用流を求める
// 流せない場合は -1 を返す
int min_cost_flow(int s, int t, int f){
	int res = 0;
	while(f > 0){
		// ベルマンフォード法により、s-t 間の最短路を求める
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool update = true;
		while(update){
			update = false;
			rep(v, V){
				if (dist[v] == INF) continue;
				rep (i, G[v].size()){
					edge &e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost){
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					} // end if
				} // end rep
			} // end rep
		} // end while
		
		if (dist[t] == INF){
			// これ以上流せない
			return -1;
		} // end if
	
		// s-t 間最短路を使って目一杯流す
		int d = f;
		for (int v = t; v != s; v = prevv[v]){
			d = min(d, G[prevv[v]][preve[v]].cap);
		} // end for
		f -= d;
		res += d*dist[t];
		for (int v = t; v != s; v = prevv[v]){
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		} // end for
	} // end whle

	return res;
}

int in[200][200];
int out[200][200];

int main()
{
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H, W; cin >> H >> W;
	vector<vector<int> > a(H, vector<int> (W, 0));
	rep (i, H) rep (j, W) cin >> a[i][j];

	V = 2 * H * W + 2;
	int cnt = 0;
	rep (i, H) rep (j, W) in[i][j] = cnt++;
	rep (i, H) rep (j, W) out[i][j] = cnt++;
	int S = cnt++;
	int T = cnt++;
	
	add_edge(in[0][0], out[0][0], 1, 0);
	add_edge(in[H-1][W-1], out[H-1][W-1], 1, 0);
	rep (i, H){
		rep (j, W){
			add_edge(in[i][j], out[i][j], 1, -a[i][j]);
		} // end rep
	} // end rep
 	rep (i, H){
		rep (j, W){
			if (i + 1 < H){
				add_edge(out[i][j], in[i+1][j], 1, 0);
			} // end if
			if (j + 1 < W){
				add_edge(out[i][j], in[i][j+1], 1, 0);
			} // end if
		} // end rep
	} // end rep

	add_edge(S, in[0][0], 2, 0);
	add_edge(out[H-1][W-1], T, 2, 0);

	int res = -min_cost_flow(S, T, 2);
	cout << res << endl; 

	return 0;
}