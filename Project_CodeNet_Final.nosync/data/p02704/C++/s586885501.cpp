#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
#define rep(i,n) for(int i=0;i<n;i++)

int ans[500][500][64];
ul out[500][500];
void solve() {
	int n; cin >> n;
	vector<int> s(n),u(n);
	vector<ul> t(n),v(n);
	rep(i, n)cin >> s[i];
	rep(i, n)cin >> u[i];
	rep(i, n)cin >> t[i];
	rep(i, n)cin >> v[i];
	rep(i, 64) {
		vector<int> h(n), w(n);
		vector<bool> abh(n), abw(n);
		rep(j, n) {
			bool b = false;
			if (t[j] & ((ul)1 << i))b = true;
			h[j] = b;
			if (s[j] == 0) {
				if (b) {
					abh[j] = true;
				}
			}
			else {
				if (!b) {
					abh[j] = true;
				}
			}

			b = false;
			if (v[j] & ((ul)1 << i))b = true;
			w[j] = b;
			if (u[j] == 0) {
				if (b){
					abw[j] = true;
				}
			}
			else {
				if (!b) {
					abw[j] = true;
				}
			}
		}
		rep(j, n)rep(k, n) {
			if (h[j] == w[k])ans[j][k][i] = h[j];
			else {
				if (abh[j] && abw[k]) {
					cout << -1 << "\n"; return;
				}
				else if (abh[j]) {
					ans[j][k][i] = h[j];
				}
				else if (abw[k]) {
					ans[j][k][i] = w[k];
				}
				else {
					ans[j][k][i] = 2;
				}
			}
		}
		rep(_, 3) {
			rep(j, n)if (!abh[j]) {
				bool exi = false;
				rep(k, n) {
					if (ans[j][k][i] == h[j])exi = true;
				}
				if (exi) {
					rep(k, n) {
						if (ans[j][k][i] == 2) {
							ans[j][k][i] = w[k];
						}
					}
				}
			}
			rep(j, n)if (!abw[j]) {
				bool exi = false;
				rep(k, n) {
					if (ans[k][j][i] == w[j])exi = true;
				}
				if (exi) {
					rep(k, n) {
						if (ans[k][j][i] == 2) {
							ans[k][j][i] = h[k];
						}
					}
				}
			}
		}
		vector<bool> exi2h(n), exi2w(n);
		rep(j, n)rep(k, n)if (ans[j][k][i] == 2) {
			exi2h[j] = exi2w[k] = true;
		}
		vector<int> indh, indw;
		rep(j, n) {
			if (exi2h[j])indh.push_back(j);
			if (exi2w[j])indw.push_back(j);
		}
		if (indh.size() && indw.size()) {
			if (indh.size() == 1 || indw.size() == 1) {
				cout << -1 << "\n"; return;
			}
			int ch = h[indh[0]];
			int cw = w[indw[0]];
			int tmp = 0;
			rep(j, indh.size()) {
				rep(k, indw.size()) {
					
					if (tmp == k) {
						ans[indh[j]][indw[k]][i] = ch;
					}
					else {
						ans[indh[j]][indw[k]][i] = cw;
					}
				}
				tmp++;
				if (tmp == indw.size())tmp = 0;
			}
		}
		rep(j, n)if (!abh[j]) {
			bool exi = false;
			rep(k, n) {
				if (ans[j][k][i] == h[j])exi = true;
			}
			if (!exi) {
				cout << -1 << "\n"; return;
			}

		}
		rep(j, n)if (!abw[j]) {
			bool exi = false;
			rep(k, n) {
				if (ans[k][j][i] == w[j])exi = true;
			}
			if (!exi) {
				cout << -1 << "\n"; return;
			}
		}
	}
	rep(i, 64) {
		ul u = (ul)1 << i;
		rep(j, n)rep(k, n) {
			if (ans[j][k][i]) {
				out[j][k] |= u;
			}
		}
	}
	rep(i, n){
		rep(j, n) {
			if (j > 0)cout << " ";
			cout << out[i][j];
		}
		cout << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}