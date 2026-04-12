#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
#include <cstring>
typedef long long ll;
typedef long double ld;

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
using Graph = vector<vector<ll>>;
/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
ll H, W;
ll sX, sY, gX, gY;
ll N, M;
bool graph[8][8];
int dfs(ll v,bool visited[8]) {
	bool all_visited = true;
	rep(i,N) {
		if (visited[i]==false) {
			all_visited = false;
		}
	}

	if (all_visited)return 1;

	int ret = 0;
	rep(i,N) {
		if (graph[v][i] == false)continue;
		if (visited[i])continue;

		visited[i] = true;
		ret += dfs(i,visited);
		visited[i] = false;
	}
	return ret;
}


int main() {

	cin >> N >> M;
	rep(i, M) {
		ll tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tmp1--; tmp2--;
		graph[tmp1][tmp2] = graph[tmp2][tmp1] = true;
	}
	bool visited[8];
	rep(i,N) {
		visited[i] = false;
	}
	visited[0] = true;
	cout << dfs(0, visited) << endl;

	return 0;
}