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

int n, k;
string s;
long long dp[ 105 ][ 105 ][ 2 ];

long long solve( int pos, int sum, bool allowed )
{
	if( pos == n )
	{
		return sum == k;
	}
	if( dp[ pos ][ sum ][ allowed ] != -1 )
	{
		return dp[ pos ][ sum ][ allowed ];
	}
	dp[ pos ][ sum ][ allowed ] = 0;
	for( int i = 0; i <= ( allowed ? 9 : s[ pos ] - '0' ); ++i )
	{
		dp[ pos ][ sum ][ allowed ] += solve( pos + 1, ( i != 0 ? sum + 1 : sum ), ( allowed || i < ( s[ pos ] - '0' ) ) );
	}
	return dp[ pos ][ sum ][ allowed ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> s >> k;
	n = s.length();
	memset( dp, -1, sizeof( dp ) );
	cout << solve( 0, 0, 0 ) << "\n";
	return 0;
}