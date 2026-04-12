#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n, m;
	bool adj[8][8] = {};

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a][b] = adj[b][a] = true;
	}

	int ans = 0;
	int vertices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	do {
		int i;
		for (i = 0; i < n - 1; i++)
			if (!adj[vertices[i]][vertices[i + 1]])
				break;
		ans += i == n - 1;
	} while (next_permutation(vertices + 1, vertices + n));

	cout << ans << endl;

	return 0;
}
