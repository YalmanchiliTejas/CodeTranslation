#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

LL N, X, M;
int T[100011];

void MAIN() {
    scanf("%lld%lld%lld", &N, &X, &M);

    memset(T, -1, sizeof T);
    int cnt = 0;
    LL A = X;
    while (T[A] == -1) {
	T[A] = cnt;
	cnt++;
	A = A * A % M;
    }

    int tail = T[A];
    int cycle = cnt - tail;
    LL joint = A;
    A = X;

    LL ans = 0;

    for (int i=0; i<tail; i++) {
	if (i < N) ans += A;
	A = A * A % M;
    }

    LL sum = 0;
    REP (i, cycle) {
	sum += A;
	A = A * A % M;
    }

    if (N >= tail) {
	ans += (N - tail) / cycle * sum;

	int rest = (N - tail) % cycle;
	REP (i, rest) {
	    ans += A;
	    A = A * A % M;
	}
    }


    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

