#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define ull unsigned ll

const int maxn = 505;
int n;
int s[maxn], t[maxn];
ull _u[maxn], _v[maxn];
int u[maxn], v[maxn];
int cur[maxn][maxn];
ull ans[maxn][maxn];

bool chk() {
	rep(i, n) if (s[i]) {
		ull x = 0;
		rep(j, n) x |= ans[i][j];
		if (x != _u[i]) return 0;
	}
	rep(i, n) if (!s[i]) {
		ull x = -1;
		rep(j, n) x &= ans[i][j];
		if (x != _u[i]) return 0;
	}
	rep(i, n) if (t[i]) {
		ull x = 0;
		rep(j, n) x |= ans[j][i];
		if (x != _v[i]) return 0;
	}
	rep(i, n) if (!t[i]) {
		ull x = -1;
		rep(j, n) x &= ans[j][i];
		if (x != _v[i]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &s[i]);
	rep(i, n) scanf("%d", &t[i]);
	rep(i, n) scanf("%llu", &_u[i]);
	rep(i, n) scanf("%llu", &_v[i]);
	rep(b, 64) {
		rep(i, n) u[i] = _u[i] >> b & 1;
		rep(i, n) v[i] = _v[i] >> b & 1;
		rep(i, n) rep(j, n) cur[i][j] = 0;
		vector <int> vr, vc;
		bool R[2], C[2];
		rep(f, 2) R[f] = C[f] = 0;
		rep(i, n) {
			if (!s[i] && u[i]) {
				rep(j, n) cur[i][j] = 1;
				R[1] = 1;
			} else if (s[i] && !u[i]) {
				rep(j, n) cur[i][j] = 0;
				R[0] = 1;
			} else {
				vr.pb(i);
			}
		}
		rep(j, n) {
			if (!t[j] && v[j]) {
				rep(i, n) cur[i][j] = 1;
				C[1] = 1;
			} else if (t[j] && !v[j]) {
				rep(i, n) cur[i][j] = 0;
				C[0] = 1;
			} else {
				vc.pb(j);
			}
		}
		if (vr.size() == 1) {
			rep(i, vc.size()) {
				if (R[v[vc[i]]]) cur[vr[0]][vc[i]] = u[vr[0]];
				else cur[vr[0]][vc[i]] = v[vc[i]];
			}
		} else if (vc.size() == 1) {
			rep(i, vr.size()) {
				if (C[u[vr[i]]]) cur[vr[i]][vc[0]] = v[vc[0]];
				else cur[vr[i]][vc[0]] = u[vr[i]];
			}
		} else {
			rep(i, vr.size()) rep(j, vc.size()) {
				cur[vr[i]][vc[j]] = (i + j) & 1;
			}
		}
		rep(i, n) rep(j, n)
			ans[i][j] |= ((ull) cur[i][j]) << b;
	}
	if (!chk()) { puts("-1"); return 0; }
	rep(i, n) rep(j, n) {
		printf("%llu", ans[i][j]);
		putchar(j + 1 == n ? '\n' : ' ');
	}
	return 0;
}
