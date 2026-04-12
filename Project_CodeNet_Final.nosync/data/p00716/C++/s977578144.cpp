#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int first, year, n;
	for( cin >> n; cin >> first >> year >> n; ){
		int ans = 0;
		for( int i = 0; i < n; ++i ){
			int compound, fee;
			double interest;
			int sum = 0;
			
			cin >> compound >> interest >> fee;
			if( compound ){
				sum = first;
				for( int j = 0; j < year; ++j ){
					sum += int( sum * interest ) - fee;
				}
			}
			else{
				int p = first;
				for( int j = 0; j < year; ++j ){
					sum += int( p * interest );
					p -= fee;
				}
				sum += p;
			}
			
			ans = max( ans, sum );
		}
		
		cout << ans << endl;
	}
}