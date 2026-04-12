#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> II;

int n, m, a[10][10];
int S, T, id;
vector<II> vres;

void add(int x, int y, int z) {
	vres.push_back(II(z, ii(x + 1, 200 - y)));
}

bool check(int x, int y, int z) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int tmp = z + x * (i + 1) + y * (j + 1);
			if (tmp < a[i][j]) return 0;
		}
	}
	return 1;
}

void run(int A, int B) {
	for (int x = 0; x <= 100; ++x) for (int y = 0; y <= 100; ++y) {
		int z = a[A][B] - x * (A + 1) - y * (B + 1);
		if (z < 0) continue;
		if (check(x, y, z)) { add(x, y, z); return; } 
	}
	cout << "Impossible"; exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	S = 1, T = 200, id = 200;
	for (int i = 1; i < 100; ++i) vres.push_back(II(-1, ii(i, i + 1)));
	for (int i = 101; i < 200; ++i) vres.push_back(II(-2, ii(i, i + 1)));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			run(i, j);
		}
	}
	sort(vres.begin(), vres.end());
	vres.erase(unique(vres.begin(), vres.end()), vres.end());
	cout << "Possible\n";
	cout << id << ' ' << vres.size() << '\n';
	for (auto i : vres) {
		cout << i.se.fi << ' ' << i.se.se << ' ';
		if (i.fi == -1) cout << "X\n";
		if (i.fi == -2) cout << "Y\n";
		if (i.fi >= 0) cout << i.fi << '\n';
	}
	cout << S << ' ' << T;
}