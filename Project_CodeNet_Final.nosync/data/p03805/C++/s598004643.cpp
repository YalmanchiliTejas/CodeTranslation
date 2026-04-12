#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int N,M,Res;
bitset<8> memo;
vector< vector<int> > el;

void dfs(int now) {
	if (memo.count() == N) {
		++Res;
		return;
	}
	for (int i = 0; i < el[now].size(); ++i) {
		if (!memo[el[now][i]]) {
			memo.set(el[now][i]);
			dfs(el[now][i]);
			memo.reset(el[now][i]);
		}
	}
	return;
}

int main(void) {
	cin >> N >> M;
	el = vector< vector<int> >(N);
	for (int i = 0; i < M; ++i) {
		int u,v;
		cin >> u >> v;
		el[u-1].push_back(v-1);
		el[v-1].push_back(u-1);
	}
	Res = 0;
	memo = bitset<8>(1);
	dfs(0);
	cout << Res << endl;
	return 0;
}
