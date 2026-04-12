#include <iostream>
#include <string>
#include <map>
using namespace std;

// Ï·e[u
map < char, string > M;
map < string, char > D;

int main( void )
{
	M['A'] = "00000";
	M['B'] = "00001";
	M['C'] = "00010";
	M['D'] = "00011";
	M['E'] = "00100";
	M['F'] = "00101";
	M['G'] = "00110";
	M['H'] = "00111";
	M['I'] = "01000";
	M['J'] = "01001";
	M['K'] = "01010";
	M['L'] = "01011";
	M['M'] = "01100";
	M['N'] = "01101";
	M['O'] = "01110";
	M['P'] = "01111";
	M['Q'] = "10000";
	M['R'] = "10001";
	M['S'] = "10010";
	M['T'] = "10011";
	M['U'] = "10100";
	M['V'] = "10101";
	M['W'] = "10110";
	M['X'] = "10111";
	M['Y'] = "11000";
	M['Z'] = "11001";
	M[' '] = "11010";
	M['.'] = "11011";
	M[','] = "11100";
	M['-'] = "11101";
	M['\''] = "11110";
	M['?'] = "11111";

	D["101"]		= ' ';
	D["000000"]		= '\'';
	D["000011"]		= ',';
	D["10010001"]	= '-';
	D["010001"]		= '.';
	D["000001"]		= '?';
	D["100101"]		= 'A';
	D["10011010"]	= 'B';
	D["0101"]		= 'C';
	D["0001"]		= 'D';
	D["110"]		= 'E';
	D["01001"]		= 'F';
	D["10011011"]	= 'G';
	D["010000"]		= 'H';
	D["0111"]		= 'I';
	D["10011000"]	= 'J';
	D["0110"]		= 'K';
	D["00100"]		= 'L';
	D["10011001"]	= 'M';
	D["10011110"]	= 'N';
	D["00101"]		= 'O';
	D["111"]		= 'P';
	D["10011111"]	= 'Q';
	D["1000"]		= 'R';
	D["00110"]		= 'S';
	D["00111"]		= 'T';
	D["10011100"]	= 'U';
	D["10011101"]	= 'V';
	D["000010"]		= 'W';
	D["10010010"]	= 'X';
	D["10010011"]	= 'Y';
	D["10010000"]	= 'Z';

	string in;
	while ( 1 )
	{
		getline( cin, in );
		if ( cin.eof() )
			break;

		string encode;
		for ( string::iterator it = in.begin(); it != in.end(); it++ )
		{
			encode += M[*it];
		}

		string decode = "";

		int index = 0;
		while ( 1 )
		{
			bool found = false;
			for ( int i = 3; i < 9; i++ )
			{
				if ( encode.size() < index + i )
					break;
				string t = encode.substr( index, i );
				if ( D.find( t ) != D.end() )
				{
					// ­©
					decode += D[t];
					index += i;
					found = true;
				}
			}
			if ( !found ) break;
		}

		cout << decode << endl;
	}

	return 0;
}