#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;

#define int ll
ll grid[302][302], mnx[302][302], mny[302][302];

ll svkek[200][200];

signed main()
{
	fastInp;

	ll a, b;
	cin >> a >> b;


	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) cin >> grid[i][j];
	}

	

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			ll vl = 0, vl2 = 0;
			if (i > 0) vl = grid[i - 1][j];
			if (j > 0) vl2 = grid[i][j - 1];

			if (i > 0) {
				mnx[i - 1][j] = abs(grid[i - 1][j] - grid[i][j]);
			}
			if (j > 0) {
				mny[i][j - 1] = abs(grid[i][j - 1] - grid[i][j]);
			}
		}
	}

	for (int i = a - 1; i >= 0; i--) {
		for (int j = b - 1; j >= 0; j--) {
			if (i > 0) {
				mnx[i - 1][j] = max(mnx[i - 1][j], mnx[i][j]);
				//mny[i - 1][j] = max(mny[i - 1][j], mny[i][j]);
			}
			if (j > 0) {
				mny[i][j - 1] = max(mny[i][j - 1], mny[i][j]);
				//mnx[i][j - 1] = max(mnx[i][j - 1], mnx[i][j]);
			}
		}
	}
	
	ll f = 100;
	ll m = 0, unus = 2, prv = 1;
	vector<tuple<ll, ll, string>> edges;
	for (int i = 0; i < f; i++) {
		edges.push_back({ prv, unus, "X" });
		prv = unus;
		unus++;
	}

	prv = unus;
	unus++;
	for (int i = 0; i < f; i++) {
		edges.push_back({ prv, unus, "Y" });
		prv = unus;
		unus++;
	}

	edges.push_back({ prv, 300, "0" });

	for (int i = 0; i <= f; i++) {
		for (int j = 0; j <= f; j++) {
			ll c = 0;
			for (int t = 0; t < a; t++) {
				for (int k = 0; k < b; k++) {
					c = max(c, grid[t][k] - ((t + 1) * (i) + (k + 1) * (j)));
				}
			}
			svkek[i][j] = c;
			edges.push_back({ i + 1, unus - (j + 1), to_string(c) });
		}
	}

	for (int x = 1; x <= a; x++) {
		for (int y = 1; y <= b; y++) {
			ll z = 10000;
			for (int i = 0; i <= f; i++) {
				for (int t = 0; t <= f; t++) {
					z = min(z, svkek[i][t] + (i * x) + (t * y));
				}
			}
			if (z != grid[x - 1][y - 1]) {
				cout << "Impossible";
				return 0;
			}
		}
	}

	cout << "Possible\n";
	cout << 300 << " " << edges.size() << "\n";

	for (auto cur : edges) {
		cout << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << "\n";
	}

	cout << 1 << " " << 300 << "\n";

	return 0;
}