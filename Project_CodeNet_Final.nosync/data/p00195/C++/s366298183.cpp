#include <iostream>
#include <string>
using namespace std;

int main()
{
	int s1, s2;
	while( cin >> s1 >> s2 && ( s1 || s2 ) ){
		int topSeller = 0;
		int topSales = ( s1 + s2 );
		for( int i = 1; i < 5; ++i ){
			cin >> s1 >> s2;
			if( topSales < s1 + s2 ){
				topSeller = i;
				topSales = s1 + s2;
			}
		}
		cout << (char)( topSeller + 'A' ) << " " << topSales << endl;
	}
	return 0;
}