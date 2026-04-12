#include <bits/stdc++.h>
using namespace std;

const int N = 10;

char mx[N][N];
bool f[N][N];

int main() {
#ifdef HOME
	freopen("agc7a.in", "r", stdin);
	freopen("agc7a.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);	
	int n, m, lx, ly;
	bool flag = true;

	lx = ly = 1e9;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> (mx[i] + 1);
		for (int j = 1; j <= m; ++j) if (mx[i][j] == '#') {
			lx = min(lx, i), ly = min(ly, j); } }

	if (lx == 1e9) {
		cout << "Impossible" << endl;
		return 0; }

	while (true) {
		f[lx][ly] = true;
		if (mx[lx + 1][ly] == '#')
			lx+= 1;
		else if (mx[lx][ly + 1] == '#')
			ly+= 1;
		else
			break; }

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j) if (mx[i][j] == '#')
		flag&= f[i][j];

	cout << (flag ? "Possible" : "Impossible") << endl;		

	return 0; }
