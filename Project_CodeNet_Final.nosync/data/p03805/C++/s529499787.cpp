#include <cstdio>
#include <vector>

int n, m;
std::vector<int> g[8];
bool v[8];
int ans;

void check(){
	bool f = true;
	for(int i=0; i<n; ++i) f &= v[i];
	if(f) ++ans;
}

void dfs(int n){
	v[n] = true;
	check();
	for(int i=0; i<g[n].size(); ++i)
		if(!v[g[n][i]])
			dfs(g[n][i]);
	v[n] = false;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	v[0] = true;
	for(int i=0; i<g[0].size(); ++i){
		dfs(g[0][i]);
	}
	printf("%d\n", ans);
}