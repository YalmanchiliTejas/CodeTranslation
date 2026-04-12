#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;

#define size(s) (int) (s).size()
#define all(s) (s).begin(), (s).end()
#define rall(s) (s).rbegin(), (s).rend()

const int INF = 1e9;

int n, m;

bool check(int v, int u) {
	return v >= 0 && v < n && u >= 0 && u < m;
}

int main() {
	ios::sync_with_stdio(0);

	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("", "r", stdin);
	// freopen("", "w", stdout);
	
	cin >> n >> m;

	vector<vector<int> > a(n, vector<int> (m, 0)), was = a;
	queue<pair<int, int> > q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char z;
			cin >> z;
			if (z == '#') {
				a[i][j] = 1;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (a[i][j - 1] == 1 && a[i - 1][j] == 1) {
				cout << "Impossible\n";
				return 0;
			}
		}
	}

	int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

	q.push({0, 0});

	while (!q.empty()) {
		int v = q.front().first, u = q.front().second;
		was[v][u] = 1;
		a[v][u] = 0;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nv = v + dx[i], nu = u + dy[i];
			if (check(nv, nu) && a[nv][nu]) {
				q.push({nv, nu});
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				cout << "Impossible\n";
				return 0;
			}
		}
	}

	if (was[n - 1][m - 1]) {
		cout << "Possible\n";
	} else {
		cout << "Impossible\n";
	}

	return 0;
}
