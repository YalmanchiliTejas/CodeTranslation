#include <iostream>
#include <string>
using namespace std;

int main( void ){
	int32_t x;
	cin >> x;
	cout << ( x != 1 && ( x <= 7 ) && ( 105 % x == 0 ) ? "YES" : "NO" ) << endl;
}