#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 120000;
struct point {
	long long x , y , i;
} s[NN];
struct edge {
	long long x , y , c;
} e[NN*2];
long long n;
long long c[NN];
long long ans;
bool cmp1 ( point x1 , point x2 ) {
	return x1.x < x2.x;
}
bool cmp2 ( point x1 , point x2 ) {
	return x1.y < x2.y;
}
bool cmp3 ( edge x1 , edge x2 ) {
	return x1.c < x2.c;
}
long long find ( long long x ) {
	long long i , t;
	for ( i = x ; c[i] > 0 ; i = c[i] ) ;
	while ( c[x] > 0 ) {
		t = c[x];
		c[x] = i;
		x = t;
	}
	return i;
}
void Union ( long long x , long long y ) {
	c[x] = y;
}
void work () {
	long long i;
	scanf ( "%lld" , &n );
	for ( i = 1 ; i <= n ; i++ ) c[i] = -1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld%lld" , &s[i].x , &s[i].y );
		s[i].i = i;
	}
	sort ( s + 1 , s + 1 + n , cmp1 );
	for ( i = 1 ; i < n ; i++ ) {
		e[i].x = s[i].i;
		e[i].y = s[i+1].i;
		e[i].c = s[i+1].x - s[i].x;
	}
	sort ( s + 1 , s + 1 + n , cmp2 );
	for ( i = 1 ; i < n ; i++ ) {
		e[n-1+i].x = s[i].i;
		e[n-1+i].y = s[i+1].i;
		e[n-1+i].c = s[i+1].y - s[i].y;
	}
	sort ( e + 1 , e + 1 + n - 1 + n - 1 , cmp3 );
	for ( i = 1 ; i <= n - 1 + n - 1 ; i++ ) {
		if ( find ( e[i].x ) != find ( e[i].y ) ) {
			ans += e[i].c;
			Union ( find ( e[i].x ) , find ( e[i].y ) );
		}
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}