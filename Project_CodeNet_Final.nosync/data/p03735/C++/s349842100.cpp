#include<set>
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
int X[200011], Y[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d%d", X+i, Y+i);
	if (X[i] > Y[i]) swap(X[i], Y[i]);
    }

    LL ans = 1LL<<62;
    LL xmi = *min_element(X, X+N);
    LL xma = *max_element(X, X+N);
    LL ymi = *min_element(Y, Y+N);
    LL yma = *max_element(Y, Y+N);
    amin(ans, (xma - xmi) * (yma - ymi));

    LL w = max(xma, yma) - min(xmi, ymi);

    multiset<int> M(X, X+N);
    vector<pair<int, int> > V;
    V.reserve(N);
    REP (i, N) {
	V.emplace_back(X[i] + Y[i], X[i]);
    }
    sort(V.begin(), V.end());

    amin(ans, w * (*M.rbegin() - *M.begin()));
    REP (i, N) {
	M.erase(M.find(V[i].second));
	M.insert(V[i].first - V[i].second);
	amin(ans, w * (*M.rbegin() - *M.begin()));
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

