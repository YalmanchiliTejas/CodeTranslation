#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const int INF = (1 << 30) - 1;
const ll INF64 = ((ll)1 << 62) - 1;
const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	vector<string> a(h);
	for (auto &v : a) {
		cin >> v;
	}

	vector<bool> row(w);
	for (int x = 0; x < w; x++) {
		bool res = true;
		for (int y = 0; y < h; y++) {
			if (a[y][x] == '#') {
				res = false;
				break;
			}
		}

		row[x] = res;
	}

	vector<bool> col(h);
	for (int y = 0; y < h; y++) {
		bool res = true;
		for (int x = 0; x < w; x++) {
			if (a[y][x] == '#') {
				res = false;
				break;
			}
		}

		col[y] = res;
	}

	for (int i = 0; i < h; i++) {
		bool isOut = false;
		for (int j = 0; j < w; j++) {
			if (row[j] || col[i]) {
				continue;
			}
			cout << a[i][j];
			isOut = true;
		}

		if (isOut) {
			cout << endl;
		}
	}

	return 0;
}
