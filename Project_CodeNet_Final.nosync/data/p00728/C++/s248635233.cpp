#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	int sum, max, min;
	
	while( 1 ){
		sum = 0; max = 0; min = 1000;
		cin >> n;
		vector<int> score(n);
		if( n == 0 ) break;
		for( int i = 0; i < n; i++ ){
			cin >> score[i];
			sum += score[i];
			if( max < score[i] ) max = score[i];
			if( min > score[i] ) min = score[i];
		}
		sum -= max + min;
		cout << sum/(n-2) << endl;
		score.clear();
	}
}