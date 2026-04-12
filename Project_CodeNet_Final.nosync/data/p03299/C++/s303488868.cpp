#include<bits/stdc++.h>
using namespace std;

template <int MOD_>
struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

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
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
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
using num = modnum<int(1e9) + 7>;

using ll = long long;

num powmod(num a, ll b) {
	num r = 1;
	while (b) {
		if (b & 1) {
			r *= a;
		}
		a *= a;
		b /= 2;
	}
	return r;
}

const int MAXV = 110;

pair<num, num> go(vector<int> H) {
	int Hmin = *min_element(H.begin(), H.end());
	int num0 = 0;
	for (int i = 0; i < int(H.size()); i++) {
		H[i] -= Hmin;
		if (H[i] == 0) num0++;
	}

	assert(num0 >= 1);
	num p0 = 1;
	num p1 = 1;
	int prv = 0;
	for (int i = 0; i <= int(H.size()); i++) {
		if (i == int(H.size()) || H[i] == 0) {
			if (prv < i) {
				auto p = go(vector<int>(H.begin() + prv, H.begin() + i));
				p0 *= (p.first + p.second);
				p1 *= p.second;
			}
			prv = i+1;
		}
	}
	num tot = powmod(2, num0) * p0 + (powmod(2, Hmin) - 2) * p1;
	num alt = powmod(2, Hmin) * p1;
	return {tot, alt};
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	auto ans = go(H);
	cout << ans.first << '\n';

	return 0;
}
