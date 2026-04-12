#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ans, c[10][10], order[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		c[a][b] = 1;
		c[b][a] = 1;
	}

	for (int i = 0; i < n; i++) {
		order[i] = i+1;
	}

	do {
		bool valid = (order[0] == 1);
		for (int i = 0; i < n-1; i++) {
			if (!c[order[i]][order[i+1]]) {
				valid = 0;
			}
		}

		if (valid) {
			ans++;
		}
	} while (next_permutation(order, order+n));

	cout << ans << '\n';
	
	return 0;
}