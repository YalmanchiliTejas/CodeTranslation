#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int d[10][10] = { 0 };

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		d[a][b] = d[b][a] = 1;
	}
	vector<int> cc;
	for (int i = 2; i <= n; i++) {
		cc.push_back(i);
	}
	long long int ans = 0;
	do {
		bool h = true;
		for (int i = 0; i+1 < cc.size(); i++) {
			if (d[cc[i]][cc[i + 1]] == 0) {
				h = false;
			}
		}
		if (d[1][cc[0]] == 0) {
			h = false;
		}
		if (h) {
			ans++;
		}
	} while (next_permutation(cc.begin(), cc.end()));
	cout << ans << endl;
	return 0;
}