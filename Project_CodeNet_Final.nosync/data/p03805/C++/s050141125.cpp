#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> p;
int n, m;
int ans = 0;

void dfs(int state, int pos){
	if(state + 1 == (1<<n)){
		ans++;
		return;
	}
	for(int i = 0; i < n; ++i){
		if((state & (1<<i)) != 0) continue;
		if(p[pos][i] == 1){
			dfs((state | (1<<i)), i);
		}
	}
}


int main(void){
	cin >> n >> m;
	p.resize(n+1);
	for(int i = 0; i <= n; ++i){
		p[i].resize(n+1);
	}
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		a--; b--;
		p[a][b] = 1;
		p[b][a] = 1;
	}
	dfs(1,0);
	cout << ans << endl;
	return 0;
}