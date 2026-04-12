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

int N;
pair<int, int> P[201];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", &P[i].first), P[i].second = i;

    VI ans;
    while (1) {
	if ((P[0].first < P[N-1].first) != (P[0].second < P[N-1].second)) {
	    ans.push_back(N-1);
	    swap(P[0].first, P[N-1].first);
	}

	if (P[0].second == 0) {
	    bool ok = true;
	    REP (i, N) if (P[i].first != i) {
		ok = false;
		break;
	    }
	    if (ok) break;
	}
	ans.push_back(1);
	for (int i=1; i<N; i++) swap(P[i], P[i-1]);
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d\n", *e);

//    REP (i, N) eprintf("%d %d, ", P[i].first, P[i].second);
//    eprintf("\n");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

