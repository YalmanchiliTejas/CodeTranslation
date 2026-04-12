#include <iostream>
#include <vector>
using namespace std;
int main( void )
{
	while ( 1 )
	{
		int max_no = -1;
		int max_value = 0;
		for ( int i = 0; i < 5; i++ )
		{
			int a, b;
			cin >> a >> b;
			if ( a == 0 && b == 0 )
				break;
			if ( a+b > max_value )
			{
				max_no = i;
				max_value = a+b;
			}
		}
		if ( max_no == -1 )
			break;
		cout << (char)('A'+max_no) << " " << max_value << endl;
	}
}