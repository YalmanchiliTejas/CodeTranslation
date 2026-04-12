#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char const* argv[])
{
	int m,n;
	const string Fizz("Fizz"),Buzz("Buzz"),FizzBuzz("FizzBuzz");
	string str;
	vector<int> player;
	vector<int>::iterator it;

	while( cin >> m >> n && m ){
		getchar();
		player.clear();
		for( int i = 1;i <= m;i++ ) player.push_back( i );

		it = player.begin();
		for( int i = 1;i <= n;i++ ){
			if( it == player.end() ) it = player.begin();
			getline( cin, str );
			if( player.size() == 1 ) continue;
			
			if( !(i % 15) ){ if( FizzBuzz != str ){ it = player.erase( it ); continue;}}
			else if( !(i % 3) ){ if( Fizz != str ){ it = player.erase( it ); continue;}}
			else if( !(i % 5) ){ if( Buzz != str ){ it = player.erase( it ); continue;}}
			else{
				int j;
				for( j = 0;j < str.size();j++ ){
					if( str[j] > '9' || str[j] < '0' ){
						break;
					}
				}
				if( j == str.size() ){ if( atoi( str.c_str() ) != i ){ it = player.erase( it ); continue;}}
				else {it = player.erase( it ); continue;}
			}
			it++;
		}

		for( int i = 0;i < player.size();i++ ){
			cout << (( i == 0 ) ? "" : " ") << player[i];
		}
		cout << endl;
	}
	return 0;
}