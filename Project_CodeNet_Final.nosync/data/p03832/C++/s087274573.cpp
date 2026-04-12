
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

template<int mod> struct modulo {
	int w;
	operator int&() { return w; }
	operator int() const { return w; }
	
	modulo() {}
	modulo(int w, bool f = 1) { this->w = w; if (f) fix(); }
	void inline fix() { w %= mod; if (w < 0) w += mod; }
	modulo inline fix(int w) { w %= mod; if (w < 0) w += mod; return w; }
	
	inline modulo  operator - () { w = mod - w; return *this; }
	inline modulo& operator += (const modulo &b) { w += b.w; if (w >= mod) w -= mod; return *this; }
	inline modulo& operator -= (const modulo &b) { w -= b.w; if (w < 0) w += mod; return *this; }
	inline modulo& operator *= (const modulo &b) { w = (num) w * b.w % mod; return *this; }
	inline modulo& operator /= (const modulo &b) { return *this *= inv(b); }
	inline modulo  operator +  (const modulo &b) { modulo r = *this; return r += b; }
	inline modulo  operator -  (const modulo &b) { modulo r = *this; return r -= b; }
	inline modulo  operator *  (const modulo &b) { modulo r = *this; return r *= b; }
	inline modulo  operator /  (const modulo &b) { modulo r = *this; return r /= b; }
	
	friend inline modulo pow(const modulo &w, int p) {
		if (!w) return 0;
		modulo a = w, r = 1;
		for (; p > 0; a *= a, p >>= 1) if (p & 1) r *= a;
		return r;
	}
	
	friend inline modulo inv(const modulo &w) { return pow(w, mod - 2); }
};
const int mod = 1000000007;
typedef modulo<mod> rem;

const int nsz = 1e3;
int n, l1, r1, l2, r2;
rem fac[2][nsz + 5], dp[nsz + 5][nsz + 5], ans;

void inline factorial_init(int to = nsz) {
	fac[0][0] = 1;
	cont (i, to) fac[0][i] = fac[0][i - 1] * rem(i);
	fac[1][to] = inv(fac[0][to]);
	for (int i = to - 1; i >= 0; --i) fac[1][i] = fac[1][i + 1] * rem(i + 1);
}

int main() {
	ios::sync_with_stdio(0);
	factorial_init();
	cin >> n >> l1 >> r1 >> l2 >> r2;
	circ (c, 0, n / l1) {
		if (c && (c < l2 || c > r2)) continue;
		dp[l1 * c][l1] = rem(1) * pow(fac[1][l1], c) * fac[1][c];
	}
	loop (i, n - 1) {
		circ (j, l1, r1) {
			int l = j + 1, m = n - i;
			rem val = dp[i][j];
			if (!val) continue;
			circ (c, 0, m / l) {
				if (c && (c < l2 || c > r2)) continue;
				dp[i + c * l][l] += val * pow(fac[1][l], c) * fac[1][c];
			}
		}
	}
	circ (j, l1, r1) {
		ans += dp[n][j];
	}
	ans *= fac[0][n];
	cout << ans << ln;
}