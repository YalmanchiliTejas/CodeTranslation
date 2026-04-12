#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> G[100005];

int dfs(int v, int prev)
{
	int res, ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		res = dfs(G[v][i], v);
		if(res == -1) return -1;
		ret += res;
	}
	if(ret >= 2) return -1;
	if(ret == 1) return 0;
	if(ret == 0) return 1;
}

int main(void)
{
	cin >> N;
	int a, b;
	for(int i = 0; i < N-1; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	if(dfs(1, -1)){
		cout << "First" << endl;
	}
	else{
		cout << "Second" << endl;
	}
	
	return 0;
}