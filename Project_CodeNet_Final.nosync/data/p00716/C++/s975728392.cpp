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

ll simple( int, int, double, int );
ll compound( int, int, double, int );

int m, n;
int a, year, p;
bool type;
double r;

int main()
{
	cin >> m;
	while ( m-- ) {
		ll ans = -1;
		cin >> a >> year >> n;
		while ( n-- ) {
			cin >> type >> r >> p;
			ll res = ( type ? compound( a, year, r, p ) : simple( a, year, r, p ) );
			ans = max( ans, res );
		}
		cout << ans << endl;
	}
	return 0;
}

// a_n = a_(n-1)-p, b_n = b_(n-1)+r*a_(n-1)
ll simple( int A, int N, double R, int P ) {
	ll tmp1 = ( ll ) A;
	ll tmp2 = 0;
	REP( i, N ) {
		tmp2 = tmp2 + R * tmp1;
		tmp1 = tmp1 - P;
	}
	return tmp1 + tmp2;
}

// a_n = (1+r)*a_(n-1)-p
ll compound( int A, int N, double R, int P ) {
	ll tmp = ( ll )A;
	REP( i, N ) tmp = ( 1 + R ) * tmp - P;
	return tmp;
}