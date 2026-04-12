#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> II;
#define fi first
#define se second

const int N = 550;

int A, B;
int n, S, T;
int nx[N][N], ny[N][N];
int a[N][N];

bool check(int x, int y, int ni, int nj) {
	int rem = a[x][y] - ni * x - nj * y;
	if (rem < 0) return false;

	for (int i = 1; i <= A; ++i) for (int j = 1; j <= B; ++j) {
		if (rem + ni * i + nj * j < a[i][j]) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> A >> B;
	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) cin >> a[i][j], nx[i][j] = -1, ny[i][j] = -1;
	}	

	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			for (int ni = 0; ni <= 100; ++ni) for (int nj = 0; nj <= 100; ++nj) {
				if (check(i, j, ni, nj)) {
					nx[i][j] = ni, ny[i][j] = nj; break;
				}
			}
		}
	}

	S = ++n;
	T = ++n;
	vector<II> X, Y, edges;

	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			if (nx[i][j] == -1 || ny[i][j] == -1) return cout << "Impossible\n", 0;
			int rem = a[i][j] - nx[i][j] * i - ny[i][j] * j;

			int lastS = S;
			for (int k = 0; k < min(nx[i][j], (int)X.size()); ++k) {
				edges.push_back(X[k]);
				lastS = X[k].se.se;
			}
			nx[i][j] -= X.size();
			while (nx[i][j]-- > 0) {
				++n; X.push_back(II(-1, ii(lastS, n))); lastS = n;
				edges.push_back(X.back());
			}


			int lastT = T;
			for (int k = 0; k < min(ny[i][j], (int)Y.size()); ++k) {
				edges.push_back(Y[k]);
				lastT = Y[k].se.fi;
			}
			ny[i][j] -= Y.size();
			while (ny[i][j]-- > 0) {
				++n; Y.push_back(II(-2, ii(n, lastT))); lastT = n;
				edges.push_back(Y.back());
			}

			edges.push_back(II(rem, ii(lastS, lastT)));
		}
	}

	assert(n <= 300);

	sort(edges.begin(), edges.end());
	edges.erase(unique(edges.begin(), edges.end()), edges.end());
	cout << "Possible\n";
	cout << n << ' ' << edges.size() << endl;
	for (auto e : edges) {
		cout << e.se.fi << ' ' << e.se.se << ' ';
		if (e.fi < 0) cout << (e.fi == -1 ? 'X' : 'Y') << endl;
		else cout << e.fi << endl;
	}
	cout << S << ' ' << T << endl;
}