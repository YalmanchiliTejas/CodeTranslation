#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = uint64_t;
using P = pair<int,int>;

bool solve();

int n;
bool s[500], t[500];
bool u[500], v[500];
ll ans[500][500];
ll b = 1;

int main() {
	ll u_orig[500], v_orig[500];
	cin >> n;
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	rep(i, n) cin >> u_orig[i];
	rep(i, n) cin >> v_orig[i];
	rep(d, 64) {
		rep(i, n) {
			u[i] = u_orig[i] & 1; u_orig[i] >>= 1;
			v[i] = v_orig[i] & 1; v_orig[i] >>= 1;
		}
		if (!solve()) {
			cout << -1 << endl;
			return 0;
		}
		b <<= 1;
	}
	rep(i, n) {
		rep(j, n) cout << ans[i][j] << ' ';
		cout << endl;
	}
}

bool resolve_any();
bool resolve_strict_existence();
bool resolve_weak_existence();

bool u_resolved[500];
bool v_resolved[500];
set<int> u_rem[500], v_rem[500];

bool solve() {
	rep(i, n) {
		u_resolved[i] = false;
		v_resolved[i] = false;
	}
	return resolve_any() && resolve_strict_existence() && resolve_weak_existence();
}

bool resolve_any() {
	bool u0 = false, u1 = false, v0 = false, v1 = false;
	rep(i, n) if ( s[i] && !u[i]) {u0 = true; break;}
	rep(i, n) if (!s[i] &&  u[i]) {u1 = true; break;}
	rep(i, n) if ( t[i] && !v[i]) {v0 = true; break;}
	rep(i, n) if (!t[i] &&  v[i]) {v1 = true; break;}
	if (u0 && v1 || u1 && v0) return false;

	bool ures[500] = {}, vres[500] = {};

	rep(i, n) if (s[i] ^ u[i]) {
		u_resolved[i] = ures[i] = true;
		if (u[i]) rep(j, n) ans[i][j] |= b;
		rep(j, n) if (u[i] == v[j]) v_resolved[j] = true;
	}
	rep(j, n) if (t[j] ^ v[j]) {
		v_resolved[j] = vres[j] = true;
		if (v[j]) rep(i, n) ans[i][j] |= b;
		rep(i, n) if (u[i] == v[j]) u_resolved[i] = true;
	}

	rep(i, n) if (!u_resolved[i]) {
		u_rem[i].clear();
		rep(j, n) if (!vres[j]) u_rem[i].insert(j);
		if (u_rem[i].empty()) return false;
	}
	rep(j, n) if (!v_resolved[j]) {
		v_rem[j].clear();
		rep(i, n) if (!ures[i]) v_rem[j].insert(i);
		if (v_rem[j].empty()) return false;
	}
	//rep(i, n) cout << u_resolved[i];
	//cout << "aaa" << (int)t[0] << (int)t[1] << endl;
	return true;
}

bool resolve_v(int);
bool resolve_u(int i) {
	assert(u_resolved[i] == false);
	u_resolved[i] = true;
	int j = *u_rem[i].begin();
	if (u[i]) ans[i][j] |= b;
	if (!v_resolved[j]) {
		if (u[i] == v[j]) v_resolved[j] = true;
		else {
			v_rem[j].erase(i);
			switch(v_rem[j].size()) {
				case 0:
					return false;
				case 1:
					return resolve_v(j);
			}
		}
	}
	return true;
}

bool resolve_v(int j) {
	assert(v_resolved[j] == false);
	v_resolved[j] = true;
	int i = *v_rem[j].begin();
	if (v[j]) ans[i][j] |= b;
	if (!u_resolved[i]) {
		if (u[i] == v[j]) u_resolved[i] = true;
		else {
			u_rem[i].erase(j);
			switch(u_rem[i].size()) {
				case 0:
					return false;
				case 1:
					return resolve_u(i);
			}
		}
	}
	return true;
}

bool resolve_strict_existence() {
	rep(i, n) if (!u_resolved[i] && u_rem[i].size() == 1 && !resolve_u(i)) return false;
	rep(j, n) if (!v_resolved[j] && v_rem[j].size() == 1 && !resolve_v(j)) return false;
	return true;
}

bool resolve_weak_existence() {
	rep(i, n) if (!u_resolved[i]) resolve_u(i);
	rep(j, n) if (!v_resolved[j]) resolve_v(j);
	return true;
}
