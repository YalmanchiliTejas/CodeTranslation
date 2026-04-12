#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;
const int inf = 0x3f3f3f3f ;

int v[maxn] ,dp[maxn] ;

int main() {
	int n ;
	scanf("%d",&n) ;
	for (int i = 1 ; i <= n ; i ++ ) {
		scanf("%d",&v[i]) ;
	}
	dp[1] = v[1] ; int len = 1 ;
	for (int i = 2 ; i <= n ; i ++ ) {
		if ( dp[len] >= v[i] ) {
			dp[++len] = v[i] ;
		} else {
			int l = 1,r = len ,mid ;
			while ( l <= r ) {
				mid = (l + r)>>1 ;
				if ( dp[mid] >= v[i] ) {
					l = mid + 1 ;
				} else {
					r = mid - 1 ;
				}
			}
			dp[l] = v[i] ;
		}
	}
//	for (int i = 1 ; i <= n ; i ++ ) {
//		printf("%d ",dp[i]) ;
//	} puts("") ;
	printf("%d\n",len) ;
	return 0;
}