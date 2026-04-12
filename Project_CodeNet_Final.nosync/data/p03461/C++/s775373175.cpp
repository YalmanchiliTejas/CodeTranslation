#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

void f(int u, int v, int w) {
	if (w == -1)
		cout << u + 1 << ' ' << v + 1 << ' ' << 'X' << endl;
	else if (w == -2)
		cout << u + 1 << ' ' << v + 1 << ' ' << 'Y' << endl;
	else
		cout << u + 1 << ' ' << v + 1 << ' ' << w << endl;
}

int main() {
	int X, Y; cin >> X >> Y;
	vector<vector<int>> a(X + 1, vector<int>(Y + 1));
	for (int x = 1; x <= X; x++)
		for (int y = 1; y <= Y; y++)
			cin >> a[x][y];
	vector<vector<int>> l(101, vector<int>(101));
	rep(i, 101) rep(j, 101) {
		int ma = 0;
		for (int x = 1; x <= X; x++)
			for (int y = 1; y <= Y; y++)
				ma = max(ma, a[x][y] - i * x - j * y);
		l[i][j] = min(ma, 100);
	}
	for (int x = 1; x <= X; x++)
		for (int y = 1; y <= Y; y++) {
			int mi = INF;
			rep(i, 101) rep(j, 101)
				mi = min(mi, i * x + j * y + l[i][j]);
			if (mi != a[x][y]) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	cout << "Possible" << endl;
	cout << 202 << ' ' << 10401 << endl;
	rep(i, 100) f(i, i + 1, -1);
	rep(j, 100) f(101 + j, 101 + j + 1, -2);
	rep(i, 101) rep(j, 101) f(i, 201 - j, l[i][j]);
	cout << 1 << ' ' << 202 << endl;
}
