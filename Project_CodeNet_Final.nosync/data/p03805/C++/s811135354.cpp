#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <memory.h>



using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,n) for(int i=0;i<(int)n;++i)
#define FORNUM(p, x) for (int num = p; num < (int)(x); ++num)
#define FORI(p, x) for (int i = p; i < (int)(x); ++i)
#define FORJ(p, x) for (int j = p; j < (int)(x); ++j)
#define FORK(p, x) for (int k = p; k < (int)(x); ++k)
#define FORL(p, x) for (int l = p; l < (int)(x); ++l)

typedef pair<int,int>P;
#define INF 1000000000
 
struct edge { 
	int from, to; 
	edge (int from, int to){
		this->from=from; this->to=to;
	}
};
 
int V,E;
typedef vector<edge> edges;
//vector<edges> G;

vector<int> G[10];
int n, m;
bool visit[10];

int dfs(int v, int num) {
	if (num == n) {
		return 1;
	}
	int ans = 0;
	for (auto u : G[v]) {
		if (visit[u] == 0) {
			visit[u] = 1;
			ans += dfs(u, num + 1);
			visit[u] = 0;
		}
	}
	return ans;
}

int main(){
	cin >> n >> m;
	FORI(0, m) {
		int u, v;
		cin >> u >> v; u--; v--;

		G[u].push_back(v);
		G[v].push_back(u);
	}
	visit[0] = 1;
	int ans = dfs(0, 1);
	cout << ans << endl;
	return 0;
}
