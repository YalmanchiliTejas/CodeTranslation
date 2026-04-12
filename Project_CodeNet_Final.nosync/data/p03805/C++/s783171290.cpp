#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> et[8];

int dfs(int v, int used) {
	used |= (1 << v);
	if (used == (1 << n) - 1) return 1;
	int ret = 0;
	for (int i = 0; i < et[v].size(); i++) {
		int nv = et[v][i];
		if ((used >> nv) & 1) continue;
		ret += dfs(nv, used + (1 << nv));
	}
	return ret;
}

int main() {
	int i;
	
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		et[a].push_back(b);
		et[b].push_back(a);
	}
	
	cout << dfs(0, 0) << endl;
	return 0;
}