#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<iomanip>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const int INF = 1e9 + 7;
vector<vector<bool>> path(10, vector<bool>(10, false));
//与えられたグラフの隣接行列
//path[a][b]=true<=>a-b間に辺がある
int N, M;
int ans = 0;
int vcount = 0;//いくつの頂点を訪れたかを記録する
vector<bool>visited(10, false);//各頂点に訪れたかを記録する

void dfs(int from) {
	visited[from] = true;
	vcount++;
	if (vcount == N) {
		ans++;
	}
	else {
		for(int i = 1; i <= N; ++i) {
			if (!visited[i] && path[from][i]) {
				dfs(i);
			}
		}
	}
	visited[from] = false;
	vcount--;
	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		path[a][b] = path[b][a] = true;
	}
	dfs(1);
	cout << ans << endl;
    return 0;
}