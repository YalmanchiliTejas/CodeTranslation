#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <limits>
#include <climits>
#include <functional>
#include <numeric>

using namespace std;

#define alloc(type,n) (type*)calloc(sizeof(type),(n));
typedef long long lli;

vector<vector<int> >g;
int n,m;
int res = 0;
vector<bool> vis;


void dfs(int p){
	static int dps = 1;
	if(dps == n){
		res++;
		return;
	}
	dps++;
	vis[p] = true;
	for(int i = 0;i < g[p].size();i++){
		if(!vis[g[p][i]]) dfs(g[p][i]);
	}
	vis[p] = false;
	dps--;
	return;
}


int main(){
	cin >> n >> m;
	g = vector<vector<int> >(n+1);
	vis = vector<bool>(n+1);
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	cout << res << endl;

	return 0;
}
