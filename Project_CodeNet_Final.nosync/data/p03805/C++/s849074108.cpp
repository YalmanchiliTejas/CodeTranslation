#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <utility> 

#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;


bool graph[8][8];


int dfs(int v, int n, bool visited[8]) {
	bool all_visited = true;
	rep(i, 0, n) {
		if (visited[i] == false)
			all_visited = false;
	}

	if (all_visited)return 1;


	int ret=0;
	rep(i, 0, n) {
		if (visited[i] == true)continue;
		if (graph[v][i] == false)continue;

		visited[i] = true;
		ret += dfs(i,n,visited);
		//次の頂点に移る前にvisitedを初期化
		visited[i] = false;
	}

	return ret;

}


int main(){
	int n, m;
	cin >> n >> m;

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}

	bool visited[8];
	rep(i, 0, n)visited[i] = false;

	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;
}

