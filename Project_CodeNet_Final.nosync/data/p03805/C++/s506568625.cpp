#include <iostream>
#include <vector>
#include <algorithm>

#define NMAX 8

using namespace std;

vector<vector<int>> a(NMAX);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		a[x].emplace_back(y);
		a[y].emplace_back(x);
	}

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = i;
	}

	int ans = 0;
	do {
		if (b[0] != 0) {
			break;
		}

		bool ok = true;
		for (int i = 0; i < n - 1; i++) {
			if (find(a[b[i]].begin(), a[b[i]].end(), b[i + 1]) == a[b[i]].end()) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans++;
		}
	} while (next_permutation(b.begin(), b.end()));
	cout << ans << endl;

	return 0;
}