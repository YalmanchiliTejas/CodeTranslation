#include <bits/stdc++.h>
using namespace std;

int MOD;

struct modnum {
private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num = modnum;

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

const int MAXN = 3100;
int n;
num ncr[MAXN][MAXN];
num pp2[MAXN];
num stir[MAXN][MAXN];

void precomp() {
	const int N = 3010;
	pp2[0] = 2;
	for (int i = 1; i <= N; i++) {
		pp2[i] = pp2[i-1] * pp2[i-1];
	}
	for (int i = 0; i <= N; i++) {
		ncr[i][0] = ncr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
		}
	}
	stir[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		stir[i][1] = stir[i][i] = 1;
		for (int j = 2; j < i; j++) {
			stir[i][j] = stir[i-1][j-1] + num(j) * stir[i-1][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	cin >> MOD;
	precomp();
	num ans = 0;
	for (int c = 0; c <= n; c++) {
		num tot = 0;
		for (int i = 0; i <= c; i++) {
			tot += stir[c+1][i+1] * pow(num(2), (n-c) * i);
		}
		tot *= pp2[n-c];
		tot *= ncr[n][c];
		if (c % 2 == 0) ans += tot;
		else ans -= tot;
	}
	cout << ans << '\n';
}
