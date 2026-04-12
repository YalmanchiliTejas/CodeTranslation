#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main( void )
{
	bool next = false;
	int n;
	while ( cin >> n && n )
	{
		if ( next )
		{
			cout << endl;
		}
		next = true;
		vector <string> team_names(n);
		vector <int> points(n,0);
		vector <int> id(n,0);
		for ( int i = 0; i < n; i++ )
		{
			id[i] = i;
			cin >> team_names[i];
			int point;
			cin >> point;
			points[i] += point * 3;
			cin >> point;
			cin >> point;
			points[i] += point;
		}

		for ( int i = 0; i < n-1; i++ )
		{
			for ( int j = i + 1; j < n; j++ )
			{
				if ( points[i] < points[j] )
				{
					swap( points[i], points[j] );
					swap( team_names[i], team_names[j] );
					swap( id[i], id[j] );
				}
				else if ( points[i] == points[j] )
				{
					if ( id[i] > id[j] )
					{
						swap( points[i], points[j] );
						swap( team_names[i], team_names[j] );
						swap( id[i], id[j] );
					}
				}
			}
		}

		for ( int i = 0; i < n; i++ )
		{
			cout << team_names[i] << ',' << points[i] << endl;
		}

	}

	return 0;
}