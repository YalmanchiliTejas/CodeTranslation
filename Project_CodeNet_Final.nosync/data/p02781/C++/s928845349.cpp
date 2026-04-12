#include<bits/stdc++.h>
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
char S[111];
int K;

LL dpE[111][5], dpL[111][5];

void MAIN() {
    scanf("%s%d", S, &K);
    N = strlen(S);

    REP (i, N) {
	int C = S[i] - '0';
	if (i == 0) {
	    for (int d=1; d<C; d++) dpL[1][1] += 1;
	    dpE[1][1] += 1;
	} else {
	    for (int d=1; d<10; d++){dpL[i+1][1] += 1;}

	    REP (k, K+1) {
		dpE[i+1][k + (C==0?0:1)] += dpE[i][k];

		REP (d, C) {dpL[i+1][k + (d==0?0:1)] += dpE[i][k];}
		REP (d, 10) {dpL[i+1][k + (d==0?0:1)] += dpL[i][k];}
		}
	}
    }
//    for(int i=1;i<=N;i++){
//    	for(int j=1;j<=K;j++){
//    		cout<<i<<" "<<" "<<j<<" "<<dpL[i][j]<<" "<<dpE[i][j]<<endl;
//		}
//	} 

    LL ans = 0;
    ans += dpE[N][K];
    ans += dpL[N][K];
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
} 