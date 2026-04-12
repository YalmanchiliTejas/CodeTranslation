#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main( void )
{
	vector <int> T;
	map<int,int> P;

	int ac, no;
	string in;
	while ( 1 )
	{
		cin >> in;
		replace( in.begin(), in.end(), ',', ' ' );
		istringstream is( in );
		is >> no >> ac;
		if ( no == 0 && ac == 0 )
			break;

		P[no] = ac;
		T.push_back( no );
	}

	for ( int i = 0; i < T.size() - 1; i++ )
	{
		for ( int j = i+1; j < T.size(); j++ )
		{
			if ( P[T[i]] < P[T[j]] )
			{
				swap( T[i], T[j] );
			}
		}
	}

	vector <int> R( T.size() );
	for ( int i = 0; i < T.size(); i++ )
	{
		R[i] = i + 1;
	}

	for ( int i = 1; i < T.size(); i++ )
	{
		if ( P[T[i]] == P[T[i-1]] )
			R[i] = R[i-1];
		else if ( R[i-1] - R[i] != 1 )
			R[i] = R[i-1] + 1;
	}

	map <int, int> rank;
	for ( int i = 0; i < T.size(); i++ )
	{
		rank[T[i]] = R[i];
	}

	int team;
	while ( cin >> team )
	{
		cout << rank[team] << endl;
	}

	return 0;
}