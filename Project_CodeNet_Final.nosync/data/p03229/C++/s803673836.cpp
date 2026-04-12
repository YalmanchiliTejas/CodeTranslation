#include <bits/stdc++.h>

#define ll long long
#define inf 0x3f3f3f3f 
#define il inline 

#define in1(a) a=read()
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
#define out(a) printf( "%d" , a ) 
#define outn(a) out(a),putchar('\n')

#define I_int int 
inline I_int read() {
	
    I_int x = 0 , f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) {
        if( c == '-' ) f = -1 ;
        c = getchar() ;
    }
    while( c >= '0' && c <= '9' ) {
        x = (x << 1) + (x << 3) + c - 48 ;
        c = getchar() ;
    }
    return x * f ;
}
#undef I_int

using namespace std ;

#define N 100010

int n ;
int b[ N ] ;
int a[ N ] ;
ll ans = 0 ;

int main() {
	in1( n ) ;
	for( int i = 1 ; i <= n ; i ++ ) in1( a[ i ] ) ;
	sort( a+1 , a+n+1 ) ;
	int l = 1 , r = n , mid = ( l + r ) >> 1 ; 
	if( n % 2 ) {
		b[ mid ] = a[ r -- ] ;
		for( int i = mid - 1 ; i ; i -- ) {
			if( ( mid - i ) % 2 ) b[ i ] = a[ l ++ ] , b[ mid + mid - i ] = a[ l ++ ] ;
			else b[ i ] = a[ r -- ] , b[ mid + mid - i ] = a[ r -- ] ;
		}
		ll sum = 0 ;
		for( int i = 2 ; i <= n ; i ++ ) sum += abs( b[ i ] - b[ i - 1 ] ) ;
		ll t = sum ;
		l = 1  , r = n ;
		b[ mid ] = a[ l ++ ] ;
		for( int i = mid - 1 ; i ; i -- ) {
			if( ( mid - i ) % 2 == 0 ) b[ i ] = a[ l ++ ] , b[ mid + mid - i ] = a[ l ++ ] ;
			else b[ i ] = a[ r -- ] , b[ mid + mid - i ] = a[ r -- ] ;
		}
		sum = 0 ;
		for( int i = 2 ; i <= n ; i ++ ) sum += abs( b[ i ] - b[ i - 1 ] ) ;
		printf( "%lld\n" , max( t , sum ) ) ;
		return 0 ;
	}
	b[ mid ] = a[ r -- ] ;
	b[ mid + 1 ] = a[ l ++ ] ;
	for( int i = mid - 1 ; i ; i -- ) {
		if( ( mid - i ) % 2 ) b[ i ] = a[ l ++ ] , b[ n - i + 1 ] = a[ r -- ] ;
		else b[ i ] = a[ r -- ] , b[ n - i + 1 ] = a[ l ++ ] ;
	}
	ll sum = 0 , t = 0 ;
	for( int i = 2 ; i <= n ; i ++ ) {
		sum += abs( b[ i ] - b[ i - 1 ] ) ;
	}
	t = sum ;
	l = 1 , r = n ;
	b[ mid + 1 ] = a[ r -- ] ;
	b[ mid ] = a[ l ++ ] ;
	for( int i = mid - 1 ; i ; i -- ) {
		if( ( mid - i ) % 2 == 0 ) b[ i ] = a[ l ++ ] , b[ n - i + 1 ] = a[ r -- ] ;
		else b[ i ] = a[ r -- ] , b[ n - i + 1 ] = a[ l ++ ] ;
	}
	sum = 0 ;
	for( int i = 2 ; i <= n ; i ++ ) {
		sum += abs( b[ i ] - b[ i - 1 ] ) ;
	}
	printf( "%lld\n" , max( sum , t ) ) ; 
}