#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iomanip>

typedef long double ld;
typedef long long ll;

using namespace std;

ll MOD = ((ll)1e9 + 7);

struct mod {
	ll x;

	mod(ll tx = 0) {
		x = tx;
		x %= MOD;
	}
	
	mod& operator=(const ll & tx) {
		x = tx % MOD;
		return *this;
	}
	
	mod& operator=(const mod & m2) {
		x = m2.x;
		return *this;
	}

	mod operator+(const mod& m2) const {
		return mod((x + m2.x) % MOD);
	}

	mod& operator+=(const mod& m2) {
		x += m2.x;
		x %= MOD;
		return *this;
	}

	mod operator-(const mod & m2) const {
		return mod((x - m2.x + MOD) % MOD);
	}

	mod& operator-=(const mod & m2) {
		x -= m2.x;
		x = (x + MOD) % MOD;
		return *this;
	}

	mod operator*(const mod & m2) const {
		return mod((x * m2.x) % MOD);
	}

	mod& operator*=(const mod & m2) {
		x *= m2.x;
		x %= MOD;
		return *this;
	}

	mod mypow(ll k) const {
		mod ret = 1;
		mod cur = x;
		while (k) {
			if (k & 1) {
				ret *= cur;
			}
			cur *= cur;
			k >>= 1;
		}
		return ret;
	}

	mod inv() const {
		return mypow(MOD - 2);
	}

	mod operator/(const mod & m2) const {
		return (*this) * m2.inv();
	}

	mod& operator/=(const mod & m2) {
		x *= m2.inv().x;
		x %= MOD;
		return *this;
	}

	bool operator<(const mod & m2) const {
		return x < m2.x;
	}
};

ostream &operator<<(ostream & os, const mod & m) {
	return os << m.x;
}



/* TEMPLATE ENDS HERE */

priority_queue<pair<ll, int> > pq;

#define MAXN (1 << 17)
#define INF (1LL << 61)

int n, m, s, t;
mod cnts[MAXN], cntt[MAXN];
ll ds[MAXN], dt[MAXN];
vector<pair<int, ll> > a[MAXN];
int vs[MAXN], vt[MAXN];

void dijkstra(int s, ll d[MAXN], mod cnt[MAXN], int v[MAXN]) {
	pq.push(make_pair(0, s));
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
		cnt[i] = 0;
		v[i] = 0;
	}
	cnt[s] = 1;
	d[s] = 0;
	while (!pq.empty()) {
		pair<ll, int> cur = pq.top();
		pq.pop();
		ll curd = -cur.first;
		int curv = cur.second;
		if (v[curv]) {
			continue;
		}
		//cerr << curv << " " << curd << " " << cnt[curv] << endl;
		for (auto & e: a[curv]) {
			int nv = e.first;
			ll nd = e.second;
			if (curd + nd < d[nv]) {
				d[nv] = curd + nd;
				cnt[nv] = cnt[curv];
				pq.push(make_pair(-d[nv], nv));
			} else if (curd + nd == d[nv]) {
				cnt[nv] += cnt[curv];
			}
		}
		v[curv] = 1;
	}
	//cerr << "done" << endl;
}

int main() {
	cout << fixed << setprecision(12);	
	cin >> n >> m;
	cin >> s >> t;
	for (int i = 0; i < m; i++) {
		int tu, tv;
		ll td;
		cin >> tu >> tv >> td;
		a[tu].push_back(make_pair(tv, td));
		a[tv].push_back(make_pair(tu, td));
	}
	dijkstra(s, ds, cnts, vs);
	dijkstra(t, dt, cntt, vt);
	mod ret = cnts[t] * cnts[t];
	//cerr << ret << endl;
	ll d = ds[t];
	for (int i = 1; i <= n; i++) {
		if ((2 * ds[i] == d) && (2 * dt[i] == d)) {
			ret -= cnts[i] * cnts[i] * cntt[i] * cntt[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto& e: a[i]) {
			int j = e.first;
			int l = e.second;
			if ((2 * ds[i] < d) && (2 * dt[j] < d) && (ds[i] + dt[j] + l == d)) {
				ret -= cnts[i] * cnts[i] * cntt[j] * cntt[j];
			}
		}
	}
	cout << ret << endl;
	return 0;
}

