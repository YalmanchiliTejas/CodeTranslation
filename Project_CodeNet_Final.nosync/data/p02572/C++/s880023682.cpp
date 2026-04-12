#ifndef _TEMPLATE_ROOT
#define _TEMPLATE_ROOT
#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repl(i, a, b) for(ll i = a; i < (b); ++i)
#define repd(i, a, b) for(int i = a; i >= (b); --i)
#define repdl(i, a, b) for(ll i = a; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
#endif
#ifndef _TEMPLATE_IO
#define _TEMPLATE_IO

template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void writef(T ...tail) { write(tail...); cout << flush; }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  if (v.size()) {
    rep(i, 0, sz(v) - 1)
      out << v[i] << " ";
    out << v.back();
  }
  return out;
}
#endif
#ifndef _TEMPLATE_MODINT
#define _TEMPLATE_MODINT

#ifndef _TEMPLATE_EUCLID
#define _TEMPLATE_EUCLID

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}
#endif
template<ll MOD = 1'000'000'007>
struct Mod {
	ll val;
	Mod() : val(0) {}
	Mod(ll xx) {
		if (0 <= xx && xx < MOD) val = xx;
		else val = (xx % MOD + MOD) % MOD;
	}
	Mod& operator+=(Mod b) { if ((val += b.val) >= MOD) val -= MOD; return *this; }
	Mod& operator-=(Mod b) { if ((val += MOD - b.val) >= MOD) val -= MOD; return *this; }
	Mod& operator*=(Mod b) { (val *= b.val) %= MOD; return *this; }
	Mod& operator/=(Mod b) { (val *= b.inv().val) %= MOD; return *this; }
	Mod operator+(Mod b) const { Mod<MOD> tmp(*this); return tmp += b; }
	Mod operator-(Mod b) const { Mod<MOD> tmp(*this); return tmp -= b; }
	Mod operator*(Mod b) const { Mod<MOD> tmp(*this); return tmp *= b; }
	Mod operator/(Mod b) const { Mod<MOD> tmp(*this); return tmp /= b; }
	Mod& operator++() { *this += 1; return *this; }
	Mod& operator--() { *this -= 1; return *this; }
	Mod operator++(int) { Mod<MOD> tmp(*this); operator++(); return tmp; }
	Mod operator--(int) { Mod<MOD> tmp(*this); operator--(); return tmp; }
	Mod inv() const {
		ll v, y, g = euclid(val, MOD, v, y);
		assert(g == 1); return Mod((v + MOD) % MOD);
	}
	Mod operator^(ll p) const {
		ll r = 1, b = val;
		for (; p; p >>= 1, b = b * b % MOD) if (p & 1) r = r * b % MOD;
		return Mod(r);
	}
	friend istream& operator>>(istream &is, Mod& mod) {
		ll tmp; is >> tmp;
		mod = Mod<MOD>(tmp);
		return is;
	}
	friend ostream& operator<<(ostream &os, const Mod& mod) {
		return os << mod.val;
	}
};
#endif
using namespace std;

typedef Mod<> modint;
int n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  modint sum = 0, sum2 = 0, sum3 = 0;
  read(n);
  rep(i, 0, n) {
    modint x; read(x);
    sum += x;
    sum2 += x * x;
  }
  sum3 = sum * sum - sum2;
  write(sum3 / 2);
}

