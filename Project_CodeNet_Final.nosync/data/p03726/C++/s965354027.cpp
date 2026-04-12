#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define maxn 100009
using namespace std;
vector<int>G[maxn];
int n;
int d[maxn];
bool ok = 0;
void dfs(int u, int fa){
	int cnt = 0;
	d[u] = 1;
	for(auto v : G[u]){
		if(v == fa)
			continue;
		dfs(v, u);
		d[u] += d[v];
		if(d[v] & 1)
			cnt++;
	}
	if((n - d[u]) & 1)
		cnt++;
	if(cnt >= 2)
		ok = 1;
}

int main(){
	scanf("%d", &n);
	for(int i =1 ; i < n ;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(n & 1){
		puts("First");
		return 0;
	}
	dfs(1, -1);
	if(ok)
		puts("First");
	else
		puts("Second");
	return 0;
}