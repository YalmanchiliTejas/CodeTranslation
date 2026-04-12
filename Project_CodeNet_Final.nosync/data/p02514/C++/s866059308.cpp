#define _USE_MATH_DEFINES
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <cmath>
#include <math.h>
#include <numeric>
#include <list>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <set>
#include <memory.h>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <map>
#include <cassert>
#include <time.h>

using namespace std;

typedef complex<double> Point;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int , P> PP;
typedef pair<int, PP> PPP;
typedef pair<double, Point> P2;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF= 1 << 30;
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;

double dis(Point p1, Point p2){
	return sqrt((p1.real() - p2.real())*(p1.real()-p2.real()) + (p1.imag() - p2.imag())*(p1.imag() - p2.imag()));
}

struct edge{
	int to;
	int cap;
	int rev;
	edge(){};
	edge(int to, int cap, int rev){
		this->to = to;
		this->cap = cap;
		this->rev = rev;
	};
};


vector<edge> G[200];
vector<edge> G2[200];
int level[200];
int iter[200];

void add_edge(int from, int to, int cap, vector<edge> *G){
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(to, cap, G[to].size()));
}

void rem_edge(int s, int t){
	G[s].pop_back();
	G[t].pop_back();
}

void bfs(int s){
	memset(level, -1, sizeof(level));
	queue<int> que;
	que.push(s);
	level[s] = 0;
	while(!que.empty()){
		int v = que.front(); que.pop();
		for(int i = 0; i < G[v].size(); i++){
			edge &e = G[v][i];
			if(e.cap > 0 && level[e.to] < 0){
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f){
	if(v == t) return f;
	for(int &i = iter[v]; i < G[v].size(); i++){
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
	for(;;){
		bfs(s);
		if(level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while((f = dfs(s, t, INF)) > 0){
			flow += f;
		}
	}
}

int main(){
	int n, m;
	while(cin >> n >> m && (n || m)){
		for(int i = 0; i < 200; i++) G2[i].clear();
		int res = 0;
		for(int i = 0; i < m; i++){
			int x, y, c;
			cin >> x >> y >> c;
			if(c < 0) res += c;
			else{
				add_edge(x, y, c, G2);
				add_edge(y, x, c, G2);
			}
		}
		int s = n;
		int t = s + 1;
		add_edge(s, 0, INF, G2);
		int f = INF;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < t + 1; j++){
				G[j].clear();
				for(int k = 0; k < (int)G2[j].size(); k++) G[j].push_back(G2[j][k]);
			}
			add_edge(i, t, INF, G);
			f = min(f, max_flow(s, t));
		}
		cout << res + f << endl;
	}
	return 0;
}