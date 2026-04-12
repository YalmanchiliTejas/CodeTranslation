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

int N;
VI G[100011];
int deg[100011];
bool use[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
	deg[x]++;
	deg[y]++;
    }

    VI leaf; leaf.reserve(N);
    REP (i, N) if (deg[i] == 1) {
	leaf.push_back(i);
    }

    bool yes = false;

    for (int i=0; i<(int)leaf.size(); i++) {
	int v = leaf[i];
	if (deg[v] == 0) {
	    yes = true;
	    break;
	}
	if (use[v]) {
	    continue;
	}
	use[v] = true;
	EACH (e, G[v]) if (!use[*e]) {
	    use[*e] = true;
	    EACH (f, G[*e]) if (!use[*f]) {
		deg[*f]--;
		if (deg[*f] == 1) {
		    leaf.push_back(*f);
		}
	    }
	}
    }

    puts(yes? "First": "Second");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

