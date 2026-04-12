#include<algorithm>
#include<iostream>
#include<string>

std::string enc[] = { "101", "000000", "000011", "10010001", "010001", "000001", "100101", "10011010", "0101", "0001", "110", "01001", "10011011", "010000", "0111", "10011000", "0110", "00100", "10011001", "10011110", "00101", "111", "10011111", "1000", "00110", "00111", "10011100", "10011101", "000010", "10010010", "10010011", "10010000" };
std::string str = " \',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string symbol = " .,-\'?";

std::string bin( int n )
{
	std::string ret( 5, '0' );
	int cnt = 0;

	while( n > 0 )
	{
		ret[cnt++] = ( n & 1 ) + '0';
		n >>= 1;
	}

	std::reverse( ret.begin(), ret.end() );

	return ret;
}

int main()
{
	std::string s;
	while( std::getline( std::cin, s ) )
	{
		std::string code;
		for( int i = 0; i != s.size(); ++i )
			code += s[i] >= 'A' && s[i] <= 'Z' ? bin( s[i] - 'A' ) : bin( 26 + symbol.find( s[i] ) );
	
		std::string ans;

		int i;
		for( i = 0; i < code.size(); ++i )
		{
			std::string t;

			for( int j = i; j < code.size(); ++j )
			{
				t += code[j];

				std::string* it;
				if( ( it = std::find( enc, enc + 32, t ) ) != enc + 32 )
					ans += str[it - enc], i = j;
			}
		}

		std::cout << ans << std::endl;
	}

	return 0;
}