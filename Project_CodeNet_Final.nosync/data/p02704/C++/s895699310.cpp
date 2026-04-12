#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
inline void read (int &x) {
	char ch = getchar(); int f = 0; x = 0;
	while (!isdigit(ch)) { if (ch == '-') f = 1; ch = getchar(); }
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); if (f) x = -x;
} const int N = 538; vector<int> a, b;
int n, s[N], t[N], u[N], v[N], res[N][N], num[N][N], ca[N], cb[N];
signed main() {
	read (n); 
	for (int i = 1; i <= n; ++i) read (s[i]);
	for (int i = 1; i <= n; ++i) read (t[i]);
	for (int i = 1; i <= n; ++i) read (u[i]);
	for (int i = 1; i <= n; ++i) read (v[i]);
	for (int i = 1; i <= n; ++i) {
		if (!s[i]) a.push_back (i);
		if (!t[i]) b.push_back (i);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (s[i] == 0 and t[j] == 0) num[i][j] = u[i] | v[j]; 
			else if (s[i] == 1 and t[j] == 1) num[i][j] = u[i] & v[j];
			else if (s[i] == 0) num[i][j] = u[i]; else num[i][j] = v[j];
		}
	srand (19260817);
	for (int T = 1; T <= 800; ++T) {
		bool ok = 1; //srand (T * time(NULL)); 
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) res[i][j] = num[i][j];
		for (int i = 1; i <= n; ++i) {
			if (!s[i]) continue;
			int tmp = 0;
			for (int j = 1; j <= n; ++j) tmp |= res[i][j];
			int qwq = u[i] - (u[i] & tmp); 
			while (qwq) {
				int m = qwq & (-qwq);
				if (b.size()) {
					int w = rand() % b.size();
					res[i][b[w]] |= m;
				} qwq -= m;
			}
		} for (int i = 1; i <= n; ++i) {
			if (!t[i]) continue;
			int tmp = 0;
			for (int j = 1; j <= n; ++j) tmp |= res[j][i];
			int qwq = v[i] - (v[i] & tmp); 
			while (qwq) {
				int m = qwq & (-qwq);
				if (a.size()) {
					int w = rand() % a.size();
					res[a[w]][i] |= m;
				} qwq -= m;
			}
		} for (int i = 1; i <= n; ++i) {
			if (s[i]) {
				int tmp = 0;
				for (int j = 1; j <= n; ++j) tmp |= res[i][j];
				if (tmp != u[i]) { ok = 0; break; }
			} else {
				int tmp = res[i][1];
				for (int j = 2; j <= n; ++j) tmp &= res[i][j];
				if (tmp != u[i]) { ok = 0; break; }
			}
		} for (int i = 1; i <= n; ++i) {
			if (t[i]) {
				int tmp = 0;
				for (int j = 1; j <= n; ++j) tmp |= res[j][i];
				if (tmp != v[i]) { ok = 0; break; }
			} else {
				int tmp = res[1][i];
				for (int j = 2; j <= n; ++j) tmp &= res[j][i];
				if (tmp != v[i]) { ok = 0; break; }
			}
		} if (!ok) continue;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) cout << res[i][j] << ' '; puts ("");
		} return 0;
	} return puts ("-1"), 0;
}
