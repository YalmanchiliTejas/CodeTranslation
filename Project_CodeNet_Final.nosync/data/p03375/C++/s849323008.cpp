#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

namespace MOD_INT_GLOBAL {
    unsigned uMod;

    struct Mint {
	unsigned x;

	Mint() : x(0) {}
	Mint(const Mint &y) : x(y.x) {}
	Mint(unsigned y) { if (uMod <= y) y %= uMod; x = y; }
	Mint(int y) { if (y < 0 || (LL)uMod <= y) y %= uMod; if (y < 0) y += uMod; x = y; }
	Mint(unsigned long long y) { if (uMod <= y) y %= uMod; x = y; }
	Mint(long long y) { if (y < 0 || uMod <= y) y %= uMod; if (y < 0) y += uMod; x = y; }

	Mint& operator+=(const Mint &y) { if ((x += y.x) >= uMod) x -= uMod; return *this; }
	Mint& operator-=(const Mint &y) { if ((x += uMod - y.x) >= uMod) x -= uMod; return *this; }
	Mint& operator*=(const Mint &y) { x = (unsigned long long)x * y.x % uMod; return *this; }
	Mint& operator/=(const Mint &y) { x = (unsigned long long)x * y.inv().x % uMod; return *this; }
	Mint operator-() const { return x? uMod - x: 0; }
	int geti() const { return x; }
    
    
	Mint inv() const {
	    unsigned a = uMod, b = x; int u = 0, v = 1;
	    while (b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	    }
	    if (u < 0) u += uMod;
	    return Mint(u);
	}

	Mint pow(long long y) const {
	    Mint b = *this, r = 1;
	    if (y < 0) { b = b.inv(); y = -y; }
	    for (; y; y>>=1) {
		if (y&1) r *= b;
		b *= b;
	    }
	    return r;
	}

	friend Mint operator+(Mint x, const Mint &y) { return x += y; }
	friend Mint operator-(Mint x, const Mint &y) { return x -= y; }
	friend Mint operator*(Mint x, const Mint &y) { return x *= y; }
	friend Mint operator/(Mint x, const Mint &y) { return x /= y; }
	friend bool operator<(const Mint x, const Mint y) { return x.x < y.x; }
	friend bool operator==(const Mint x, const Mint y) { return x.x == y.x; }
	friend bool operator!=(const Mint x, const Mint y) { return x.x != y.x; }
    };
}; // namespace MOD_INT_GLOBAL

using namespace MOD_INT_GLOBAL;

LL powMod(LL x, LL y, LL m) {
    LL r = 1;
    x %= m;
    for (; y; y>>=1) {
	if (y & 1) (r *= x) %= m;
	(x *= x) %= m;
    }
    return r;
}

const int MAX = 1000000;
Mint inv[MAX+1], fact[MAX+1], fact_inv[MAX+1];

void init() {
    LL MOD = uMod;
    inv[1] = 1;
    for (int i=2; i<=MAX; i++) inv[i] = inv[MOD%i] * (MOD-MOD/i);

    fact[0] = fact_inv[0] = 1;
    for (int i=1; i<=MAX; i++) {
	fact[i] = fact[i-1] * i;
	fact_inv[i] = fact_inv[i-1] * inv[i];
    }
}

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}

int N, M;

Mint dp[3011][3011];

Mint ways(int n) {
    Mint ret = 0;
    REP (j, n+1) {
	ret += dp[n][j];
    }
    return ret;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    uMod = M;
    init();

    dp[0][0] = 1;
    REP (i, N+1) {
	REP (j, i+1) {
	    dp[i+1][j] += dp[i][j] * (j+1);
	    dp[i+1][j+1] += dp[i][j];
	}
    }

    REP (i, N+1) {
	Mint base = Mint(2).pow(N-i);
	Mint eval = Mint(2).pow(powMod(2, N-i, uMod-1));

	REP (j, i+1) {
	    dp[i][j] *= eval;
	    eval *= base;
	}
    }

    int sgn = 1;
    Mint ans = 0;
    REP (i, N+1) {
	Mint tmp = nCk(N, i) * ways(i);
	ans += (sgn==1? tmp: -tmp);
	sgn = 1-sgn;
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

