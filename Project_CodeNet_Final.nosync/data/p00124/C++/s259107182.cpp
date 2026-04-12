#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); i++ )
#define UREP( i, m, n ) for ( unsigned int i = (unsigned int)( m ); i < (unsigned int)( n ); i++ )
#define ITER( c ) __typeof( (c).begin() )
#define IREP( c, it ) for ( ITER(c) it = (c).begin(); it != (c).end(); ++it )
#define ALL( c ) (c).begin(), (c).end()
#define PB( n ) push_back( ( n ) )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define fst first
#define snd second

const double p500[] = { 70, 55, 50, 43, 40, 37.5, 35.5 };
const double p1000[] = { 148, 116, 105, 89, 83, 77, 71 };
const string rank[] = {	"NA", "E", "D", "C", "B", "A",	"AA", "AAA" };

struct Team
{
	string name;
	int point;

	Team( string name, int point )
	{
		this -> name = name;
		this -> point = point;

		return;
	}

	bool operator < ( const Team &a ) const
	{
		return point > a.point;
	}
};

int main()
{
	bool first = true;

	while ( true )
	{
		int n;
		cin >> n;

		if ( n == 0 )
		{
			break;
		}

		if ( first )
		{
			first = false;
		}
		else
		{
			cout << endl;
		}

		vector<Team> teams;

		REP( i, 0, n )
		{
			string name;
			int a, b, c;

			cin >> name >> a >> b >> c;

			teams.PB( Team( name, a * 3 + c ) );
		}

		stable_sort( ALL( teams ) );

		REP( i, 0, n )
		{
			cout << teams[i].name << ',' << teams[i].point << endl;
		}
	}

	return 0;
}