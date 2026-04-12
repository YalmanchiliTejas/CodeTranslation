#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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

typedef unsigned int UI;
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

#define ITER( c ) __typeof( (c).begin() )
#define EACH( it, c ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int n;
	cin >> n;

	vector< stack<char> > deck( n );
	while ( true )
	{
		string command;
		cin >> command;

		int p1, p2;
		char c;

		if ( command == "push" )
		{
			cin >> p1 >> c;
			deck[ p1 - 1 ].push( c );
		}
		else if ( command == "pop" )
		{
			cin >> p1;
			cout << deck[ p1 - 1 ].top() << endl;
			deck[ p1 - 1 ].pop();
		}
		else if ( command == "move" )
		{
			cin >> p1 >> p2;
			deck[ p2 - 1 ].push( deck[ p1 - 1 ].top() );
			deck[ p1 - 1 ].pop();
		}
		else
		{
			break;
		}
	}

	return 0;
}