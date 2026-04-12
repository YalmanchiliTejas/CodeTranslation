/*
これを入れて実行
g++ code.cpp
./a.out
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

int n, m;

vector<int> g[10];

int seen[10] = {0};


int dfs(int now, int counter){
	if(counter >= n - 1){
		return 1;
	}

	seen[now] = 1;

	int ret = 0;

	for(int i = 0; i < g[now].size(); i++){

		int next = g[now][i];
		if(seen[next] == 1) continue;

		ret += dfs(next, counter + 1);

	}
	seen[now] = 0;

	return ret;
}


int main(void){
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tmp1--;
		tmp2--;
		g[tmp1].push_back(tmp2);
		g[tmp2].push_back(tmp1);
	}

	cout << dfs(0, 0) << endl;

}

