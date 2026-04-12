#include <iostream>
#include <string>
using namespace std;

int main()
{

	int	   n, temp, sum;
	int	   top, front, back, left, right, under;
	string order;

	while( 1 ) {

		top   = 1;
		front = 2;
		back  = 5;
		left  = 4;
		right = 3;
		under = 6;
		sum   = 1;
	
		cin >> n;
		if( n == 0 ) break;

		for( int i = 0; i < n; i++ ) {
		
			cin >> order;

			if( order == "North" ) {
			
				temp  = top;
				top   = front;
				front = under;
				under = back;
				back  = temp;

			}
			else if( order == "South" ) {
			
				temp  = top;
				top   = back;
				back  = under;
				under = front;
				front = temp;
			
			}
			else if( order == "West" ) {
			
				temp  = top;
				top   = right;
				right = under;
				under = left;
				left  = temp;
			
			}
			else if( order == "East" ) {
			
				temp  = top;
				top   = left;
				left  = under;
				under = right;
				right = temp;
			
			}
			else if( order == "Right" ) {
			
				temp  = front;
				front = right;
				right = back;
				back  = left;
				left  = temp;
			
			}
			else if( order == "Left" ) {
			
				temp  = front;
				front = left;
				left  = back;
				back  = right;
				right = temp;

			}

			sum += top;
		
		}

		cout << sum << endl;
	
	}

	return 0;

}