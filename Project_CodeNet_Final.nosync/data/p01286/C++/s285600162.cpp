#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>
#include <bitset>
#include <cassert>
#include <random>

// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#endif
// END CUT HERE 

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

class MaxFlow{
	struct edge{
		int to, rev, cap;
		edge(){}
		edge(int to, int rev, int cap) :to(to), rev(rev), cap(cap){}
	};
	vector<vector<edge> > Graph;
	vector<int> used, level, iter;
	int V;
	static const int INF = 1 << 30;
public:
	MaxFlow(int size) :V(size){
		Graph.resize(V);
		iter.resize(V, 0);
		level.resize(V);
		used.resize(V, 0);
	}
	void add(int from, int to, int cap){
		Graph[from].push_back(edge(to, Graph[to].size(), cap));
		Graph[to].push_back(edge(from, Graph[from].size() - 1, 0));
	}

	void dinic_bfs(int s){
		fill(level.begin(), level.end(), -1);

		queue<int> q;
		q.push(s);
		level[s] = 0;
		while (!q.empty()){
			int v = q.front(); q.pop();
			for (int i = 0; i < Graph[v].size(); i++){
				edge &e = Graph[v][i];
				if (e.cap <= 0 || level[e.to] >= 0) continue;
				level[e.to] = level[v] + 1;
				q.push(e.to);
			}
		}
	}

	int dinic_dfs(int s, int t, int f){
		if (s == t) return f;
		for (int &i = iter[s]; i < Graph[s].size(); i++){
			edge &e = Graph[s][i];
			if (e.cap <= 0 || level[e.to] <= level[s]) continue;
			int res = dinic_dfs(e.to, t, min(f, e.cap));
			if (res > 0){
				e.cap -= res;
				Graph[e.to][e.rev].cap += res;
				return res;
			}
		}
		return 0;
	}

	int dinic(int s, int t){
		int res = 0;
		while (1){
			dinic_bfs(s);
			if (level[t] < 0) break;
			fill(iter.begin(), iter.end(), 0);
			int f;
			while (f = dinic_dfs(s, t, INF)){
				res += f;
			}
		}
		return res;
	}

	int max_flow(int s, int t){
		return dinic(s, t);
	}
};



int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(12);

	int H, W, C, M, NW, NC, NM;
	while(cin >> H >> W >> C >> M >> NW >> NC >> NM, H + 1){
		const int n = (H + W + C + M + 3);
		const int iNW = n - 3, iNC = n - 2, iNM = n - 1;
		const int SRC = n * 2, SNK = n * 2 + 1;
		MaxFlow mf(n * 2 + 2);

		rep(i, n - 3) mf.add(i, n + i, 1);
		FOR(i, n - 3, n) mf.add(i, n + i, vector<int>({ NW, NC, NM })[i - (n - 3)]);

		// H
		rep(i, H){
			mf.add(SRC, i, 1);
			mf.add(i + n, iNW, 1);
		}
		// W
		FOR(i, H, H + W){
			mf.add(i + n, iNC, 1);
		}
		// C
		FOR(i, H + W, H + W + C){
			mf.add(iNW + n, i, 1);
			mf.add(i + n, iNM, 1);
		}
		// M
		FOR(i, H + W + C, H + W + C + M){
			mf.add(iNC + n, i, 1);
			mf.add(i + n, SNK, 1);
		}
		mf.add(iNM + n, SNK, 1000);

		rep(i, W){
			int t;
			cin >> t;
			while (t--){
				int k;
				cin >> k;
				--k;
				mf.add(k + n, H + i, 1);
			}
		}

		rep(i, C){
			int t;
			cin >> t;
			while (t--){
				int k;
				cin >> k;
				--k;
				mf.add(H + k + n, W + H + i, 1);
			}
		}

		rep(i, M){
			int t;
			cin >> t;
			while (t--){
				int k;
				cin >> k;
				--k;
				mf.add(W + H + k + n, C + W + H + i, 1);
			}
		}

		cout << mf.max_flow(SRC, SNK) << endl;
	}

	return 0;
}