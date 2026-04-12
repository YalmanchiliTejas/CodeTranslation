#include <bits/stdc++.h>
using namespace std ;
const int MaxN = 50 + 5 ;
long long A[MaxN] , B[MaxN] ;
long long Dfs( int N , long long X ) {
	register long long Mid = ( A[N] + 1ll ) >> 1 ;
	if( X == 0 ) return 0ll ;
	if( X == Mid ) return B[N] / 2.0 + 1ll ;
	if( X == A[N] ) return B[N] ;
	if( X < Mid ) return Dfs( N - 1 , X - 1 ) ;
	if( X > Mid ) return Dfs( N - 1 , X - Mid ) + B[N] / 2.0 + 1ll ;
}
int main() {
	int N ;
	long long X ;
	scanf( "%d%lld" , &N , &X ) ;
	A[0] = 1 ;
	B[0] = 1 ;
	for(register int i = 1 ; i <= N ; ++i ) {
		A[i] = A[i-1] * 2ll + 3ll ;
		B[i] = B[i-1] * 2ll + 1ll ;
	}
	return not printf( "%lld\n" , Dfs( N , X ) ) ;
}