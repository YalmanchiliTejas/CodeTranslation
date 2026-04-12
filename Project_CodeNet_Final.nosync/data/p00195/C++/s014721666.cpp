#include<algorithm>
#include<iostream>
#include<utility>

typedef std::pair<int, int> P;

int main()
{
	int s1, s2;
	while( std::cin >> s1 >> s2, s1 | s2 )
	{
		P ans( s1 + s2, 0 );
		for( int i = 0; i != 4; ++i )
		{
			std::cin >> s1 >> s2;
			ans = std::max( ans, P( s1 + s2, i + 1 ) );
		}
		std::cout << char( 'A' + ans.second ) << ' ' << ans.first << std::endl;
	}

	return 0;
}