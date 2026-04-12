#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, sum = 0;
	cin >> n >> m;
	vector<vector<char>> arr(n + 2, vector<char>(m + 2, '.'));

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '#')
				sum++;
		}
	if (sum == m + n - 1) {
		cout << "Possible\n";
	} else
		cout << "Impossible\n";

	return 0;

}
