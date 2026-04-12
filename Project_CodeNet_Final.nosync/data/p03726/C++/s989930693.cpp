#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int cnt[N], n, v, u;
bool white[N], allchild[N], ans = false;
vector<int> g[N];

void dfs(int v, int p){
	for (int u : g[v])
		if(u != p)
			dfs(u, v);
	cnt[v] = 1;
	for (int u : g[v])
		if(u != p)
			cnt[v] += cnt[u];
	if(cnt[v] % 2 == 0)
		white[v] = true;
	bool f = true;
	for (int u : g[v])
		if(u != p)
			if(!white[u])
				f = false;
	allchild[v] = f;
	
	int c = 0;
	for (int u : g[v])
		if(u != p)
			c += allchild[u];
	if(c >= 2)
		ans = true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	for (int i = 0; i + 1 < n; i++){
		cin >> v >> u;
		v--;u--;
		
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	dfs(0, 0);
	
	if(allchild[0])
		return cout << "First", 0;
	int c = 0;
	for (int u : g[0])
		c += allchild[u];
	if(ans)
		return cout << "First", 0;
		
	cout << "Second";
	return 0;
}