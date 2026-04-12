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
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL C[8];

void MAIN() {
    LL K;
    scanf("%lld", &K);
    vector<LL> X;

    REP (t, 35) {
	REP (c, 7) REP (k, t) {
	    if (c == 0) C[0]++;
	    else C[c] += C[c-1];
	    X.push_back(C[6]);
	}
    }
    VI Y(X.size());
    for (int i=X.size(); --i;) {
	while (X[i] && X[i] <= K) {
	    K -= X[i];
	    Y[i]++;
	}
    }
    int idx = 0;
    REP (t, 35) {
	REP (c, 7) REP (k, t) {
	    putchar("FESTIVA"[c]);
	    if (c == 0) C[0]++;
	    else C[c] += C[c-1];

	    REP (z, Y[idx]) putchar('L');
	    idx++;
	}
    }
    putchar('\n');
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

