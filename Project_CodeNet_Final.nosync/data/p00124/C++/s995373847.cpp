#include <math.h>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){

	bool f = false;
	while(true) {

		int n;
		cin >> n;
		if ( n == 0 ) break;
		if ( f ) cout << endl;

		vector<string> country;
		vector<int> score;
		string input1;
		int input2,input3,input4;
		vector<bool> flag;

		for ( int i = 0; i < n; i++ ) {

			int cnt = 0;
			cin >> input1 >> input2 >> input3 >> input4;
			country.push_back(input1);
			cnt += ( input2*3 + input4 ) * 10 + ( 9 - i );
			score.push_back(cnt);
			flag.push_back(true);

		}

		sort( score.begin(), score.end() );
		for ( int i = n-1; i >= 0; i-- ) {
			cout << country[ 9 - score[i]%10 ] << "," << score[i]/10 << endl;
		}
		f = true;
	}
	return 0;
}