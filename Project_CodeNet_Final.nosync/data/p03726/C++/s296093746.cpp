#include<bits/stdc++.h>
using namespace std;
 
const int N = 100010;
 
std::vector <int> e[N];
int n;
 
int dfs(int u, int fa){
	int cnt = 0;
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		if (dfs(v, u)){
			++ cnt;
		}
	}
	if (cnt >= 2){
		printf("First\n");
		exit(0);
	}
	return !cnt;
}
 
int main(){
	scanf("%d", &n);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	return printf(dfs(1, 0) ? "First\n" : "Second\n"), 0;
}