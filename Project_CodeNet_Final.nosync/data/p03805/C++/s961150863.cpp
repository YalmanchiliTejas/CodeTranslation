#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> path;
	path = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		path[a][b]++;
		path[b][a]++;
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}

	int cnt = 0;

	do {
		for (int i = 0; i < n-1; i++) {
			if (!path[v[i]][v[i + 1]])
				break;
			if (i == n - 2) {
				cnt++;
			}
		}
	} while (next_permutation(v.begin(), v.end()) && v[0] == 0);

	cout << cnt << endl;

}