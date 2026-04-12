#include <iostream>

using namespace std;

int calc_simple_interest ( int money, int year, double rate, int fee )
{
	int sum = 0;
	for ( int i = 0; i < year; ++i ) {
		sum += money * rate;
		money -= fee;
	}
	return money + sum;
}

int calc_compound_interest ( int money, int year, double rate, int fee )
{
	for ( int i = 0; i < year; ++i ) {
		money += money * rate;
		money -= fee;
	}
	return money;
}

int main ( void )
{
	int data_num;
	cin >> data_num;

	while ( data_num-- ) {
		int money, year, n;
		cin >> money
			>> year
			>> n;

		int max_money = 0;
		for ( int i = 0; i < n; ++i ) {
			int type, fee, temp;
			double rate;

			cin >> type >> rate >> fee;

			if ( type == 0 ) {
				temp = calc_simple_interest( money, year, rate, fee );
			}
			else {
				temp = calc_compound_interest( money, year, rate, fee );
			}
			max_money = max( max_money, temp );
		}

		cout << max_money << endl;
	}
	return 0;
}