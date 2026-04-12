#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, sum = 0;
	cin >> n;
	vector<long long> seq(n);
	vector<vector<long long>> table(n, vector<long long> (n, 0));
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		sum += seq[i];
	}

	int gap, i, j; //for filling table diagonally
	for (gap = 0; gap < n; gap++)
		for (i = 0, j = gap; j < n; i++, j++) {
			long long x = ((i + 2) <= j) ? table[i + 2][j] : 0;
			long long y = ((i + 1) <= j - 1) ? table[i + 1][j - 1] : 0;
			long long z = (i <= j - 2) ? table[i][j - 2] : 0;

			table[i][j] = max(seq[i] + min(x, y), seq[j] + min(y, z));
		}

	cout << 2 * table[0][n - 1] - sum << endl;
}
