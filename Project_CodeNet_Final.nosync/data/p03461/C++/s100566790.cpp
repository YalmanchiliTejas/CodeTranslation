#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using K = long double;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SIZE(a) ((int)(a).size())

const int N = 15;
const int M = 105;

int n = 204, m;
vector<tuple<int,int,int>> edges; 

int a, b, d[N][N];
int used[N][N];
int was[M][M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;
	for (int i = 1; i <= a; ++i) {
		for (int j = 1; j <= b; ++j) {
			cin >> d[i][j];
		}
	}

	for (int r = 0; r <= 100; ++r) {
		for (int x = 0; x <= 100; ++x) {
			for (int y = 0; y <= 100; ++y) {
				if (was[x][y]) continue;
				int failed = 0;
				for (int i = 1; i <= a; ++i) {
					for (int j = 1; j <= b; ++j) {
						if (r + x*i + y*j < d[i][j]) {
							failed = 1;
							goto fin;
						}
					}
				}
			fin:
				if (!failed) {
					edges.emplace_back(2 + x, 103 + y, r);
					was[x][y] = 1;
					for (int i = 1; i <= a; ++i) {
						for (int j = 1; j <= b; ++j) {
							if (r + x*i + y*j == d[i][j]) {
								used[i][j] = 1;
							}
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= a; ++i) {
		for (int j = 1; j <= b; ++j) {
			if (!used[i][j]) {
				cout << "Impossible\n";
				return 0;
			}
		}
	}

	cout << "Possible\n";

	cout << n << ' ' << SIZE(edges)+202 << '\n';
	cout << 1 << ' ' << 2 << ' ' << 0 << '\n';
	cout << 103 << ' ' << 204 << ' ' << 0 << '\n';
	for (int i = 2; i <= 101; ++i) {
		cout << i << ' ' << i+1 << ' ' << 'X' << '\n';
	}
	for (int i = 103; i <= 202; ++i) {
		cout << i+1 << ' ' << i << ' ' << 'Y' << '\n';
	}
	for (auto& item : edges) {
		int x, y, c;
		tie(x, y, c) = item;
		cout << x << ' ' << y << ' ' << c << '\n';
	}
	cout << 1 << ' ' << 204 << '\n';

	return 0;
}
