#include <iostream>
#include <string>
#define LEN (17 / 2 + 1)

const char* out = "ILMU";

int mf( std::string str ){
	int sum = 0, pt = 0;
	int n[ LEN + 1 ];

	std::fill( n, n + LEN + 1, 1 );

	for( int i = 0; i < str.size(); i++ ){
		if( i & 1 ){
			if( str[i] == '+' ){
				pt++;
			}
		}else{
			n[pt] *= (str[i] - '0');
		}
	}

	for( int i = 0; i <= pt; ++i ) sum += n[i];	

	return sum;
}

int lr( std::string str ){
	int sum = str[0] - '0' ;

	for( int i = 1; i < str.size(); i += 2 ){
		if(str[i] == '+'){
			sum += str[i+1] - '0';
		}else{
			sum *= str[i+1] - '0';
		}
	}

	return  sum;
}

int main(){
	std::string str;
	int res;
	bool equal[2];

	std::cin >> str >> res;

	equal[0] = (mf( str ) == res);
	equal[1] = (lr( str ) == res);

	std::cout << out[ ((int)equal[0] << 1) + equal[1] ] << std::endl;

	return 0;
}