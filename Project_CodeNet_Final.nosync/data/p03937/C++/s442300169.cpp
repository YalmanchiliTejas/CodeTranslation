/* it was worth becoming a chemist */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned int uni;
typedef unsigned long long unll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define NAME "puts"
#define F first
#define S second

const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const db EPS = (db) 1e-9;
const db pi = acos(-1.0);
const int MAXN = 2e5 + 5;

int n, m;
char a[12][12];
bool used[12][12];

bool f(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) {
		if (a[x][y] == '#' && used[x][y] == 0) return 1;
		else return 0;
	}
	else return 0;
}

void rec(int x, int y) {
	
	used[x][y] = 1;
	if (f(x + 1, y)) {
		rec(x + 1, y);
		return;
	}
	if (f(x, y + 1)) {
		rec(x, y + 1);
		return;
	}
}

int main() {	

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	rec(1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '#' && used[i][j] == 0) {
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible";
	return 0;
}
