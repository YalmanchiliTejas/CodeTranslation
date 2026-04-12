#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define FOR( v, c ) for ( auto &v : c )

#define EACH( it, c ) for ( auto it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()
#define DRANGE( c, p ) (c).begin(), (c).begin() + p, (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

int tan( int money, int year, double rishi, int tesu )
{
	int t_rishi = 0;
	int res = money;
	REP( i, 0, year )
	{
		t_rishi += res * rishi;
		res -= tesu;
	}
	return res + t_rishi;
}

int fuku( int money, int year, double rishi, int tesu )
{
	REP( i, 0, year )
	{
		money += money * rishi;
		money -= tesu;
	}
	return money;
}

int ( * const funcs[] )( int m, int y, double r, int t ) = { tan, fuku };

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int m;
	cin >> m;
	REP( times, 0, m )
	{
		int money, year, n;
		cin >> money >> year >> n;

		VI type( n ), tesu( n );
		vector<double> rishi( n );

		REP( i, 0, n )
		{
			cin >> type[i] >> rishi[i] >> tesu[i];
		}

		int res = 0;
		REP( i, 0, n )
		{
			res = max( res, (*funcs[ type[i] ])( money, year, rishi[i], tesu[i] ) );
		}

		cout << res << endl;
	}

	return 0;
}