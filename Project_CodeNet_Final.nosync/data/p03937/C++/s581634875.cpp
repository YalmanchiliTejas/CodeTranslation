#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;


void ans(bool c) {
	if (c) {
		cout << "Possible";
	}
	else {
		cout << "Impossible";
	}
}

main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	bool a[n][m];
	bool used[n + 1][m + 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			a[i][j] = (c == '#');
			used[i][j] = 0;
		}
	}
	int l = 0;
	int r = 0;
	used[l][r] = 1;
	while ((l < n && r < m)) {
		if (l < n - 1 && a[l + 1][r]) {
			l++;
		}
		else {
			r++;
		}
		used[l][r] = 1;
	}
	bool prav = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] && !used[i][j]) {
				prav = 1;
			}
		}
	}
	ans(!prav);
}