#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 1e5 + 5 ;
using namespace std ;

int n, e, lnk[N], nxt[N << 1], ter[N << 1] ;

void add(int x, int y) {
	ter[++ e] = y, nxt[e] = lnk[x], lnk[x] = e ;
}

int dfs(int p, int las) {
	int cnt = 0 ;
	for (int i = lnk[p] ; i; i = nxt[i]) if (ter[i] != las) {
		cnt += dfs(ter[i], p) ;
	}
	if (cnt == 0) return 1 ; else
	  if (cnt > 1) return 2 ; else return 0 ;
}

int main() {
	for ( ; scanf("%d", &n) != EOF ; ) {
		rep(i, 1, n) lnk[i] = 0 ;
		rep(i, 1, e) nxt[i] = 0 ; e = 0 ;
		int x, y ;
		rep(i, 1, n - 1) {
			scanf("%d%d", &x, &y) ;
			add(x, y), add(y, x) ;
		}
		if (!dfs(1, 0)) printf("Second\n") ; else printf("First\n") ;
	}
	return 0 ; 
}