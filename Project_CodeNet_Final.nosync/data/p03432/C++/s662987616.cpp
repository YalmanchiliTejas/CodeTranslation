//Author:xht37
#include <bits/stdc++.h>

#define ui unsigned int
#define ll long long
#define ul unsigned ll
#define ld long double

#define pi pair <int, int>
#define fi first
#define se second
#define mp make_pair

#define ls (p << 1)
#define rs (ls | 1)
#define md ((t[p].l + t[p].r) >> 1)

#define vi vector <int>
#define pb push_back
#define pq priority_queue

#define dbg(x) cerr << #x" = " << (x) << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)

#define fl(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)

using namespace std;

namespace io {
	const int SI = 1 << 21 | 1;
	char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
	int f, t;
	#define gc() (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin), IS == IT ? EOF : *IS++) : *IS++)
	inline void flush() {
		fwrite(OB, 1, OS - OB, stdout), OS = OB;
	}
	inline void pc(char x) {
		*OS++ = x;
		if (OS == OT) flush();
	}

	template <class I>
	inline void rd(I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15), c = gc());
		x *= f;
	}
	template <class I>
	inline void rd(I &x, I &y) {
		rd(x), rd(y);
	}
	template <class I>
	inline void rd(I &x, I &y, I &z) {
		rd(x), rd(y), rd(z);
	}
	template <class I>
	inline void rda(I *a, int n) {
		for (int i = 1; i <= n; i++) rd(a[i]);
	}
	inline void rdc(char &c) {
		for (c = gc(); c < 33 || c > 126; c = gc());
	}
	inline void rds(char *s, int &n) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (n = 0; c >= 33 && c <= 126; s[++n] = c, c = gc());
	}
	inline void rds(string &s) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (s.clear(); c >= 33 && c <= 126; s.pb(c), c = gc());
	}

	template <class I>
	inline void print(I x, char k = '\n') {
		if (!x) pc('0');
		if (x < 0) pc('-'), x = -x;
		while (x) ch[++t] = x % 10 + '0', x /= 10;
		while (t) pc(ch[t--]);
		pc(k);
	}
	template <class I>
	inline void print(I x, I y) {
		print(x, ' '), print(y);
	}
	template <class I>
	inline void print(I x, I y, I z) {
		print(x, ' '), print(y, ' '), print(z);
	}
	template <class I>
	inline void printa(I *a, int n) {
		for (int i = 1; i <= n; i++) print(a[i], " \n"[i==n]);
	}
	inline void printc(char c) {
		pc(c);
	}
	inline void prints(char *s, int n) {
		for (int i = 1; i <= n; i++) pc(s[i]);
		pc('\n');
	}
	inline void prints(string s) {
		int n = s.length();
		while (t < n) pc(s[t++]);
		pc('\n'), t = 0;
	}
	struct Flush {
		~Flush() {
			flush();
		}
	} flusher;
}
using io::rd;
using io::rda;
using io::rdc;
using io::rds;
using io::print;
using io::printa;
using io::printc;
using io::prints;

const int P = 998244353;

