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

#define dbg(x) cerr << #x" = " << x << endl
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
		s[n+1] = '\0';
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

const int P = 1e9 + 7;

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

//const int NP = 1e6 + 7;
//modint p[NP], v[NP], vp[NP];
//inline void init(int n) {
//  p[0] = v[0] = 1;
//  for (int i = 1; i <= n; i++) p[i] = p[i-1] * i;
//  vp[n] = 1 / p[n];
//  for (int i = n; i; i--) v[i] = vp[i] * p[i-1], vp[i-1] = vp[i] * i;
//}
//inline modint binom(int n, int m) {
//  return (m < 0 || n < m) ? 0 : p[n] * vp[m] * vp[n-m];
//}

const int N = 1e5 + 7;
int n, h[N], p[N], pl[N], pr[N], w[N];

struct DP {
	modint a[2][2][2];
	inline DP() {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					a[i][j][k] = 0;
	}
	inline friend DP operator + (DP a, DP b) {
		DP c;
		for (int li = 0; li < 2; ++li)
			for (int ri = 0; ri < 2; ++ri)
				for (int lj = 0; lj < 2; ++lj)
					for (int rj = 0; rj < 2; ++rj)
						for (int lk = 0; lk < 2; ++lk)
							for (int rk = 0; rk < 2; ++rk)
								c.a[li][rj][lk|rk|(lj==ri)] += a.a[li][lj][lk] * b.a[ri][rj][rk];
		return c;
	}
} f[N];

void work(int o, int x) {
	if (w[o] == x) return;
	DP now;
	int t = (w[o] ^ x) & 1;
	modint k = (modint)2 ^ (w[o] - x - 1);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			now.a[i][j][1] = f[o].a[i^t][j^t][1],
			now.a[i][j][0] = (f[o].a[i][j][0] + f[o].a[i^1][j^1][0]) * k;
	f[o] = now;
}

int main() {
	rd(n), rda(h, n), iota(p + 1, p + n + 1, 1);
	sort(p + 1, p + n + 1, [&](int i, int j) { return h[i] > h[j]; });
	for (int o = 1; o <= n; o++) {
		int i = p[o], L = i, R = i;
		DP now;
		now.a[0][0][0] = now.a[1][1][0] = 1;
		if (pl[i-1]) L = pl[i-1], pr[L] = pl[i-1] = 0, work(L, h[i]), now = f[L] + now;
		if (pr[i+1]) R = pr[i+1], pr[i+1] = pl[R] = 0, work(i + 1, h[i]), now = f[i+1] + now;
		f[L] = now, pr[L] = R, pl[R] = L, w[L] = h[i];
	}
	work(1, 1);
	modint ans;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				ans += f[1].a[i][j][k];
	print(ans);
	return 0;
}