#include <iostream>
#include <string>
#include <utility>

struct dice{
	char right, front, top;

	dice( char r, char f, char t ){
		right = r, front = f, top = t;
	}

	void Roll( bool b ){
		std::swap( right, front );
		if( b ) right = 7 - right;
		else front = 7 - front;
	}

	void North(){
		std::swap( top, front );
		front = 7 - front;
	}

	void South(){
		std::swap( top, front );
		top = 7 - top;
	}

	void East(){
		std::swap( top, right );
		top = 7 - top;
	}

	void West(){
		std::swap( top, right );
		right = 7 - right;
	}

};


int main(){
	int n;
	while( std::cin >> n, n ){
		int sum = 1;
		dice d = dice( 3, 2, 1 );

		while( n-- ){
			std::string str;
			std::cin >> str;
			switch( str[0] ){
			case 'R':
				d.Roll(1);
				break;
			case 'L':
				d.Roll(0);
				break;
			case 'N':
				d.North();
				break;
			case 'S':
				d.South();
				break;
			case 'E':
				d.East();
				break;
			case 'W':
				d.West();
				break;
			}
			sum += d.top;
		}
		std::cout << sum << std::endl;
	}
	return 0;
}