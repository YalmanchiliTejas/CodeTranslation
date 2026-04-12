#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

#define FOR( i, k, n ) for ( int i = ( k ); i < ( int )( n ); ++i )
#define REP( i, n ) FOR( i, 0, n )

typedef long long ll;
typedef pair< int, int > P;

#define MAX_S 32

bool IsRight( char );

int main()
{
	while( 1 ) {
		char str[ MAX_S + 1 ];
		cin >> str;
		if( str[ 0 ] == '#' ) break;

		int ans = 0;
		bool hand = IsRight( str[ 0 ] );
		for( int i = 1; str[ i ] != '\0'; ++i ) {
			if( hand != IsRight( str[ i ] ) ) {
				hand = IsRight( str[ i ] );
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

bool IsRight( char key ) {
	const char rights[ 11 ] = { 'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm' };
	REP( i, 11 ) if( key == rights[ i ] ) { return  true; }
	return false;
}