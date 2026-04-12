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
	while ( true )
	{
		int n;
		cin >> n;
		
		if ( n == 0 )
		{
			break;
		}

		vector< vector<int> > board;
		
		for ( int i = 0; i < n; i++ )
		{
			board.push_back( vector<int>() );
			board[i].resize( n );
		}

		
		int i = n / 2 + 1, j = n / 2;
		board[i][j] = 1;

		for ( int ni = 2; ni <= n * n; ni++ )
		{
			i++;
			i %= n;

			j++;
			j %= n;

			if ( board[i][j] == 0 )
			{
				board[i][j] = ni;
			}
			else
			{
				i++;
				i %= n;

				j--;
				if ( j < 0 )
				{
					j += n;
				}

				board[i][j] = ni;
			}
		}

		for ( unsigned int i = 0; i < board.size(); i++ )
		{
			for ( unsigned int j = 0; j < board[i].size(); j++ )
			{
				printf("%4d", board[i][j] );
			}
			cout << endl;
		}
	}

	return 0;
}