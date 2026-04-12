#include <iostream>
using namespace std;
const int maxn = 30;

int number , n , max_number , cnt;

int main ( void )
{
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> number;
		if ( number >= max_number ) {
			cnt++;
			max_number = number;
		}
	}	
	cout << cnt << endl;
	return 0;
}