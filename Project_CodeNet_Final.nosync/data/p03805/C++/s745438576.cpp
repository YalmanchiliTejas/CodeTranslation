#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <numeric>

#define ll long long
#define ull unsigned long long
using _loop_int = int;
#define rep(i,n) for(_loop_int i=0;i<(_loop_int)(n);i++)
using namespace std;

using Graph = vector<vector<int>>;
Graph G;
int n, m;
int a, b;
vector<bool> seen;
bool check = true;
int ans = 0;
void dfs(const Graph & G, int v) {
	seen[v] = true;
	
	for(int i=1;i<=n;i++) {
		if (seen[i] == false) {
			check = false;
			break;
		}
	}
	if (check) ans++; 
	check = true;
	for (auto next_v : G[v]) {
		if (seen[next_v]) continue;
		dfs(G, next_v);
	}
	seen[v] = false;
}

int main() {
	
	cin >> n >> m;
	Graph G(n+1);
	for (int i = 0; i < m;i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	seen.assign(n+1, false);
	
	dfs(G, 1);
	
	cout<<ans<<endl;

	return 0;
}