#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int ok = 1;
vector<int> edges[110000];
int dfs(int a, int p){
	int ans = 0;
	for(int j = 0; j < edges[a].size(); j++){
		if(edges[a][j] == p) continue;
		ans += dfs(edges[a][j],a);
	}
	if(ans > 1){
		ok = 0;
		return 0;
	}
	return 1-ans;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	if(dfs(0,-1) == 1) ok = 0;
	cout << (ok ? "Second" : "First") << endl;
}