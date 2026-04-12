#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <type_traits>
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std;
using namespace placeholders;

using LL = long long;
using ULL = unsigned long long;
using VI = vector< int >;
using VVI = vector< vector< int > >;
using VS = vector< string >;
using ISS = istringstream;
using OSS = ostringstream;
using PII = pair< int, int >;
using VPII = vector< pair< int, int > >;
template < typename T = int > using VT = vector< T >;
template < typename T = int > using VVT = vector< vector< T > >;
template < typename T = int > using LIM = numeric_limits< T >;

template < typename T > inline istream& operator>>( istream &s, vector< T > &v ){ for ( T &t : v ) { s >> t; } return s; }
template < typename T > inline ostream& operator<<( ostream &s, const vector< T > &v ){ for ( int i = 0; i < int( v.size() ); ++i ){ s << ( " " + !i ) << v[i]; } return s; }
template < typename T > inline T fromString( const string &s ) { T res; istringstream iss( s ); iss >> res; return res; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); }

#define NUMBERED( name, number ) NUMBERED2( name, number )
#define NUMBERED2( name, number ) name ## _ ## number
#define REP1( n ) REP2( NUMBERED( REP_COUNTER, __LINE__ ), n )
#define REP2( i, n ) REP3( i, 0, n )
#define REP3( i, m, n ) for ( int i = ( int )( m ); i < ( int )( n ); ++i )
#define GET_REP( a, b, c, F, ... ) F
#define REP( ... ) GET_REP( __VA_ARGS__, REP3, REP2, REP1 )( __VA_ARGS__ )
#define FOR( e, c ) for ( auto &&e : c )
#define ALL( c ) begin( c ), end( c )
#define AALL( a ) ( remove_all_extents< decltype( a ) >::type * )a, ( remove_all_extents< decltype( a ) >::type * )a + sizeof( a ) / sizeof( remove_all_extents< decltype( a ) >::type )
#define DRANGE( c, p ) begin( c ), begin( c ) + ( p ), end( c )

#define SZ( v ) ( (int)( v ).size() )
#define EXIST( c, e ) ( ( c ).find( e ) != ( c ).end() )

template < typename T > inline bool chmin( T &a, const T &b ){ if ( b < a ) { a = b; return true; } return false; }
template < typename T > inline bool chmax( T &a, const T &b ){ if ( a < b ) { a = b; return true; } return false; }

#define PB push_back
#define EM emplace
#define EB emplace_back
#define BI back_inserter

#define MP make_pair
#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

#include <climits>

// 最小費用流 O( F |E| log |V| )
class MinimumCostFlow
{
private:
	struct Edge
	{
		int to, cap, cost, rev;
		Edge( int t, int c, int d, int r ) : to( t ), cap( c ), cost( d ), rev( r ) {}
	};

	const int V;
	vector< vector<Edge> > G;

public:
	MinimumCostFlow( int v ) : V( v ), G( V ) {};

	void connect( int from, int to, int cap, int cost )
	{
		G[ from ].push_back( Edge( to, cap, cost, G[ to ].size() ) );
		G[ to ].push_back( Edge( from, 0, -cost, G[ from ].size() - 1 ) );
		return;
	}

