#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

typedef std::string String;
typedef std::map< String, char > scnd;

int conv[256];
String str, tstr;
scnd data;

String setWidth( String str, int w ){
	std::stringstream ss;
	ss.width(5);
	ss.fill('0');
	ss << str;
	return ss.str();
}

String two_convert( int i ){
	String result;
	while( i != 0 ){
		if( i & 1 ) result += '1';
		else result += '0';
		i >>= 1;
	}

	std::reverse( result.begin(), result.end() );

	return result;
}

int two_re_convert( String str ){
	int a = 1;
	int result;
	for( int i = str.size() - 1; i >= 0; --i ){
		if( str[i] == '1' )result += a;
		a <<= 1;
	}

	return result;
}

int main(){
	conv[' '] = 0;
	conv['.'] = 1;
	conv[','] = 2;
	conv['-'] = 3;
	conv['\''] = 4;
	conv['?'] = 5;

	data["101"] = ' ';
	data["000000"] = '\'';
	data["000011"] = ',';
	data["10010001"] = '-';
	data["010001"] = '.';
	data["000001"] = '?';
	data["100101"] = 'A';
	data["10011010"] = 'B';
	data["0101"] = 'C';
	data["0001"] = 'D';
	data["110"] = 'E';
	data["01001"] = 'F';
	data["10011011"] = 'G';
	data["010000"] = 'H';
	data["0111"] = 'I';
	data["10011000"] = 'J';
	data["0110"] = 'K';
	data["00100"] = 'L';
	data["10011001"] = 'M';
	data["10011110"] = 'N';
	data["00101"] = 'O';
	data["111"] = 'P';
	data["10011111"] = 'Q';
	data["1000"] = 'R';
	data["00110"] = 'S';
	data["00111"] = 'T';
	data["10011100"] = 'U';
	data["10011101"] = 'V';
	data["000010"] = 'W';
	data["10010010"] = 'X';
	data["10010011"] = 'Y';
	data["10010000"] = 'Z';

	while(std::getline(std::cin, str)){

	for( int i = 0; i < str.size(); ++i ){
		if( str[i] >= 'A' && str[i] <= 'Z' ){
				tstr += setWidth(two_convert( str[i] - 'A' ), 5);
			}else{
				tstr += setWidth(two_convert( 26 + conv[str[i]] ), 5);
			}
		}

		String buf;
		for( int  i = 0; i < tstr.size(); ++i ){
			if( data[buf] != NULL ){
				std::cout << data[buf];
				buf = "";
			}
			buf += tstr[i];
		}

		if( data[buf] != NULL ){
			std::cout << data[buf];
			buf = "";	
		}

		std::cout << std::endl;

		str = "", buf = "", tstr = "";
	}
	return 0;
}