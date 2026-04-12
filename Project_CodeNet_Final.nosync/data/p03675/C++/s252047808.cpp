#include <stdio.h>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define STRS(i,str) for(int i = 0; (str)[i]; i++)

int main(){
	int n, a[210000];
	scanf("%d", &n);
	REP(i, n) scanf("%d", a + i);
	REP(i, (n + 1)/2) printf("%d ", a[n - i * 2 - 1]);
	FOR(i, (n + 1)/2, n) printf("%d ", a[i * 2 - n]);
}