	int solve( int s, int t, int f )
	{
		int res = 0;
		vector<int> h( V, 0 ), prevv( V ), preve( V );

		while ( 0 < f )
		{
			vector<int> distance( V, INT_MAX );
			distance[s] = 0;

			priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > que;
			que.push( make_pair( 0, s ) );
			
			while ( !que.empty() )
			{
				int d = que.top().first;
				int v = que.top().second;
				que.pop();

				if ( distance[v] < d )
				{
					continue;
				}

				for ( int i = 0; i < (int)G[v].size(); ++i )
				{
					Edge &e = G[v][i];
					if ( 0 < e.cap && distance[v] + e.cost + h[v] - h[ e.to ] < distance[ e.to ] )
					{
						distance[ e.to ] = distance[v] + e.cost + h[v] - h[ e.to ];
						prevv[ e.to ] = v;
						preve[ e.to ] = i;
						que.push( make_pair( distance[ e.to ], e.to ) );
					}
				}
			}

			if ( distance[t] == INT_MAX )
			{
				return -1;
			}

			for ( int i = 0; i < V; ++i )
			{
				h[i] += distance[i];
			}

			int d = f;
			for ( int v = t; v != s; v = prevv[v] )
			{
				d = min( d, G[ prevv[v] ][ preve[v] ].cap );
			}
			f -= d;
			res += d * h[t];
			for ( int v = t; v != s; v = prevv[v] )
			{
				Edge &e = G[ prevv[v] ][ preve[v] ];
				e.cap -= d;
				G[v][ e.rev ].cap += d;
			}
		}

		return res;
	}

	int solve2( const int s, const int t, int f )
	{
		const int INF = INT_MAX / 2;
		int res = 0;

		while ( f > 0 )
		{
			vector<int> dist( V, INF );
			dist[s] = 0;
			vector<int> prevv( V ), preve( V );

			bool update = true;
			while ( update )
			{
				update = false;

				for ( int v = 0; v < V; v++ )
				{
					if ( dist[v] == INF )
					{
						continue;
					}
					for ( int i = 0; i < (int)G[v].size(); i++ )
					{
						Edge &e = G[v][i];
						if ( e.cap > 0 && dist[ e.to ] > dist[v] + e.cost )
						{
							dist[ e.to ] = dist[v] + e.cost;
							prevv[ e.to ] = v;
							preve[ e.to ] = i;
							update = true;
						}
					}
				}
			}

			if ( dist[t] == INF )
			{
				return -1;
			}

			int d = f;
			for ( int v = t; v != s; v = prevv[v] )
			{
				d = min( d, G[ prevv[v] ][ preve[v] ].cap );
			}
			f -= d;
			res += d * dist[t];
			for ( int v = t; v != s; v = prevv[v] )
			{
				Edge &e = G[ prevv[v] ][ preve[v] ];
				e.cap -= d;
				G[v][ e.rev ].cap += d;
			}
		}

		return res;
	}
};
// MinimumCostFlow( |V| )
// connect( from, to, cap, cost )
// solve( s, t, f ) :  Primal-Dual O( F |E| log |V| )
// solve2( s, t, f ) : Bellman-Ford O( F |E| |V| )

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );
	cout << setprecision( 12 ) << fixed;

	int H, W;
	cin >> H >> W;

	VVI A( H, VI( W ) );
	cin >> A;

	// [ 0, H * W ) := cell-in
	// [ H * W, 2 * H * W ) := cell-out
	const int SRC = 2 * H * W;
	const int SINK = SRC + 1;

	const auto in = [&]( const int i, const int j ){ return i * W + j; };
	const auto out = [&]( const int i, const int j ){ return H * W + i * W + j; };

	MinimumCostFlow mcf( SINK + 1 );
	REP( i, H )
	{
		REP( j, W )
		{
			mcf.connect( in( i, j ), out( i, j ), 1, -A[i][j] );
		}
	}
	mcf.connect( in( 0, 0 ), out( 0, 0 ), 1, 0 );
	mcf.connect( in( H - 1, W - 1 ), out( H - 1, W - 1 ), 1, 0 );
	REP( i, H )
	{
		REP( j, W )
		{
			if ( i + 1 < H )
			{
				mcf.connect( out( i, j ), in( i + 1, j ), 1, 0 );
			}
			if ( j + 1 < W )
			{
				mcf.connect( out( i, j ), in( i, j + 1 ), 1, 0 );
			}
		}
	}
	mcf.connect( SRC, in( 0, 0 ), 2, 0 );
	mcf.connect( out( H - 1, W - 1 ), SINK, 2, 0 );

	cout << -mcf.solve2( SRC, SINK, 2 ) << endl;

	return 0;
}
