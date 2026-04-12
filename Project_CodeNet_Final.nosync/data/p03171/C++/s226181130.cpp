#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<iterator>
#include<stack>
#include<queue>
#include<utility>
#include<functional>
#include<bitset>
#include<numeric>
#include<cstring>
#include<tuple>
using namespace std;

int n;
vector< long long > arr( 3003 ), pref( 3003, 0 );
int ok[ 3003 ][ 3003 ];
long long dp[ 3003 ][ 3003 ];

long long solve( int l, int r )
{
	if( l == r )
	{
		return arr[ l ];
	}
	if( ok[ l ][ r ] != -1 )
	{
		return dp[ l ][ r ];
	}
	ok[ l ][ r ] = 1;
	dp[ l ][ r ] = max( arr[ l ] + pref[ r ] - pref[ l ] - solve( l + 1, r ), arr[ r ] + pref[ r - 1 ] - pref[ l - 1 ] - solve( l, r - 1 ) );
	return dp[ l ][ r ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	memset( ok, -1, sizeof( ok ) );
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];
		pref[ i ] += pref[ i - 1 ] + arr[ i ];		
	}
	cout << 2 * solve( 1, n ) - pref[ n ] << "\n";
	return 0;
}