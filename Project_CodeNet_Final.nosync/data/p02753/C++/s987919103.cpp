#include <iostream>
#include <string>
using namespace std;

int main ( void )
{
	string sta;
	cin >> sta;

	if ( ( sta == "AAA" ) || ( sta == "BBB" ) ){
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
	return 0;
}