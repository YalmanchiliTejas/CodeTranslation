#include <iostream>
#include <string>

#define IDX(c) ( c - 'a' )

using namespace std;

int main ( void )
{
	bool key[26] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 };

	string str;
	while ( cin >> str, str != "#" ) {
		int cnt = 0,
			prev = key[IDX( str[0] )];

		for ( int i = 0; i < str.size(); ++i ) {
			cnt += prev != key[IDX( str[i] )];
			prev = key[IDX( str[i] )];
		}

		cout << cnt << endl;
	}
	return 0;
}