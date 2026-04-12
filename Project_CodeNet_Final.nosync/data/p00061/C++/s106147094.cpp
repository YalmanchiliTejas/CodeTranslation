#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector< pair<int,int> > teams;

	while ( true )
	{
		string buffer;

		cin >> buffer;

		for ( unsigned int i = 0; i < buffer.length(); i++ )
		{
			if ( buffer[i] == ',' )
			{
				buffer[i] = ' ';
				break;
			}
		}

		int number, point;

		istringstream( buffer ) >> number >> point;

		if ( number == 0 && point == 0 )
		{
			break;
		}

		teams.push_back( pair<int,int>( point, number ) );
	}

	sort( teams.begin(), teams.end(), greater< pair<int,int> >() );

	map<int,int> result;

	int cpoint = teams[0].first, crank = 1;
	for ( unsigned int i = 0; i < teams.size(); i++ )
	{
		if ( teams[i].first != cpoint )
		{
			cpoint = teams[i].first;
			crank++;
		}

		result[ teams[i].second ] = crank;
	}

	int number;
	
	while ( cin >> number )
	{
		cout << result[ number ] << endl;
	}

	return 0;
}