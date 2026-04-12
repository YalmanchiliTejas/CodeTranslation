#include<queue>
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
template<unsigned MOD> struct ModInt {
    static const unsigned static_MOD = MOD;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(const ModInt &y) { x = y.x; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }
    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;

const int MAXN = 100111;
int N, M;
int S, T;
int U[200111], V[200111], D[200111];
vector<pair<int, LL> > G[MAXN];
LL lenS[MAXN], lenT[MAXN];
Mint dpS[MAXN], dpT[MAXN];

void calc(int s, LL len[], Mint dp[]) {
    memset(len, 0x3f, sizeof(LL) * N);
    len[s] = 0;
    dp[s] = 1;
    priority_queue<pair<LL, int> > Q;
    Q.emplace(0, s);
    while (!Q.empty()) {
	LL cst = -Q.top().first;
	int v = Q.top().second;
	Q.pop();
	if (len[v] < cst) continue;
	EACH (e, G[v]) {
	    int w = e->first;
	    LL cst2 = cst + e->second;
	    if (len[w] > cst2) {
		len[w] = cst2;
		dp[w] = 0;
		Q.emplace(-cst2, w);
	    }

	    if (len[w] == cst2) {
		dp[w] += dp[v];
	    }
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &T);
    S--; T--;
    REP (i, M) {
	scanf("%d%d%d", U+i, V+i, D+i);
	U[i]--; V[i]--;
	G[U[i]].emplace_back(V[i], D[i]);
	G[V[i]].emplace_back(U[i], D[i]);
    }

    calc(S, lenS, dpS);
    calc(T, lenT, dpT);

    const LL LEN = lenS[T];
    Mint ans = dpS[T] * dpT[S];
    REP (i, N) {
	if (lenS[i] == lenT[i] && lenS[i] + lenT[i] == LEN) {
//	    eprintf("%d : %d %d\n", i, dpS[i].geti(), dpT[i].geti());
	    Mint k = dpS[i] * dpT[i];
	    ans -= k*k;
	}
    }
    REP (i, M) {
	int u = U[i], v = V[i];

	if (lenS[u] > lenS[v]) swap(u, v);

	if (lenS[u]*2 < LEN && lenT[v]*2 < LEN && 
		LEN == lenS[u] + D[i] + lenT[v]) {
//	    eprintf("%d %d : %d %d\n", u, v, dpS[u].geti(), dpT[v].geti());
	    Mint k = dpS[u] * dpT[v];
	    ans -= k * k;
	}
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

