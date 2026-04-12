#include <iostream>
#include <vector>
using namespace std;

int n, a[100009], b[100009], col[100009]; bool used[100009]; vector<int>x[100009]; bool flag = false;

int dfs(int pos) {
	int cl = 0, cr = 0;
	used[pos] = true;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i]] == true) continue;
		int F = dfs(x[pos][i]);
		if (F == 0) cl++; else cr++;
	}
	if (cl == 0) {
		if (pos == 1)flag = true;
		col[pos] = 0;
		return 0;
	}
	if (cl >= 2)flag = true;
	col[pos] = 1;
	return 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i] >> b[i];
		x[a[i]].push_back(b[i]);
		x[b[i]].push_back(a[i]);
	}
	dfs(1);
	if (flag == true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}