#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int S[511];
int T[511];
ULL U[511];
ULL V[511];

char R[511], C[511];

ULL A[511][511];

bool solve(int t) {
    int r0 = 0, r1 = 0, rO = 0, rI = 0;
    memset(R, '?', sizeof R);
    REP (i, N) {
	if (S[i] == 0) { // and;
	    if (U[i]>>t&1) {
		rI++;
		R[i] = 'I';
	    } else {
		r0++;
		R[i] = '.';
	    }
	} else { // or;
	    if (U[i]>>t&1) {
		r1++;
		R[i] = '#';
	    } else {
		rO++;
		R[i] = 'O';
	    }
	}
    }
    int c0 = 0, c1 = 0, cO = 0, cI = 0;
    memset(C, '?', sizeof C);
    REP (j, N) {
	if (T[j] == 0) { // and;
	    if (V[j]>>t&1) {
		cI++;
		C[j] = 'I';
	    } else {
		c0++;
		C[j] = '.';
	    }
	} else { // or;
	    if (V[j]>>t&1) {
		c1++;
		C[j] = '#';
	    } else {
		cO++;
		C[j] = 'O';
	    }
	}
    }

    if (rI && cO) return false;
    if (rO && cI) return false;

    if (r0 + rO == N && c1 + cI == N) {
	if (r0 <= 1) return false;
	if (c1 <= 1) return false;
	int pr = 0;
	REP (i, N) {
	    int pc = 0;
	    REP (j, N) {
		ULL b;
		if (R[i] == 'O' || C[j] == 'O') b = 0;
		else if (R[i] == 'I' || C[j] == 'I') b = 1;
		else { b = pr^pc; pc ^= 1; }
		A[i][j] |= b<<t;
	    }
	    if (R[i] != 'O' && R[i] != 'I') pr ^= 1;
	}
    } else if (r1 + rI == N && c0 + cO == N) {
	if (r1 <= 1) return false;
	if (c0 <= 0) return false;
	int pr = 0;
	REP (i, N) {
	    int pc = 0;
	    REP (j, N) {
		ULL b;
		if (R[i] == 'O' || C[j] == 'O') b = 0;
		else if (R[i] == 'I' || C[j] == 'I') b = 1;
		else { b = pr^pc; pc ^= 1; }
		A[i][j] |= b<<t;
	    }
	    if (R[i] != 'O' && R[i] != 'I') pr ^= 1;
	}
    } else {
	REP (i, N) REP (j, N) {
	    ULL b = 0;
	    if (R[i] == 'O' || C[j] == 'O') b = 0;
	    else if (R[i] == 'I' || C[j] == 'I') b = 1;
	    else if (R[i] == '#' && C[j] == '#') b = 1;
	    else if (R[i] == '#' && C[j] == '.') {
		if (c1 + cI == 0) b = 1;
	    } else if (R[i] == '.' && C[j] == '#') {
		if (r1 + rI == 0) b = 1;
	    }
	    A[i][j] |= b<<t;
	}
    }
    return true;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", S+i);
    REP (i, N) scanf("%d", T+i);
    REP (i, N) scanf("%llu", U+i);
    REP (i, N) scanf("%llu", V+i);

    REP (t, 64) {
	if (!solve(t)) {
	    puts("-1");
	    return;
	}
    }
    REP (i, N) rprintf("%llu", A[i], A[i]+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

