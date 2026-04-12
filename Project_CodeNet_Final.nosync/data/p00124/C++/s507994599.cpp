#include<functional>
#include<iostream>
#include<map>
#include<string>

int n;
std::multimap<int, std::string, std::greater<int> > m;

int main()
{
	bool fst = true;

	while( std::cin >> n, n )
	{
		m.clear();

		for( int i = 0; i != n; ++i )
		{
			std::string s;
			int a, b, c;
			std::cin >> s >> a >> b >> c;
			
			m.insert( std::make_pair( a * 3 + c, s ) );
		}

		if( !fst )
			std::cout << std::endl;
		for( auto it = m.begin(); it != m.end(); ++it )
			std::cout << it->second << ',' << it->first << std::endl;
	
		fst = false;
	}

	return 0;
}