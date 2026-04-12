#include <iostream>
#include <string>
using namespace std;

string N;
int k;
int sum_1 , sum_2;
int cnt = 0 , f_number , s_number , f_loc;

int main ( void )
{
	cin >> N;
	cin >> k;
	if ( k == 1 ) {
		cout << ( N.size ( ) - 1 ) * 9 + N [ 0 ] - 48 << endl;
	} else if ( k == 2 ) {
		if ( N.size ( ) == 1 ) {
			cout << 0 << endl;
			return 0;
		}
		sum_1 += 81 * ( N.size ( ) - 2 ) * ( N.size ( ) - 1 ) / 2;
		sum_1 += ( N.size ( ) - 1 ) * 9 * ( N [ 0 ] - 48 - 1 );
		for ( int i = 1 ; i < N.size ( ) ; i++ ) {
			if ( N [ i ] != '0' ) {
				sum_1 += ( N.size ( ) - i - 1 ) * 9;
				sum_1 += N [ i ] - 48;
				break;
			}
		}
		cout << sum_1 << endl;
	} else {
		if ( N.size ( ) <= 2 ) {
			cout << 0 << endl;
			return 0;
		}
		sum_2 += 81 * ( N [ 0 ] - 48 - 1 ) * ( N.size ( ) - 1 ) * ( N.size ( ) - 2 ) / 2;
		for ( int i = 2 ; i <= N.size ( ) - 2  ; i++ ) {
			sum_2 += 729 * i * ( i - 1 ) / 2;
		}
		for ( int i = 1 ; i < N.size ( ) ; i++ ) {
			if ( N [ i ] != '0' && cnt == 0 ) {
				f_number = N [ i ] - 48;
				sum_2 += ( f_number - 1 ) * ( N.size ( ) - i - 1 ) * 9;
				f_loc = i;
				cnt++;
			} else if ( N [ i ] != '0' && cnt == 1 ) {
				s_number = N [ i ] - 48;
				sum_2 += ( N.size ( ) - i - 1 ) * 9 + s_number;
				break;
			}
		}
		/*
		if ( s_number == 0 && f_number != 0 ) {
			if ( f_loc == N.size ( ) - 2 ) {
				sum_2 += ( N.size ( ) - f_loc - 1 ) * 9 * ( f_number - 1 );
			} else {
				sum_2 += ( N.size ( ) - f_loc - 1 ) * 9 * f_number;
			}
		}*/
		if ( f_number != 0 ) {
			sum_2 += 81 * ( N.size ( ) - 1 - f_loc ) * ( N.size ( ) - 2 - f_loc ) / 2;
		}
		cout << sum_2 << endl;
	}
	return 0;
}