#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char key[][ 2 ][ 9 ] = {
	{ "\'", "000000" },
	{ "?", "000001" },
	{ "W", "000010" },
	{ ",", "000011" },
	{ "D", "0001" },
	{ "L", "00100" },
	{ "O", "00101" },
	{ "S", "00110" },
	{ "T", "00111" },
	{ "H", "010000" },
	{ ".", "010001" },
	{ "F", "01001" },
	{ "C", "0101" },
	{ "K", "0110" },
	{ "I", "0111" },
	{ "R", "1000" },
	{ "Z", "10010000" },
	{ "-", "10010001" },
	{ "X", "10010010" },
	{ "Y", "10010011" },
	{ "A", "100101" },
	{ "J", "10011000" },
	{ "M", "10011001" },
	{ "B", "10011010" },
	{ "G", "10011011" },
	{ "U", "10011100" },
	{ "V", "10011101" },
	{ "N", "10011110" },
	{ "Q", "10011111" },
	{ " ", "101" },
	{ "E", "110" },
	{ "P", "111" },
};

int main()
{
	string code;

	while( getline( cin, code ) ){
		string bits;
		int length = code.size();
		for( int i = 0; i < length; ++i ){
			char c = code[ i ];
			if( c >= 'A' && c <='Z' ){
				c -= 'A';
			}else{
				switch( c ){
					case ' ': c = 0x1A; break;
					case '.': c = 0x1B; break;
					case ',': c = 0x1C; break;
					case '-': c = 0x1D; break;
					case '\'': c = 0x1E; break;
					case '?': c = 0x1F; break;
				}
			}
			c <<= 3;
			for( int i = 0; i < 5; ++i ){
				if( c & 0x80 ){
					bits += '1';
				}else{
					bits += '0';
				}
				c <<= 1;
			}
		}
		length = bits.size();
		int index = 0;
		string decrypt;
		bool found = true;
		while( found ){
			found = false;
			for( int i = 0; i < 32; ++i ){
				int l = strlen( key[ i ][ 1 ] );
				if( bits.find( key[ i ][ 1 ], index, l ) != index ){
					continue;
				}
				decrypt += key[ i ][ 0 ];
				index += l;
				found = true;
				break;
			}
		}
		cout << decrypt << endl;
	}

	return 0;
}