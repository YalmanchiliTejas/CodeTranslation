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

int A, B;
int D[11][11];
int U[111][111];
int idx[111][111];
int cnt;
void add(int s, int t) {
    if (idx[s][t] == 0) idx[s][t] = cnt++;
}

void MAIN() {
    scanf("%d%d", &A, &B);
    REP (i, A) REP (j, B) scanf("%d", &D[i][j]);

    REP (i, A) REP (j, B) REP (s, 101) REP (t, 101) {
	amax(U[s][t], D[i][j] - s*(i+1) - t*(j+1));
    }

    cnt = 1;
    add(0, 0);
    REP (i, A) REP (j, B) {
	REP (s, 101) REP (t, 101) {
	    if (s*(i+1) + t*(j+1) + U[s][t] == D[i][j]) {
		add(s, t);
		goto BREAK;
	    }
	}

	puts("Impossible");
	return;
BREAK:
	;
    }

    for (int s=101; s--;) for (int t=101; t--;) if (idx[s][t]) {
	if (s == 0 && t == 0) continue;
	if (s && idx[s-1][t]) continue;
	if (t && idx[s][t-1]) continue;
	if (s < t) add(s, t-1);
	else add(s-1, t);
    }

    puts("Possible");
    VI from, to, cst;
    REP (s, 101) REP (t, 101) {
	if (idx[s][t]) {
	    if (idx[s][t+1]) {
		from.push_back(idx[s][t]);
		to.push_back(idx[s][t+1]);
		cst.push_back(-2);  // Y
	    }
	    if (idx[s+1][t]) {
		from.push_back(idx[s][t]);
		to.push_back(idx[s+1][t]);
		cst.push_back(-1);  // X
	    }
	    from.push_back(idx[s][t]);
	    to.push_back(cnt);
	    cst.push_back(U[s][t]);
	}
    }

    printf("%d %d\n", cnt, (int)from.size());
    REP (i, from.size()) {
	printf("%d %d ", from[i], to[i]);
	if (cst[i] == -2) puts("Y");
	else if (cst[i] == -1) puts("X");
	else printf("%d\n", cst[i]);
    }
    printf("1 %d\n", cnt);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

