#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef unsigned long long ull;

template<typename T> inline void read(T &x) {
	char c = getchar();
	bool f = false;
	for (x = 0; !isdigit(c); c = getchar()) {
		if (c == '-') {
			f = true;
		}
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + c - '0';
	}
	if (f) {
		x = -x;
	}
}

template<typename T> inline bool checkMax(T &a, const T &b) {
	return a < b ? a = b, true : false;
}

template<typename T> inline bool checkMin(T &a, const T &b) {
	return a > b ? a = b, true : false;
}

const int N = 1e4 + 10, mod = 998244353, G = 3;

inline void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    } if (a < 0) {
        a += mod;
    }
}

inline void mul(int& a, int b) {
    a = 1ll * a * b - 1ll * a * b / mod * mod;
}

int fac[N], invfac[N];

inline int qpow(int v, int p) {
	int res = 1;
	for (; p; p >>= 1, mul(v, v)) {
		if (p & 1) {
			mul(res, v);
		}
	}
	return res;
}

void init() {
	fac[0] = invfac[0] = 1;
	int ub = 1e4 + 1;
	for (register int i = 1; i <= ub; ++i) {
		mul(fac[i] = fac[i - 1], i);
	}
	invfac[ub] = qpow(fac[ub], mod - 2);
	for (register int i = ub - 1; i; --i) {
		mul(invfac[i] = invfac[i + 1], i + 1);
	}
}

int n, x[N << 2], y[N << 2], r[N << 2], l, S;

void prepare(int n) {
	x[0] = 1;
	for (register int i = 0; i <= n; ++i) {
		y[i] = invfac[i + 1];
	}
	for (l = 0, S = 1; S <= n << 1; S <<= 1, ++l);
	--l;
	for (register int i = 0; i < S; ++i) {
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << l);
	}
}

inline void ntt(int* c, int type) {
	for (register int i = 0; i < S; ++i) {
		if (i < r[i]) {
			swap(c[i], c[r[i]]);
		}
	}
	for (register int i = 1; i < S; i <<= 1) {
		int x = qpow(G, type == 1 ? (mod - 1) / (i << 1) : mod - 1 - (mod - 1) / (i << 1));
		for (register int j = 0; j < S; j += i << 1) {
			int y = 1;
			for (register int k = 0; k < i; ++k, mul(y, x)) {
				int p = c[j + k], q = c[i + j + k];
				mul(q, y);
				add(c[j + k] = p, q);
				add(c[i + j + k] = p, -q);
			}
		}
	}
	if (type == -1) {
		int inv = qpow(S, mod - 2);
		for (register int i = 0; i < S; ++i) {
			mul(c[i], inv);
		}
	}
}

inline void mul(int* c, int* t) {
	for (register int i = 0; i < S; ++i) {
		mul(c[i], t[i]);
	}
}

char a[N], b[N];

int main() {
	scanf("%s%s", a, b);
	int n = strlen(a), c1 = 0, c2 = 0;
	for (register int i = 0; i < n; ++i) {
		if (a[i] == '1' && b[i] == '1') {
			c1++;
		} else if (a[i] == '1' && b[i] == '0') {
			c2++;
		}
	}
	init();
	prepare(c1);
	for (register int p = c2; p; p >>= 1) {
		ntt(y, 1);
		if (p & 1) {
			ntt(x, 1), mul(x, y), ntt(x, -1);
			fill(x + c1 + 1, x + S, 0);
		}
		mul(y, y), ntt(y, -1);
		fill(y + c1 + 1, y + S, 0);
	}
	int res = 0;
	for (register int i = 0; i <= c1; ++i) {
		add(res, x[i]);
	}
	mul(res, fac[c1]), mul(res, fac[c2]), mul(res, fac[c1 + c2]);
	printf("%d\n", res);
	return 0;
}