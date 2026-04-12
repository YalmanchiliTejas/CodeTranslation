#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>>path(n,vector<int>(n,0));
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		path[a - 1][b - 1] = 
		path[b - 1][a - 1] = 1;
	}

	vector<int>g; for (int i = 0; i < n - 1; i++)g.push_back(i + 1);
	
	int ans = 0;
	do {
		bool ok = true;
		int now = 0;
		for (int i = 0; i < n - 1; i++) {
			if (!path[now][g[i]])ok = false;
			now = g[i];
		}
		if (ok)ans++;
	} while (next_permutation(g.begin(), g.end()));
	cout << ans << endl;

	return 0;
}