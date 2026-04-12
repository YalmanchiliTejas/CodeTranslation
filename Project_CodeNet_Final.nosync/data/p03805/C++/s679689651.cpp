#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	bool edge[10][10];
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			edge[i][j] = false;
		}
	}
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		edge[a][b] = true;
		edge[b][a] = true;
	}
	vector<int>v(n);
	v[0] = 1;
	iota(v.begin() + 1, v.end(), 2);
	int ans = 0;
	do {
		bool b = true;
		for (int i = 0;i < n - 1;i++) {
			if (!edge[v[i]][v[i + 1]]) {
				b = false;
			}
		}
		if (b) {
			ans++;
		}
	} while (next_permutation(v.begin() + 1, v.end()));
	cout << ans << endl;
	return 0;
}