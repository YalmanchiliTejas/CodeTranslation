
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


template< int mod >
struct ModInt {
	int x;

	ModInt() : x(0) {}

	ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

	ModInt& operator+=(const ModInt& p) {
		if ((x += p.x) >= mod) x -= mod;
		return *this;
	}

	ModInt& operator-=(const ModInt& p) {
		if ((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}

	ModInt& operator*=(const ModInt& p) {
		x = (int)(1LL * x * p.x % mod);
		return *this;
	}

	ModInt& operator/=(const ModInt& p) {
		*this *= p.inverse();
		return *this;
	}

	ModInt operator-() const { return ModInt(-x); }

	ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

	ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

	ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

	ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

	bool operator==(const ModInt& p) const { return x == p.x; }

	bool operator!=(const ModInt& p) const { return x != p.x; }

	ModInt inverse() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(int64_t n) const {
		ModInt ret(1), mul(x);
		while (n > 0) {
			if (n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	friend ostream& operator<<(ostream& os, const ModInt& p) {
		return os << p.x;
	}

	friend istream& operator>>(istream& is, ModInt& a) {
		int64_t t;
		is >> t;
		a = ModInt< mod >(t);
		return (is);
	}

	static int get_mod() { return mod; }
};

using mint = ModInt< 998244353 >;




struct segt {

	struct node {
		mint t, mx, lazyby, lazyto;
		ll length, s, e;
		bool set;
		node* l;
		node* r;
	};

	node* rt;

	void build(int i, int j, node* v) {
		v->mx = v->t = v->lazyby = v->lazyto = 0;
		v->length = j - i + 1;
		v->s = i;
		v->e = j;
		if (i == j) return;
		v->l = new node();
		v->r = new node();
		build(i, (i + j) / 2, v->l);
		build((i + j) / 2 + 1, j, v->r);
	}

	segt() {}
	segt(int n) {
		rt = new node();
		build(0, n - 1, rt);
	}

	inline void prop(node* v) {
		if (v->l != nullptr) {
			if (v->set) {
				v->l->lazyby = v->r->lazyby = 0;
				v->l->lazyto = v->r->lazyto = v->lazyto;
				v->l->set = v->r->set = true;
			}
			v->l->lazyby += v->lazyby;
			v->r->lazyby += v->lazyby;
		}
		if (v->set) {
			v->t = v->lazyto * v->length;
			v->mx = v->lazyto;
		}
		v->t += v->lazyby * v->length;
		v->mx += v->lazyby;
		v->set = false;
		v->lazyby = v->lazyto = 0;
	}

	void update(int i, int j, mint val, bool by, node* v) {
		if (j < v->s || v->e < i) return;
		if (i <= v->s && v->e <= j) {
			prop(v);
			if (by) v->lazyby += val;
			else {
				v->lazyto = val;
				v->set = true;
			}
			prop(v);
			return;
		}
		prop(v);
		update(i, j, val, by, v->l);
		update(i, j, val, by, v->r);
		prop(v->l);
		prop(v->r);
		v->t = v->l->t + v->r->t;

	}

	void updateby(int i, int j, mint val) { update(i, j, val, true, rt); }
	void updateto(int i, int j, mint val) { update(i, j, val, false, rt); }


	mint query(int i, int j, bool m, node* v) {
		if (j < v->s || v->e < i) {
			if (m) return -1000000000;
			return 0;
		}
		prop(v);
		if (i <= v->s && v->e <= j) {
			if (m) return v->mx;
			return v->t;
		}
		mint l = query(i, j, m, v->l);
		mint r = query(i, j, m, v->r);
		return l + r;
	}

	mint querysum(int i, int j) { return query(i, j, false, rt); }
	mint querymax(int i, int j) { return query(i, j, true, rt); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, x, m;
	cin >> n >> x >> m;

	vector<pair<ll, ll> > seen(m + 5, { -1, -1 });

	ll tot = x;
	ll cur = 1;
	seen[x] = { cur, tot };
	bool b = true;
	for (ll cur = 2; cur <= n; cur++) {
		x = (x * x) % m;
		tot += x;
		if (seen[x].first != -1 && b) {
			ll reps = ((n - cur) / (cur - seen[x].first));
			tot = reps * (tot - seen[x].second) + seen[x].second;
			cur = reps * (cur - seen[x].first) + seen[x].first;
			b = false;
		}
		seen[x] = { cur, tot };
	}
	cout << tot << endl;

}
