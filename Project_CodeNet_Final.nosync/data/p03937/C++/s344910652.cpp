#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> have(n + 1);
	vector<vector<char>> a(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			//cout << a[i][j] << ' ';
			if (a[i][j] == '#') {
				have[i].pb(j);
			}
		}
		if (have[i].empty()) {
			cout << "Impossible\n";
			exit(0);
		}
		if (have[i].back() - have[i][0] + 1 != SZ(have[i])) {
			cout << "Impossible\n";
			exit(0);
		}
	}  
	for (int i = 1; i < n; i++) {
		if (have[i].back() != have[i + 1][0]) {
			cout << "Impossible\n";
			exit(0);
		}
	}
	cout << "Possible\n";
} 