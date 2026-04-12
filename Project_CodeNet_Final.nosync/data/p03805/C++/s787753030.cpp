#include<iostream>
using namespace std;

int n, m;
int road[8][8];

int dfs(int posi, bool *yet){
	int count = 1;
	for(int i = 0; i < n; ++i){
		count *= yet[i];
	}
	if(count) return 1;
	int ret = 0;
	for(int i = 0; i < n; ++i){
		if(road[posi][i] && !yet[i]){
			yet[i] = 1;
			ret += dfs(i, yet);
			yet[i] = 0;
		}
	}
	return ret;
}

int main(){	
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			road[i][j] = 0;
		}
	}
	for(int i = 0; i < m; ++i){
		int a, b; cin >> a >> b; --a; --b;
		road[a][b] = road[b][a] = 1;
	}
	bool yet[n] = {0};
	yet[0] = 1;
	cout << dfs(0, yet) << endl;
	return 0;
}