#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> g(9);
bool vi[9];

int dfs(int p = 1, int d = 1){
	if(d == n) return 1;
	vi[p] = true;
	int cnt = 0;
	for(int i = 0; i < g[p].size(); i++){
		if(!vi[g[p][i]]){
			cnt += dfs(g[p][i], d + 1);
		}
	}
	vi[p] = false;
	return cnt;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout << dfs() << endl;
	return 0;
}