struct modint {
	int x;
	inline modint(int x = 0) : x(x) {}
	inline modint &operator = (int o) { return x = o, *this; }
	inline modint &operator += (modint o) { return (x += o.x) >= P && (x -= P), *this; }
	inline modint &operator -= (modint o) { return (x -= o.x) < 0 && (x += P), *this; }
	inline modint &operator *= (modint o) { return x = 1ll * x * o.x % P, *this; }
	template <class I>
	inline modint &operator ^= (I b) {
		modint a = *this, c;
		if (!~b) b = P - 2;
		c.x = 1 % P;
		while (b) {
			if (b & 1) c *= a;
			a *= a, b >>= 1;
		}
		return x = c.x, *this;
	}
	inline modint &operator /= (modint o) { return *this *= o ^ -1; }
	inline modint &operator += (int o) { return (x += o) >= P && (x -= P), *this; }
	inline modint &operator -= (int o) { return (x -= o) < 0 && (x += P), *this; }
	inline modint &operator *= (int o) { return x = 1ll * x * o % P, *this; }
	inline modint &operator /= (int o) { return *this *= (modint)o ^ -1; }
	template <class I>
	inline friend modint operator + (modint a, I b) { return a += b; }
	template <class I>
	inline friend modint operator - (modint a, I b) { return a -= b; }
	template <class I>
	inline friend modint operator * (modint a, I b) { return a *= b; }
	template <class I>
	inline friend modint operator ^ (modint a, I b) { return a ^= b; }
	template <class I>
	inline friend modint operator / (modint a, I b) { return a /= b; }
	inline friend bool operator == (modint a, int b) { return a.x == b; }
	inline friend bool operator != (modint a, int b) { return a.x != b; }
	inline friend bool operator < (modint a, int b) { return a.x < b; }
	inline friend bool operator <= (modint a, int b) { return a.x <= b; }
	inline friend bool operator > (modint a, int b) { return a.x > b; }
	inline friend bool operator >= (modint a, int b) { return a.x >= b; }
	inline friend bool operator == (modint a, modint b) { return a.x == b.x; }
	inline friend bool operator != (modint a, modint b) { return a.x != b.x; }
	inline friend bool operator < (modint a, modint b) { return a.x < b.x; }
	inline friend bool operator <= (modint a, modint b) { return a.x <= b.x; }
	inline friend bool operator > (modint a, modint b) { return a.x > b.x; }
	inline friend bool operator >= (modint a, modint b) { return a.x >= b.x; }
	inline bool operator ! () { return !x; }
	inline modint operator - () { return x ? P - x : 0; }
};
inline void rd(modint &x) { rd(x.x); }
inline void print(modint x, char k = '\n') { print(x.x, k); }

const int NP = 1e6 + 7;
modint p[NP], v[NP], vp[NP];
inline void init(int n) {
  p[0] = v[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i-1] * i;
  vp[n] = 1 / p[n];
  for (int i = n; i; i--) v[i] = vp[i] * p[i-1], vp[i-1] = vp[i] * i;
}
inline modint binom(int n, int m) {
  return (m < 0 || n < m) ? 0 : p[n] * vp[m] * vp[n-m];
}

namespace NTT {
	const int N = 1 << 21 | 1;
	const modint g = 3, vg = 1 / g;
	int n, m, k, l, r[N];
	modint vk, a[N], b[N];
	inline void ntt(modint *a, int n, modint x) {
		for (int i = 0; i < n; i++)
			if (i < r[i]) swap(a[i], a[r[i]]);
		for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1) {
			modint W = x ^ ((P - 1) / o);
			for (int i = 0; i < n; i += o) {
				modint w = 1;
				for (int j = 0; j < k; j++, w *= W) {
					modint x = a[i+j], y = a[i+j+k] * w;
					a[i+j] = x + y, a[i+j+k] = x - y;
				}
			}
		}
	}
	inline void solve() {
		k = 1, l = 0;
		while (k <= n + m) k <<= 1, ++l;
		vk = (modint)1 / k;
		for (int i = 0; i < k; i++)
			r[i] = r[i>>1] >> 1 | (i & 1) << (l - 1);
		for (int i = n + 1; i < k; i++) a[i] = 0;
		for (int i = m + 1; i < k; i++) b[i] = 0;
		ntt(a, k, g), ntt(b, k, g);
		for (int i = 0; i < k; i++) a[i] *= b[i];
		ntt(a, k, vg);
		for (int i = 0; i <= n + m; i++) a[i] *= vk;
	}
}

const int N = 8e3 + 7, M = 207;
int n, m;
modint f[N][M], ans;

int main() {
	rd(n, m), init(n + 2);
	f[0][0] = 1;
	for (int j = 0; j < m; j++) {
		NTT::n = NTT::m = n;
		for (int i = 0; i <= n; i++) NTT::a[i] = f[i][j] * vp[i];
		NTT::b[0] = 0;
		for (int i = 1; i <= n; i++) NTT::b[i] = vp[i+2];
		NTT::solve();
		for (int i = 0; i <= n; i++)
			f[i][j+1] = (1 + i + binom(i, 2)) * f[i][j] + p[i+2] * NTT::a[i];
	}
	for (int i = 0; i <= n; i++)
		ans += binom(n, i) * f[i][m];
	print(ans);
	return 0;
}