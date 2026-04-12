#include <iostream>
#include <string>
#include <map>
using namespace std;

map< char, string > toBits;
map< string, char > toChar;

#define INSB( k, s ) (toBits.insert( map<char, string>::value_type(k, s)))
#define INSC( k, s ) (toChar.insert( map<string, char>::value_type(k, s))) 

string ToBits( char ch ) {
	string res = "", tmp = "";
	int num = ch - 'A';

	for( int i = 0; i < 5; ++i ) {
		tmp += (char)((num % 2) + '0' );
		num /= 2;
	}

	for( int i = 4; i >= 0; --i ) {
		res += tmp[ i ];
	}

	return res;
}

void Init() {
	// toBitsの初期化
	INSB( ' ', "11010" ); INSB( '.', "11011" ); INSB( ',', "11100" );
	INSB( '-', "11101" ); INSB( '\'', "11110" ); INSB( '?', "11111" );
	for( char c = 'A'; c <= 'Z'; ++c ) {
		INSB( c, ToBits( c ) );
	}

	// toCharの初期化
	INSC( "101", ' ' );      INSC( "000000", '\'' );  INSC( "000011", ',' );
	INSC( "10010001", '-' ); INSC( "010001", '.' );   INSC( "000001", '?' );
	INSC( "100101", 'A' );   INSC( "10011010", 'B' ); INSC( "0101", 'C' );
	INSC( "0001", 'D' );     INSC( "110", 'E' );      INSC( "01001", 'F' );
	INSC( "10011011", 'G' ); INSC( "010000", 'H' );   INSC( "0111", 'I' );
	INSC( "10011000", 'J' ); INSC( "0110", 'K' );     INSC( "00100", 'L' );
	INSC( "10011001", 'M' ); INSC( "10011110", 'N' ); INSC( "00101", 'O' );
	INSC( "111", 'P' );      INSC( "10011111", 'Q' ); INSC( "1000", 'R' );
	INSC( "00110", 'S' );    INSC( "00111", 'T' );    INSC( "10011100", 'U' );
	INSC( "10011101", 'V' ); INSC( "000010", 'W' );   INSC( "10010010", 'X' );
	INSC( "10010011", 'Y' ); INSC( "10010000", 'Z' );
}

int main() {
	Init();

	string in;
	while( getline( cin, in ) ) {
		string bits = "";
		string tmp = "";

		for( int i = 0; i < in.length(); ++i ) {
			bits += toBits[ in[ i ] ];
		}

		for( int i = 0; i < bits.length(); ++i ) {
			tmp += bits[ i ];
			if( toChar.find( tmp ) != toChar.end() ) {
				cout << toChar[ tmp ];
				tmp = "";
			}
		}
		cout << endl;
	}
	return 0;
}