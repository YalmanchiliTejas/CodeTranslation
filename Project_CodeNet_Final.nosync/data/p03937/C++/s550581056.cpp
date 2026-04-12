// Bismillahirrahmanirrahim
// by Batrrr Tolkynbayev
#include <bits/stdc++.h>
// skripi krasava
#define respa return 0
#define all(x) x.begin(), x.end()
#define sz size
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5 + 17, M = N << 2, mod = 1e9 + 7; 

int tt = 1, n, m;
char a[10][10];
bool used[10][10];

void solve () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	int i = 1, j = 1;
	while (i < n || j < m) {
		used[i][j] = true;
		if (i == n) {++j; continue;}
		if (j == m) {++i; continue;}
		if (a[i + 1][j] == '#') ++i;
		else ++j;
	}
	used[n][m] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if ((a[i][j] == '#' && !used[i][j]) || (a[i][j] == '.' && used[i][j])) {
				cout << "Impossible"; return;
			}
		}
	}
	cout << "Possible";
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}