#include <iostream>
#include <vector>
using namespace std;

bool visited[100010];
int dfs(int key, vector<vector<int>> &v){
	visited[key]=1;
	int leaf=0;
	for(int i=0; i<v[key].size(); ++i){
		if(!visited[v[key][i]]){
			int kept=dfs(v[key][i], v);
			if(kept<0) return -1;
			leaf += kept;
		}
	}
	if(leaf>1) return -1;
	return 1-leaf;
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> g(N+1);
	for(int i=1; i<N; ++i){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout << (dfs(1, g) ? "First" : "Second") << endl;
	return 0;
}