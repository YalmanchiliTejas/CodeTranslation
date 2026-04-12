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

#define EACH( it, c ) for ( auto it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

struct Dice
{
	int top, bottom;
	VI sides;

	Dice() : top( 1 ), bottom( 6 ), sides { 2, 3, 5, 4 }
	{
		return;
	}

	void rotate( string direction )
	{
		if ( direction == "North" )
		{
			int ntop = sides[0], nbottom = sides[2], nfront = bottom, nback = top;
			top = ntop;
			bottom = nbottom;
			sides[0] = nfront;
			sides[2] = nback;
		}
		else if ( direction == "East" )
		{
			int ntop = sides[3], nbottom = sides[1], nleft = bottom, nright = top;
			top = ntop;
			bottom = nbottom;
			sides[3] = nleft;
			sides[1] = nright;
		}
		else if ( direction == "South" )
		{
			int ntop = sides[2], nbottom = sides[0], nfront = top, nback = bottom;
			top = ntop;
			bottom = nbottom;
			sides[0] = nfront;
			sides[2] = nback;
		}
		else if ( direction == "West" )
		{
			int ntop = sides[1], nbottom = sides[3], nleft = top, nright = bottom;
			top = ntop;
			bottom = nbottom;
			sides[3] = nleft;
			sides[1] = nright;
		}
		else if ( direction == "Right" )
		{
			std::rotate( sides.begin(), sides.begin() + 1, sides.end() );
		}
		else
		{
			std::rotate( sides.begin(), sides.begin() + 3, sides.end() );
		}
	}
};

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	while ( true )
	{
		int n;
		cin >> n;

		if ( !n )
		{
			break;
		}

		Dice d;
		int res = 1;
		REP( i, 0, n )
		{
			string str;
			cin >> str;
			d.rotate( str );
			res += d.top;
		}

		cout << res << endl;
	}

	return 0;
}