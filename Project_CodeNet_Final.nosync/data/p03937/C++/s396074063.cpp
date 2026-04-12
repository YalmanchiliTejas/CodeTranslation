#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

string a[10];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
	int h, w;
	cin >> h >> w;
	rep (i, h) cin >> a[i];

	bool ok = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.') continue;
			bool le = false, ri = false, up = false, dw = false;
			rep (k, 4) {
				int x = dx[k] + j;
				int y = dy[k] + i;
				if (x < 0 || x >= w || y < 0 || y >= h) continue;
				if (a[y][x] == '.') continue;
				if (k == 0) ri = true;
				if (k == 1) le = true;
				if (k == 2) dw = true;
				if (k == 3) up = true;
			}
			if (!i && !j) {if (!ri && !dw || ri && dw) ok = false;}
			else if (i == h - 1 && j == w - 1) {if (le && up || !le && !up) ok = false;}
			else {if ((le && up) || (!le && !up) || (ri && dw) || (!ri && !dw)) ok = false;}
		}
	}

	cout << (ok ? "Possible" : "Impossible") << endl;
 	return 0;
}